#include "GameScene.h"
#include "ChessClass.h"
#include "SimpleAudioEngine.h"
#include"cocos2d.h"
#include"AudioEngine.h"
USING_NS_CC;

int ChessBoard[9][10] = {0};
bool ClickFlag = false;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init()
{
    CCLOG("3");

    if ( !Scene::init() )
    {
        return false;
    }
    //显示界面
    this->removeAllChildren();
    GameInterface();
    InitGameBoard();
    UpdateChessBoard();
    GameSide = RED;
    GameState = true;
    
    //清空悔棋栈，并保存初始状态
    RegretState.clear();
    
    //鼠标监听
    auto listener2 = EventListenerTouchOneByOne::create();
    listener2->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan , this);
    listener2->onTouchEnded = CC_CALLBACK_2(GameScene::ChessMove , this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener2, 1);

    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan , this);
    listener1->onTouchEnded = CC_CALLBACK_2(GameScene::ClassFactory , this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener1, 1);
    return true;
}

//判断是否将军
void CheckKing(int ChessID,int px,int py,Scene *scene)
{
    int ID = ChessBoard[px][py];
    
    if(ID <0 )
        ID = -ID;
    //棋子类制造
    switch (ID)
    {
        case RKING:
        {
            return;
        }
        case RROOK:
        {
            rook Crook(ChessID,px,py);
            Crook.moveTrack(scene,2);
            if(Crook.checkFlag == true)
                SimpleAudioEngine::getInstance()->playEffect("res/bgm/checkking.wav");
            Crook.checkFlag = false;
            return;
        }
        case RKNIGNT:
        {
            knight Cknight(ChessID,px,py);
            Cknight.moveTrack(scene,2);
            if(Cknight.checkFlag == true)
                SimpleAudioEngine::getInstance()->playEffect("res/bgm/checkking.wav");
            Cknight.checkFlag = false;
            return;
        }
        case RCANNON:
        {
            Cannon Ccannon(ChessID,px,py);
            Ccannon.moveTrack(scene,2);
            if(Ccannon.checkFlag == true)
                SimpleAudioEngine::getInstance()->playEffect("res/bgm/checkking.wav");
            Ccannon.checkFlag = false;
            return;
        }
        case RMANDARIN:
        {
            return;
        }
        case RELEPHANT:
        {
            return;
        }
        case RPAWN:
        {
            Pawn Cpawn(ChessID,px,py);
            Cpawn.moveTrack(scene,2);
            if(Cpawn.checkFlag == true)
                SimpleAudioEngine::getInstance()->playEffect("res/bgm/checkking.wav");
            Cpawn.checkFlag = false;
            return;
        }
        default:
            break;
    }
    return ;
}

void GameScene::ChessMove(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    if(Cstack.empty() == true || GameState == false)
        return;
    
    auto Cchess = Cstack.back();
    if(GameSide != Cchess.color)
        return;
    
    auto point = touch->getLocation();
    int px = (int)((point.x - 166.176+9.2)/18.4);
    int py = (int)((point.y - 60.825+9.3)/18.6);
    if(px < 0||px >8 ||py > 9||py < 0)
        return;
    int xx = Cchess.cx;
    int yy = Cchess.cy;
    if(Cchess.ChessBoardFlag[px][py] != EMPTY)
    {
        //保存移动前的的棋盘数据
        SaveChessBoardState();
        //改棋盘数据
        ChessBoard[xx][yy] = 0;
        ChessBoard[px][py] = Cchess.ChessBoardFlag[px][py];
        SimpleAudioEngine::getInstance()->playEffect("res/bgm/select.wav");
        
        this->removeAllChildren();
        //判断是否将军
        for(int i=0;i<9;i++)
            for(int j=0;j<10;j++)
            {
                CheckKing(ChessBoard[i][j], i, j, this);
            }
       // CheckKing(Cchess.chessID, px,py,this);
        //更新棋盘
        this->removeAllChildren();
        GameInterface();
        UpdateChessBoard();
        Cstack.clear();
        JudgeWin();
        GameSide = EMPTY - GameSide;
    }
}

void GameScene::SaveChessBoardState()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<10;j++)
        {
            RegretState.push_back(ChessBoard[i][j]);
        }
}

void GameScene::JudgeWin()
{
    bool RedWin = true;
    bool BlackWin = true;
    //判断红帅是否在
    for(int i=3;i<=5;i++)
        for(int j=0;j<=2;j++)
        {
            if(ChessBoard[i][j] == RKING)
                BlackWin = false;
        }
    
    //判断黑将是否在
    for(int i=3;i<=5;i++)
        for(int j=7;j<=9;j++)
        {
            if(ChessBoard[i][j] == BKING)
                RedWin = false;
        }
    
    if(RedWin == true||BlackWin == true)
    {
        int groudwidth,groudheight;
        groudwidth=Director::getInstance()->getWinSize().width;
        groudheight=Director::getInstance()->getWinSize().height;
        SimpleAudioEngine::getInstance()->playEffect("res/bgm/win.wav");
        if(RedWin == true)
        {
            auto RedWin = Sprite::create("res/css/gameEvent/whitewin.png");
            RedWin->setPosition(Point(groudwidth/2,groudheight/2+95));
            this->addChild(RedWin,1);
            GameState = false;
        }
        else if(BlackWin == true)
        {
            auto BlackWin = Sprite::create("res/css/gameEvent/blackwin.png");
            BlackWin->setPosition(Point(groudwidth/2,groudheight/2+95));
            this->addChild(BlackWin,1);
            GameState = false;
        }
    }
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)
{
    return true;
}
