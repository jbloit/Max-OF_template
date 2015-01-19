//
//  wheeler.h
//  shissss
//
//  Created by julien@macmini on 10/15/14.
//
//

#ifndef __shissss__wheeler__
#define __shissss__wheeler__

#include <iostream>
#include "_projectGlobals.h"
#include "globals.h"
#include "oscManager.h"
#include "dot.h"

class scene{
    
public:
    void setup();
    void update();
    void draw();
    void listen();
    void terminate();
    
    // OSC events callbacks
    void onMaxToggle(int& value);
    void onMaxFloat_1(float& value);
    void onMaxFloat_2(float& value);
    
    // keyboard callbacks
    void keyPressed(ofKeyEventArgs& args);
    void keyReleased(ofKeyEventArgs& args);
    
private:
    // utils
    oscManager * osc; // pointer to osc the singleton class
    
    // Scene methods
    
    // scene elements
    dot aDot;
    
    // scene behavior
    void addGrain(int grainId);
    
};

#endif /* defined(__shissss__wheeler__) */
