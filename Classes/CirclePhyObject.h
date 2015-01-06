

#ifndef __Box2DDemo__CirclePhyObject__
#define __Box2DDemo__CirclePhyObject__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PhyObject.h"

using namespace cocos2d;

class CirclePhyObject:public PhyObject{
    
public:
    
    static CirclePhyObject* create(bool isStatic,float* mShapeData,Layer* layer,b2World* world,float density,float friction,float restitution,std::string pic);
    
};

#endif /* defined(__Box2DDemo__CirclePhyObject__) */
