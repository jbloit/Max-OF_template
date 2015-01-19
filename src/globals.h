//
//  globals.h
//  scene_projections
//
//  Created by Julien Bloit on 24/08/14.
//
//

#ifndef __scene_projections__globals__
#define __scene_projections__globals__

#include <iostream>

class globals{
public:
    static globals* Instance();
    float getValue();
    void setValue(float _val);
    
private:
    float value;
    globals(){};
    static globals* uniqueInstance;
};

#endif /* defined(__scene_projections__globals__) */
