//
//  main2.cpp
//  iSpeakTest
//
//  Created by Semih Onay on 6.03.2015.
//
//

#include "speechRecog.h"

int main(int argc, char* argv[])
{
    double t0;
    if (::CoInitializeEx(NULL,COINIT_MULTITHREADED) == S_OK)
    {
        Network yarp;
        if (!yarp.checkNetwork())
            return -1;
        
        ResourceFinder rf;
        rf.setVerbose(true);
        rf.setDefaultContext("speechRecognizer");
        rf.setDefaultConfigFile("config.ini");
        rf.configure(argc,argv);
        SpeechRecognizerModule mod;
        
        mod.runModule(rf);
        t0 = Time::now();
        cout<<"Out of the runModule(). You may want to stop the microphone to get back the hand..."<<endl;
    }
    ::CoUninitialize();
    cout<<"Time to give back the hand : "<<Time::now()-t0<<endl;
}
