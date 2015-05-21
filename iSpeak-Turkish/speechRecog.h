//
//  speechRecog.h
//  iSpeakTest
//
//  Created by Semih Onay on 6.03.2015.
//
//

#ifndef iSpeakTest_Header_h
#define iSpeakTest_Header_h


#endif

class SpeechRecognizerModule: public RFModule
{
    //Yarp related
    Port m_portRPC;
    Port m_portContinuousRecognition;
    Port m_portContinuousRecognitionGrammar;
    Port m_port2iSpeak;
    Port m_port2iSpeakRpc;
    BufferedPort<Sound> m_portSound;
    
    
public:
    
    /************************************************************************/
    bool configure(ResourceFinder &rf);
    
    /************************************************************************/
    bool updateModule();
    
    /************************************************************************/
    bool handleRGMCmd(const Bottle& cmd, Bottle& reply);
    
    /************************************************************************/
    bool handleAsyncRecognitionCmd(const Bottle& cmd, Bottle& reply);
    
    /************************************************************************/
    bool refreshFromVocabulories(CComPtr<ISpRecoGrammar> grammarToModify);
    
    /************************************************************************/
    bool handleVocabuloryCmd(const Bottle& cmd, Bottle& reply);
    
    /************************************************************************/
    bool handleRecognitionCmd(const Bottle& cmd, Bottle& reply);
    
    /************************************************************************/
    bool setGrammarCustom(CComPtr<ISpRecoGrammar> grammarToModify, string grammar, bool append);
    
    /************************************************************************/
    string getFromDictaction(int timeout, LPCWSTR options=NULL);
    
    /************************************************************************/
    list< pair<string, double> > waitNextRecognitionLEGACY(int timeout);
    
    /************************************************************************/
    Bottle waitNextRecognition(int timeout);
    
    /************************************************************************/
    void say(string s, bool wait=true);
    
    /************************************************************************/
    Bottle toBottle(SPPHRASE* pPhrase, const SPPHRASERULE* pRule );
    
    /************************************************************************/
    bool respond(const Bottle& cmd, Bottle& reply);
    
    /************************************************************************/
    bool interruptModule()
    {
        std::cout<<"Interrupting ports...";
        m_portRPC.interrupt();
        m_portContinuousRecognition.interrupt();
        m_portContinuousRecognitionGrammar.interrupt();
        m_port2iSpeak.interrupt();
        m_port2iSpeakRpc.interrupt();
        m_portSound.interrupt();
        std::cout<<"ok"<<std::endl;
        return true;
    }
    
    /************************************************************************/
    bool close()
    {
        std::cout<<"Closing ports...";
        m_portRPC.close();
        m_portContinuousRecognition.close();
        m_portContinuousRecognitionGrammar.close();
        m_port2iSpeak.close();
        m_port2iSpeakRpc.close();
        m_portSound.close();
        std::cout<<"ok"<<std::endl;
        return true;
    }
    
    /************************************************************************/
    double getPeriod()
    {
        return 0.1;
    }
    
    /************************************************************************/
    bool loadGrammarFromRf(ResourceFinder &RF);
    
    /************************************************************************/
    yarp::sig::Sound toSound(CComPtr<ISpRecoResult> cpRecoResult);
}