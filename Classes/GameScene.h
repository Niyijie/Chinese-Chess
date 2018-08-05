#ifndef GameScene_h
#define GameScene_h
#include "cocos2d.h"
#include "ChessClass.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
USING_NS_CC;
#define EMPTY 0
#define RED 1
#define BLACK -1
//宏定义表示棋子的标号
#define BKING -2
#define BROOK -3
#define BKNIGNT -4
#define BCANNON -5
#define BMANDARIN -6
#define BELEPHANT -7
#define BPAWN -8

#define RKING 2
#define RROOK 3
#define RKNIGNT 4
#define RCANNON 5
#define RMANDARIN 6
#define RELEPHANT 7
#define RPAWN 8

extern int ChessBoard[9][10];
extern bool ClickFlag;
using namespace std;
class GameScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    virtual bool onTouchBegan(Touch *touch,Event *unused_event);
    //virtual bool onTouchEnded(Touch *touch,Event *unused_event);
    CREATE_FUNC(GameScene);
    
    void GameInterface();    //游戏界面
    void InitGameBoard();    //初始化棋盘
    Sprite* ChessFactory(int ChessID);     //添加棋子的工厂
    void ClassFactory(Touch *touch,Event *unused_event);// 棋子类工厂
    void ChessMove(Touch *touch,Event *unused_event);//棋子移动回调函数
    void SaveChessBoardState();//保存每次棋盘的信息
    void UpdateChessBoard();  //更新棋盘
    void JudgeWin();
    //按钮回调函数
    void BGiveUp(Ref *sender);
    void BPeace(Ref *sender);
    void BReplay(Ref *sender);
    void BLeave(Ref *sender);
    void BRegret(Ref *sender);
    
    vector<chess> Cstack;  //存放棋子工厂返回值
    int GameSide; //记录当前执棋者
    bool GameState;//记录棋盘开始或状态
    vector<int> RegretState;  //每次悔棋的棋盘状态
    
};

#endif /* GameScene_h */
