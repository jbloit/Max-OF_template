//
//  oscManager.h
//  scene_projections
//
//  Created by Julien Bloit on 21/08/14.
//
//

#ifndef __scene_projections__oscManager__
#define __scene_projections__oscManager__

// OSC ports
#define OSC_RECEIVE_PORT 12345
#define OSC_SEND_PORT 54321
#define OSC_NUM_MSG_STRINGS 20
#define HOST "localhost"

#include <iostream>
#include "ofxOsc.h"

// Singleton class. See tutorial here http://www.yolinux.com/TUTORIALS/C++Singleton.html

class oscManager{
public:
    
    static oscManager* Instance();
    void setup();
    void update();

    // ----------- Events to dispatch to registered clients
    
    // Define events to receive from the OSC sender (Max/MSP for instance)
    ofEvent<int> maxEventToggle;
    ofEvent<float> maxEventFloat_1;
    ofEvent<float> maxEventFloat_2;
    
    // allow client objects to call the sender directly
    ofxOscSender sender;
    
private:
    oscManager();
    oscManager(oscManager const&){};            // copy constructor is private
    oscManager& operator=(oscManager const&){}; // assignment operator is private
    static oscManager* m_pInstance;             // the unique instance
    
    ofxOscReceiver receiver;
    int current_msg_string;
    string msg_strings[OSC_NUM_MSG_STRINGS];
    float timers[OSC_NUM_MSG_STRINGS];
    
    
    
};

#endif /* defined(__scene_projections__oscManager__) */
