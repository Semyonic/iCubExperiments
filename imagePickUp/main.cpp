//
//
//  Created by Semih Onay on 27.04.2015.
//
//
#include <stdio.h>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::dev;
int main() {

  //set YARP
  Network yarp;
  BufferedPort<Vector> targetPort;
  targetPort.open("/tutorial/target/in");
  Network::connect("/tutorial/target/out","/tutorial/target/in");
  Property options;
  //initialize drivers
  options.put("device", "remote_controlboard");
  options.put("local", "/tutorial/motor/client");
  options.put("remote", "/icubSim/head");
  PolyDriver robotHead(options);
  //check robotHead for camera init.
  if (!robotHead.isValid()) {
    printf("Cannot connect to robot head\n");
    return 1;
  }
  IPositionControl *pos;
  IVelocityControl *vel;
  IEncoders *enc;
  robotHead.view(pos);//position vector
  robotHead.view(vel);//velocity vector
  robotHead.view(enc);//encoders
  if (pos==NULL || vel==NULL || enc==NULL) {
    printf("Cannot get interface to robot head\n");
    robotHead.close();
    return 1;
  }
  int jnts = 0;
  pos->getAxes(&jnts);
  Vector setpoints;
  setpoints.resize(jnts);
  while (1) { // repeat forever
    Vector *target = targetPort.read();  // read a target
    if (target!=NULL) { // check for incoming data
       printf("We got a vector containing");
       for (int i=0; i<target->size(); i++) {
         printf(" %g", (*target)[i]);
       }
       printf("\n");
       double x = (*target)[0];
       double y = (*target)[1];
       double conf = (*target)[2];
       x -= 320/2;
       y -= 240/2;
       double vx = x*0.1;
       double vy = -y*0.1;
       /* prepare command */
       for (int i=0; i<jnts; i++) {
         setpoints[i] = 0;
       }
       if (conf>0.5) {
         setpoints[3] = vy;
         setpoints[4] = vx;
       } else {
         setpoints[3] = 0;
         setpoints[4] = 0;
       }
       vel->velocityMove(setpoints.data());
    }
  }
  return 0;
}
