

#include "PhyObject.h"

void PhyObject::fresh(){
    
    //CCLog("fresh");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    b2Vec2 position=this->_body->GetPosition();
    float angle=this->_body->GetAngle();

    this->_sprite->setPosition
    (
     Point
     (
      position.x,
      position.y
      )
     );
  
    this->_sprite->setRotation(-angle*180.0/3.1415926);
}