//
//  dot.h
//  scene_projections
//
//  Created by Julien Bloit on 28/08/14.
//
//

#ifndef __scene_projections__dot__
#define __scene_projections__dot__

#include <iostream>
#include "_projectGlobals.h"
#include "ofMain.h"

// Circle dot
class dot{

public:
    void setup(float _x, float _y, float _radius);
    void update();
    void draw();
    
    void display(bool _displayFlag);
    void setx(float _x);
    void sety(float _y);

private:
    bool hide;
    ofVec2f center;
    float radius;
    ofColor color;
};

#endif /* defined(__scene_projections__dot__) */
