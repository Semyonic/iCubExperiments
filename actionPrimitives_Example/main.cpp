//
//
//  Created by Semih Onay on 20.04.2015.
//
//

/* options used to open a ActionPrimitives object
 robot                           icubSim //simulation
 thread_period                   50 // thread timer
 default_exec_time               3.0 
 reach_tol                       0.007
 verbosity                       on
 torso_pitch                     on
 torso_roll                      off
 torso_yaw                       on
 torso_pitch_max                 30.0
 tracking_mode                   on
 verbosity                       on

//pre-defined paramaters for arm orientation
 [arm_dependent]
 grasp_orientation               (-0.171542 0.124396 -0.977292 3.058211)
 grasp_displacement              (0.0 0.0 0.05)
 systematic_error_displacement   (-0.03 -0.07 -0.02)
 lifting_displacement            (0.0 0.0 0.2)
 home_position                   (-0.29 -0.21 0.11)
 home_orientation                (-0.029976 0.763076 -0.645613 2.884471)
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <deque>

#include <yarp/os/Network.h>
#include <yarp/os/RFModule.h>
#include <yarp/os/Bottle.h>
#include <yarp/os/BufferedPort.h>
#include <yarp/sig/Vector.h>
#include <yarp/math/Math.h>
#include <yarp/dev/Drivers.h>
#include <iCub/perception/models.h>
#include <iCub/action/actionPrimitives.h>

#define USE_LEFT    0
#define USE_RIGHT   1

#define AFFACTIONPRIMITIVESLAYER    ActionPrimitivesLayer1

YARP_DECLARE_DEVICES(icubmod)

using namespace std;
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::dev;
using namespace yarp::math;
using namespace iCub::perception;
using namespace iCub::action;


class ExampleModule : public RFModule
{
protected:
    AFFACTIONPRIMITIVESLAYER *action;
    BufferedPort <Bottle> inPort;
    Port rpcPort;

    Vector graspOrien;
    Vector graspDisp;
    Vector dOffs;
    Vector dLift;
    Vector home_x;

    bool firstRun;

public:
    ExampleModule() {
        graspOrien.resize(4);
        graspDisp.resize(3);
        dOffs.resize(3);
        dLift.resize(3);
        home_x.resize(3);

        //Default Values of Arms
        graspOrien[0] = -0.171542;
        graspOrien[1] = 0.124396;
        graspOrien[2] = -0.977292;
        graspOrien[3] = 3.058211;

        graspDisp[0] = 0.0;
        graspDisp[1] = 0.0;
        graspDisp[2] = 0.05;

        dOffs[0] = -0.03;
        dOffs[1] = -0.07;
        dOffs[2] = -0.02;

        dLift[0] = 0.0;
        dLift[1] = 0.0;
        dLift[2] = 0.15;

        home_x[0] = -0.29;
        home_x[1] = -0.21;
        home_x[2] = 0.11;

        action = NULL;
        firstRun = true;
    }

//grasp orientation function.
    void getArmDependentOptions(Bottle &b, Vector &_gOrien, Vector &_gDisp,
                                Vector &_dOffs, Vector &_dLift, Vector &_home_x) {
        if (Bottle *pB = b.find("grasp_orientation").asList()) {
            int sz = pB->size();
            int len = _gOrien.length();
            int l = len < sz ? len : sz;

            for (int i = 0; i < l; i++)
                _gOrien[i] = pB->get(i).asDouble();
        }

        if (Bottle *pB = b.find("grasp_displacement").asList()) {
            int sz = pB->size();
            int len = _gDisp.length();
            int l = len < sz ? len : sz;

            for (int i = 0; i < l; i++)
                _gDisp[i] = pB->get(i).asDouble();
        }

        if (Bottle *pB = b.find("systematic_error_displacement").asList()) {
            int sz = pB->size();
            int len = _dOffs.length();
            int l = len < sz ? len : sz;

            for (int i = 0; i < l; i++)
                _dOffs[i] = pB->get(i).asDouble();
        }

        if (Bottle *pB = b.find("lifting_displacement").asList()) {
            int sz = pB->size();
            int len = _dLift.length();
            int l = len < sz ? len : sz;

            for (int i = 0; i < l; i++)
                _dLift[i] = pB->get(i).asDouble();
        }

        if (Bottle *pB = b.find("home_position").asList()) {
            int sz = pB->size();
            int len = _home_x.length();
            int l = len < sz ? len : sz;

            for (int i = 0; i < l; i++)
                _home_x[i] = pB->get(i).asDouble();
        }
    }

//Gathering resources for initialization
    bool configure(ResourceFinder &rf) {
        string name = rf.find("name").asString().c_str();
        setName(name.c_str());

        Property config; config.fromConfigFile(rf.findFile("from").c_str());
        Bottle &bGeneral = config.findGroup("general");
        if (bGeneral.isNull()) {
            cout << "Error: group general is missing!" << endl;
            return false;
        }

        // parsing general config options from config.ini file
        Property option(bGeneral.toString().c_str());
        option.put("local", name.c_str());
        option.put("part", "left_arm");
        option.put("grasp_model_type", rf.find("grasp_model_type").asString().c_str());
        option.put("grasp_model_file", rf.findFile("grasp_model_file").c_str());
        option.put("hand_sequences_file", rf.findFile("hand_sequences_file").c_str());

        // parsing arm dependent config options from config.ini file
        Bottle &bArm = config.findGroup("arm_dependent");
        getArmDependentOptions(bArm, graspOrien, graspDisp, dOffs, dLift, home_x);

        cout << "***** Instantiating primitives for left arm" << endl;
        action = new AFFACTIONPRIMITIVESLAYER(option);
        if (!action->isValid()) {
            delete action;
            return false;
        }

        //createing YARP ports and connections
        deque <string> q = action->getHandSeqList();
        cout << "***** List of available hand sequence keys:" << endl;
        for (size_t i = 0; i < q.size(); i++)
            cout << q[i] << endl;

        string fwslash = "/";
        inPort.open((fwslash + name + "/in").c_str());
        rpcPort.open((fwslash + name + "/rpc").c_str());
        attach(rpcPort);

        // check for graspCalibration
        Model *model; action->getGraspModel(model);
        if (model != NULL) {
            if (!model->isCalibrated()) {
                Property prop("(finger all_parallel)");
                model->calibrate(prop);

                string fileName = rf.getHomeContextPath();
                fileName += "/";
                fileName += option.find("grasp_model_file").asString().c_str();

                ofstream fout;
                fout.open(fileName.c_str());
                model->toStream(fout);
                fout.close();
            }
        }

        return true;
    }

    bool close() {
        if (action != NULL)
            delete action;

        inPort.close();
        rpcPort.close();

        return true;
    }

    double getPeriod() {
        return 0.1;
    }

    void init() {
        bool f;

        action->pushAction(home_x, "open_hand");
        action->checkActionsDone(f, true);
        action->enableArmWaving(home_x);
    }

    bool updateModule() {
        if (firstRun) {
            init();
            firstRun = false;
        }

        // get a target object position from a YARP port
        Bottle *b = inPort.read();

        if (b != NULL) {
            Vector xd(3);
            bool f;

            xd[0] = b->get(0).asDouble();
            xd[1] = b->get(1).asDouble();
            xd[2] = b->get(2).asDouble();

            // apply systematic offset
            // due to uncalibrated kinematic
            xd = xd + dOffs;

            // safe thresholding
            xd[0] = xd[0] > -0.1 ? -0.1 : xd[0];

            // grasp (wait until it's done)
            action->grasp(xd, graspOrien, graspDisp);
            action->checkActionsDone(f, true);
            action->areFingersInPosition(f);

            // if fingers are not in position,
            // it's likely that we've just grasped
            // something, so lift it up!
            if (!f) {
                cout << "Wow, got something!" << endl;

                // lift the object (wait until it's done)
                action->pushAction(xd + dLift, graspOrien);
                action->checkActionsDone(f, true);
            }
            else
                cout << "Sorry :( ... nothing to grasp" << endl;

            // release the object or just open the
            // hand (wait until it's done)
            action->pushAction("open_hand");
            action->checkActionsDone(f, true);

            // wait until it's done, since
            // use two arms that shares the torso
            action->pushAction(home_x);
            action->checkActionsDone(f, true);

            // let the hand wave a bit around home position
            // the waving will be disabled before commencing
            // a new action
            action->enableArmWaving(home_x);
        }

        return true;
    }

    bool interruptModule() {
        // since a call to checkActionsDone() blocks
        // the execution until it's done, we need to
        // take control and exit from the waiting state
        action->syncCheckInterrupt(true);

        inPort.interrupt();
        rpcPort.interrupt();

        return true;
    }
};


int main(int argc, char *argv[]) {
    Network yarp;
    if (!yarp.checkNetwork()) {
        cout << "YARP server not available!" << endl;
        return -1;
    }

// resource allocation
    YARP_REGISTER_DEVICES(icubmod)

    ResourceFinder rf;
    rf.setVerbose(true);
    rf.setDefaultContext("actionPrimitivesExample");
    rf.setDefaultConfigFile("config.ini");
    rf.setDefault("grasp_model_type", "tactile");
    rf.setDefault("grasp_model_file", "grasp_model.ini");
    rf.setDefault("hand_sequences_file", "hand_sequences.ini");
    rf.setDefault("name", "actionPrimitivesMod");
    rf.configure(argc, argv);

    ExampleModule mod;
    return mod.runModule(rf);
}
