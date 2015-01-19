//
//  globals.cpp
//  scene_projections
//
//  Created by Julien Bloit on 24/08/14.
//
//

#include "globals.h"

globals* globals::uniqueInstance = NULL;

globals* globals::Instance(){
    if (!uniqueInstance){
        uniqueInstance = new globals;
        uniqueInstance->value = -1;
    }
    return uniqueInstance;
}


float globals::getValue(){
    return value;
}
void globals::setValue(float _val){
    value = _val;
}