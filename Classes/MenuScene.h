#ifndef __GAMESCENE_SCENE_H__
#define __GAMESCENE_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

class MenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    virtual bool onTouchBegan(Touch *touch,Event *unused_event);

    CREATE_FUNC(MenuScene);
    
    //菜单
    void InitMenu();
    //游戏界面
    //void GameInterface();
    //按钮回调函数
    void BPVPGameStart(Ref *sender);

    
    void menuCloseCallback(cocos2d::Ref* pSender);

};

#endif // __HELLOWORLD_SCENE_H__
