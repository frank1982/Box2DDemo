

#ifndef __Box2DDemo__PhyObject__
#define __Box2DDemo__PhyObject__

#include "cocos2d.h"
#include "Box2D/Box2D.h"
using namespace cocos2d;

enum SHAPE{
    
    Rect,Circle,Polygon
    
};

class PhyObject{
    
public:
    
    bool _isStatic;
    float _density;
    float _friction;
    float _restitution;
    float* _shapeData;
    SHAPE _shape;
    Sprite* _sprite;
    b2Body* _body;
    void fresh();
    
};




#endif /* defined(__Box2DDemo__PhyObject__) */
