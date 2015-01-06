#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "RectPhyObject.h"
#include "CirclePhyObject.h"
#include "PhyObject.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    CREATE_FUNC(HelloWorld);
    
    std::map<std::string,PhyObject*> pom;
    b2World* world;
    
    int index;
    std::string* indexStr;
    
    void setGround();
    void createPyramid();
    void createBullet();
    void update(float dt);
    void step();
};

#endif // __HELLOWORLD_SCENE_H__
