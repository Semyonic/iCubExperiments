//
//
//  Created by Semih Onay on 6.03.2015.
//
//

#include <stdio.h>
#include <yarp/dev/PolyDriver.h>
#include <yarp/dev/AudioGrabberInterfaces.h>
#include <yarp/os/Network.h>
#include <yarp/os/Port.h>
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::dev;
int main(int argc, char *argv[]) {
    // Open the network
    Network yarp;
    BufferedPort<Sound> p;
    p.open("/receiver");
    Network::connect("/sender", "/receiver");
    // Get an audio write device.
    Property conf;
    conf.put("device","portaudio");
    conf.put("samples", "4096");
    conf.put("write", "1");
    PolyDriver poly(conf);
    IAudioRender *put;
    // Check it can write the sound
    poly.view(put);
    if (put==NULL) {
        printf("cannot open interface\n");
        return 1;
    }
    //Receive and render the sound
    Sound *s;
    while (true)
      {
    s = p.read(false);
    if (s!=NULL)
        put->renderSound(*s);
      }
    return 0;
}
