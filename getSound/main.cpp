//
//
//  Created by Semih Onay on 12.04.2015.
//
//
#include <yarp/dev/AudioGrabberInterfaces.h>
#include <yarp/sig/Sound.h>

//device driver
polyDriver              dev("portaudio");
IAudioGrabberSound	*grabber;
dev.view(grabber);
Sound sound;

//template
if (grabber!=NULL)
{
...
    if (grabber->getSound(sound))
    {...}
}
