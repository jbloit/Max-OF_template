//
//  wheeler.cpp
//  shissss
//
//  Created by julien@macmini on 10/15/14.
//
//

#include "scene.h"

using namespace std;

void scene::setup(){
    
    osc = oscManager::Instance();
    
    // notify Max of scene start
    ofxOscMessage m;
    m.setAddress("/scene/on");
    m.addIntArg(1);
    osc->sender.sendMessage(m);
    
    // Register event listeners
    ofAddListener(osc->maxEventToggle, this, &scene::onMaxToggle);
    ofAddListener(osc->maxEventFloat_1, this, &scene::onMaxFloat_1);
    ofAddListener(osc->maxEventFloat_2, this, &scene::onMaxFloat_2);

    ofRegisterKeyEvents(this);

    // init vector capacity to avoid dynamic resizes
//    elements.reserve(maxNumberOfElements);
    
    // init elements
    aDot.setup(ofGetWidth()/2, ofGetHeight()/2, 50);
}

// ------------------------------------------------------
// End scene and deallocate objects if needed. This is not a destructor, we want to
// be able to call it even when the object is not destroyed.
void scene::terminate(){
    
    ofUnregisterKeyEvents(this);
    ofRemoveListener(osc->maxEventToggle, this, &scene::onMaxToggle);
    ofRemoveListener(osc->maxEventFloat_1, this, &scene::onMaxFloat_1);
    ofRemoveListener(osc->maxEventFloat_2, this, &scene::onMaxFloat_2);
    
//    elements.clear();
    
    // notify Max of scene end
    ofxOscMessage m;
    m.setAddress("/scene/on");
    m.addIntArg(0);
    osc->sender.sendMessage(m);
}

// ------------------------------------------------------
void scene::update(){
    // manage scene behavior here

    aDot.update();
}

// ------------------------------------------------------
void scene::draw(){
    aDot.draw();
}

#pragma mark event callbacks

// ------------------------------------------------------
void scene::onMaxToggle(int& value){
    cout << "display dot toggle\n";
    aDot.display((value == 1));
}

// ------------------------------------------------------
void scene::onMaxFloat_1(float& value){
    aDot.setx(value * ofGetWidth());
}
// ------------------------------------------------------
void scene::onMaxFloat_2(float& value){
    cout << "set Y";
    aDot.sety(value * ofGetHeight());
}

#pragma mark keyboard callbacks
// ------------------------------------------------------
void scene::keyPressed(ofKeyEventArgs& args){

    
}
void scene::keyReleased(ofKeyEventArgs& args){
    
}

# pragma mark behavior


