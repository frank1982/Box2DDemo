

#include "RectPhyObject.h"

using namespace cocos2d;


RectPhyObject* RectPhyObject::create(bool isStatic,float* mShapeData,Layer* layer,b2World* world,float density,float friction,float restitution,std::string pic){
    
    RectPhyObject* rectObject=new RectPhyObject;

    b2BodyDef bodyDef;
    if(!isStatic)
    {
        bodyDef.type = b2_dynamicBody;
    }
    bodyDef.position.Set(mShapeData[0], mShapeData[1]);
    rectObject->_body = world->CreateBody(&bodyDef);
    //body->SetUserData(id);
    
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(mShapeData[2], mShapeData[3]);
    
    if(!isStatic)
    {
        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = density;
        fixtureDef.friction = friction;
        fixtureDef.restitution=restitution;
        rectObject->_body->CreateFixture(&fixtureDef);
    }
    else
    {
        rectObject->_body->CreateFixture(&dynamicBox, 0.0f);
    }
    
    rectObject->_sprite = Sprite::create(pic);
    layer->addChild(rectObject->_sprite, 1);
    Size size=rectObject->_sprite->getContentSize();

    float pw=mShapeData[2]*2;
    float ph=mShapeData[3]*2;
    float scaleX=pw/size.width;
    float scaleY=ph/size.height;
    rectObject->_sprite->setScaleX(scaleX);
    rectObject->_sprite->setScaleY(scaleY);
    rectObject->_sprite->setPosition(mShapeData[0],mShapeData[1]);
    
    

    return rectObject;
}





