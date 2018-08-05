#include"GameScene.h"
#include"MenuScene.h"
void GameScene::BGiveUp(cocos2d::Ref *sender)
{
    if(GameState == false)
        return;
    int groudwidth,groudheight;
    groudwidth=Director::getInstance()->getWinSize().width;
    groudheight=Director::getInstance()->getWinSize().height;
    SimpleAudioEngine::getInstance()->playEffect("res/bgm/win.wav");
    if(GameSide == RED)
    {
        auto RedWin = Sprite::create("res/css/gameEvent/WhiteGiveUp.png");
        RedWin->setPosition(Point(groudwidth/2,groudheight/2+95));
        this->addChild(RedWin,1);
    }
    else if(GameSide == BLACK)
    {
        auto BlackWin = Sprite::create("res/css/gameEvent/BlackGiveUp.png");
        BlackWin->setPosition(Point(groudwidth/2,groudheight/2+95));
        this->addChild(BlackWin,1);
    }
    GameState = false;
}


void GameScene::BLeave(cocos2d::Ref *sender)
{
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    auto SceneB = MenuScene::createScene();
    Director::getInstance()->replaceScene(SceneB);
}

void GameScene::BPeace(cocos2d::Ref *sender)
{
    
}

void GameScene::BRegret(cocos2d::Ref *sender)
{
    if(GameState == false)
        return;
    if(RegretState.empty() == true)
    {
        CCLOG("empty!");
        return;
    }
    for(int i=8;i>=0;i--)
    {
        for(int j=9;j>=0;j--)
        {
            ChessBoard[i][j] = RegretState.back();
            RegretState.pop_back();
        }
    }
    this->removeAllChildren();
    GameInterface();
    UpdateChessBoard();
    GameSide = EMPTY - GameSide;
}

void GameScene::BReplay(cocos2d::Ref *sender)
{
    init();
}
