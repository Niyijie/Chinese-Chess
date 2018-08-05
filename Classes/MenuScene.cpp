#include "MenuScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool MenuScene::init()
{
    if ( !Scene::init())
    {
        return false;
    }
    InitMenu();
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("res/bgm/bgmusic.mp3");
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(MenuScene::onTouchBegan , this);
   // listener->onTouchEnded = CC_CALLBACK_2(GameScene::AddChess , this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

    return true;
}

//菜单界面
void MenuScene::InitMenu()
{
    auto menuBackGround = Sprite::create("res/css/backgroud/menu.png");

    Size visibleSize = Director::getInstance()->getWinSize();
    menuBackGround ->setScale(1.05);
    menuBackGround ->setAnchorPoint(Point(0.5,0.5));
    menuBackGround ->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    this->addChild(menuBackGround,0);
    //人人对战按钮
    auto PVP = MenuItemImage::create("res/css/button/PVP_normal.png","res/css/button/PVP_selected.png",CC_CALLBACK_1(MenuScene::BPVPGameStart, this));
    PVP->setPosition(Point(-55,-60));
    //人机对战
    auto PVC = MenuItemImage::create("res/css/button/PVC_normal.png","res/css/button/PVC_selected.png",CC_CALLBACK_1(MenuScene::BPVPGameStart, this));
    PVC->setPosition(Point(0,-60));
    //复盘按钮
    auto REPLAY = MenuItemImage::create("res/css/button/replay_normal.png","res/css/button/replay_selected.png",CC_CALLBACK_1(MenuScene::BPVPGameStart, this));
    REPLAY->setPosition(Point(55,-60));
    //注册菜单界面按钮
    auto menu = Menu::create(PVP,PVC,REPLAY,NULL);
    this->addChild(menu);
    
    CCLOG("x: %f,y: %f",visibleSize.width/2,visibleSize.height/2);

}

