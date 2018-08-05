#include"MenuScene.h"
#include"GameScene.h"
void MenuScene::BPVPGameStart(cocos2d::Ref *sender)
{
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto SceneA = GameScene::createScene();
    Director::getInstance()->replaceScene(SceneA);
}

bool MenuScene::onTouchBegan(Touch *touch,Event *unused_event)
{
    Point point = touch->getLocation();
    int px = (int)((point.x - 166.176+9.2)/18.4);
    int py = (int)((point.y - 60.825+9.3)/18.6);
    
    CCLOG("nx:%d ny:%d",px,py);
    return true;
}
