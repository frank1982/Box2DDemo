

#ifndef __Box2DDemo__RectPhyObject__
#define __Box2DDemo__RectPhyObject__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
#include "PhyObject.h"

using namespace cocos2d;

class RectPhyObject:public PhyObject{
    
public:
    
    static RectPhyObject* create(bool isStatic,float* mShapeData,Layer* layer,b2World* world,float density,float friction,float restitution,std::string pic);
   
};

#endif /* defined(__Box2DDemo__RectPhyObject__) */
