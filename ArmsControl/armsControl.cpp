//
//
//  Created by Semih Onay on 6.03.2015.
//
//
#include <stdio.h>
#include <yarp/os/Network.h>
#include <yarp/dev/ControlBoardInterfaces.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/os/Time.h>
#include <yarp/sig/Vector.h>

#include <string>

using namespace yarp::dev;
using namespace yarp::sig;
using namespace yarp::os;

int main(int argc, char *argv[]) {
    //Initialization
    Network yarp;
    Property params;
    params.fromCommand(argc, argv);

    if (!params.check("robot")) {
        fprintf(stderr, "--robot name (icubSim to see on simulation env.)\n");
        return -1;
    }
    //get robot paramaters,  robot name "icubSim" and arm to use
    std::string robotName = params.find("robot").asString().c_str();
    std::string remotePorts = "/";
    remotePorts += robotName;
    remotePorts += "/right_arm";

    std::string localPorts = "/test/client";

    //initialize icub drivers
    Property options;
    options.put("device", "remote_controlboard");       //device init.
    options.put("local", localPorts.c_str());           //local port names
    options.put("remote", remotePorts.c_str());         //where we connect to

    // create a device
    PolyDriver robotDevice(options);
    if (!robotDevice.isValid()) {
        printf("Device not available.  Here are the known devices:\n");
        printf("%s", Drivers::factory().toString().c_str());
        return 0;
    }

    IPositionControl *pos;
    IEncoders *encs;

    bool ok;
    ok = robotDevice.view(pos);
    ok = ok && robotDevice.view(encs);

    if (!ok) {
        printf("Problems acquiring interfaces\n");
        return 0;
    }

    int nj = 0;
    pos->getAxes(&nj);
    Vector encoders;
    Vector command;
    Vector tmp;
    encoders.resize(nj);
    tmp.resize(nj);
    command.resize(nj);

    int i;
    for (i = 0; i < nj; i++) {
        tmp[i] = 50.0;
    }
    pos->setRefAccelerations(tmp.data());

    for (i = 0; i < nj; i++) {
        tmp[i] = 10.0;
        pos->setRefSpeed(i, tmp[i]);
    }

    //fisrst read all encoders
    printf("waiting for encoders");
    while (!encs->getEncoders(encoders.data())) {
        Time::delay(0.1);
        printf(".");
    }
    printf("\n;");

    command = encoders;

    //Shoulder Part
    command[0] = -50;
    command[1] = 20;
    command[2] = -10;
    command[3] = 50;
    pos->positionMove(command.data());

    bool done = false;

    //checking for action
    while (!done) {
        pos->checkMotionDone(&done);
        Time::delay(0.1);
    }

    int times = 0;
    while (true) {
        times++;
        if (times % 2) {
            command[0] = -50;
            command[1] = 20;
            command[2] = -10;
            command[3] = 50;
        }
        else {
            command[0] = -20;
            command[1] = 40;
            command[2] = -10;
            command[3] = 30;
        }

        pos->positionMove(command.data());

        int count = 50;
        while (count--) {
            Time::delay(0.1);
            bool ret = encs->getEncoders(encoders.data());

            if (!ret) {
                fprintf(stderr, "Error receiving encoders, check ports\n");
            }
            else {
                printf("%.1lf %.1lf %.1lf %.1lf\n", encoders[0], encoders[1], encoders[2], encoders[3]);
            }
        }
    }

    robotDevice.close();

    return 0;
}
