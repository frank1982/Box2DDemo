#include "HelloWorldScene.h"

static int* NUMS=new int[9]{1,2,3,4,5,4,3,2,1};
static std::string SA[8]={
				"pic/brownCube.png","pic/pinkCube.png",
				"pic/redCube.png","pic/yellowCube.png",
				"pic/greenCube.png","pic/blueCube.png",
				"pic/violetCube.png","pic/orangeCube.png"
};


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);
    

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    schedule(schedule_selector(HelloWorld::update), 0.001f);
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    LayerColor *background = LayerColor::create( Color4B(255,255,255,255) );
    this->addChild(background,-20);

    b2Vec2 gravity(0.0f, -10.0f);
    world = new b2World(gravity);
    world->SetAllowSleeping(true);

    setGround();
    createPyramid();
    createBullet();
    
    return true;
}

void HelloWorld::setGround(){
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto data1=new float[4]{20,450,10,400};
    auto object1=RectPhyObject::create(true,data1,this,world, 0, 0, 0, "pic/bolckGrayCube.png");
    index=0;
    indexStr=new std::string(StringUtils::format("%d", index));
    pom[*indexStr]=object1;
    
    auto data2=new float[4]{visibleSize.width-20,450,10,400};
    auto object2=RectPhyObject::create(true,data2,this,world, 0, 0, 0, "pic/bolckGrayCube.png");
    index++;
    indexStr=new std::string(StringUtils::format("%d", index));
    pom[*indexStr]=object2;
    
    auto data3=new float[4]{visibleSize.width/2,50,visibleSize.width/2-10,10};
    auto object3=RectPhyObject::create(true,data3,this,world, 0, 0, 0, "pic/bolckGrayCube.png");
    index++;
    indexStr=new std::string(StringUtils::format("%d", index));
    pom[*indexStr]=object3;
    
    CCLog("_MAP length is: %d",pom.size());
}

void HelloWorld::createPyramid(){
    
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<NUMS[i];j++){
            
            float x=80+i*60;
            float y=100+j*60;
            auto data=new float[4]{x,y,10,30};
            index++;
            indexStr=new std::string(StringUtils::format("%d", index));
            auto object=RectPhyObject::create(false,data,this,world, 0.6f, 0.1f, 0.2f, SA[index%8]);
            pom[*indexStr]=object;
            CCLog("set i: %d, j: %d,index: %d",i,j,index);
        }
    }
    
}
void HelloWorld::update(float dt){
    
    //CCLOG("update");
    step();
    std::map<std::string,PhyObject*>::iterator iter;
    for(iter=pom.begin();iter!=pom.end();iter++)
    {
        PhyObject* po=iter->second;
        po->fresh();
    }
}
void HelloWorld::createBullet(){
    
    auto data=new float[4]{250,800,20,20};
    index++;
    indexStr=new std::string(StringUtils::format("%d", index));
    auto object=CirclePhyObject::create(false,data,this,world, 2.6f, 0.1f, 0.2f, "pic/ball.png");
    pom[*indexStr]=object;
    CCLog("set index: %d",index);

}
void HelloWorld::step(){
    
    float32 timeStep = 2.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    world->Step(timeStep,velocityIterations,positionIterations);
}


