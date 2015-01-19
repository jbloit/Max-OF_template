//
//  oscManager.cpp
//  scene_projections
//
//  Created by Julien Bloit on 21/08/14.
//
//

#include "oscManager.h"

oscManager* oscManager::m_pInstance = NULL;

oscManager* oscManager::Instance(){
    if (!m_pInstance)  // Only allow one instance of class to be generated.
        m_pInstance = new oscManager;
    return m_pInstance;
}

// --------------------------------------------------------------------------
oscManager::oscManager(){}

// --------------------------------------------------------------------------
void oscManager::setup(){
    // listen on the given port
    cout << "listening for osc messages on port " << OSC_RECEIVE_PORT << "\n";
    receiver.setup(OSC_RECEIVE_PORT);
    
    // open an outgoing connection to HOST:PORT
	sender.setup(HOST, OSC_SEND_PORT);
}

// --------------------------------------------------------------------------
void oscManager::update(){
    // hide old messages
    for(int i = 0; i < OSC_NUM_MSG_STRINGS; i++){
        if(timers[i] < ofGetElapsedTimef()){
            msg_strings[i] = "";
        }
    }
    
    // check for waiting messages
    while(receiver.hasWaitingMessages()){
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        // Check for events from the OSC source
        if(m.getAddress() == "/toggle"){
            int value = m.getArgAsInt32(0);
            ofNotifyEvent(maxEventToggle, value, this);
        }
        if(m.getAddress() == "/slider_1"){
            float value = m.getArgAsFloat(0);
            cout << "osc slider 1 " << value << "\n";
            ofNotifyEvent(maxEventFloat_1, value , this);
        }
        if(m.getAddress() == "/slider_2"){
            float value = m.getArgAsFloat(0);
            cout << "osc slider 2 " << value << "\n";
            ofNotifyEvent(maxEventFloat_2, value , this);
        }

    }
    
}