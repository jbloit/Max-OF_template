//
//  dot.cpp
//  scene_projections
//
//  Created by Julien Bloit on 28/08/14.
//
//

#include "dot.h"

void dot::setup(float _x, float _y, float _radius=30){
    center.x = _x;
    center.y = _y;
    radius = _radius;
    hide = false;
    color = ofColor::steelBlue;
   }

void dot::update(){
// TODO: add ALIVE_CHECK code here

}

void dot::draw(){
    if (!hide){
        ofFill();
        ofSetColor(color);
        ofCircle(center.x, center.y, radius);
    }
}

void dot::setx(float _x){
    center.x = _x;
}
void dot::sety(float _y){
    cout << "set y " << _y  << "\n";
    center.y = _y;
}

void dot::display(bool _displayFlag){
    hide = !_displayFlag;
}