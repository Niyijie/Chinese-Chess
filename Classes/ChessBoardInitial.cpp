#include"GameScene.h"
#include"ChessClass.h"


void GameScene::UpdateChessBoard()
{
    for(int i=0;i<9;i++)
        for(int j=0;j<10;j++)
        {
            if(ChessBoard[i][j] == EMPTY)
                continue;
            auto Chess = ChessFactory(ChessBoard[i][j]);
            Chess->setScale(0.5);
            Chess->setPosition(Point(166.197+i*18.4,60.845+j*18.6));
            this->addChild(Chess,1);
        }
}

void GameScene::InitGameBoard()
{
    //初始化棋盘
    for(int i=0;i<9;i++)
        for(int j=0;j<10;j++)
            ChessBoard[i][j] = EMPTY;
    
    ChessBoard[0][0] = RROOK;
    ChessBoard[8][0] = RROOK;
    ChessBoard[1][0] = RKNIGNT;
    ChessBoard[7][0] = RKNIGNT;
    ChessBoard[2][0] = RELEPHANT;
    ChessBoard[6][0] = RELEPHANT;
    ChessBoard[3][0] = RMANDARIN;
    ChessBoard[5][0] = RMANDARIN;
    ChessBoard[4][0] = RKING;
    ChessBoard[1][2] = RCANNON;
    ChessBoard[7][2] = RCANNON;
    ChessBoard[0][3] = RPAWN;
    ChessBoard[2][3] = RPAWN;
    ChessBoard[4][3] = RPAWN;
    ChessBoard[6][3] = RPAWN;
    ChessBoard[8][3] = RPAWN;


    ChessBoard[0][9] = BROOK;
    ChessBoard[8][9] = BROOK;
    ChessBoard[1][9] = BKNIGNT;
    ChessBoard[7][9] = BKNIGNT;
    ChessBoard[2][9] = BELEPHANT;
    ChessBoard[6][9] = BELEPHANT;
    ChessBoard[3][9] = BMANDARIN;
    ChessBoard[5][9] = BMANDARIN;
    ChessBoard[4][9] = BKING;
    ChessBoard[1][7] = BCANNON;
    ChessBoard[7][7] = BCANNON;
    ChessBoard[0][6] = BPAWN;
    ChessBoard[2][6] = BPAWN;
    ChessBoard[4][6] = BPAWN;
    ChessBoard[6][6] = BPAWN;
    ChessBoard[8][6] = BPAWN;
}

//棋子工厂
Sprite* GameScene::ChessFactory(int ChessID)
{
    if(ChessID > 0)
    {
        switch (ChessID)
        {
            case RKING:
            {
                Sprite* Rking = new Sprite;
                Rking = Sprite::create("res/css/chess/rking.png");
                return Rking;
            }
            case RPAWN:
            {
                Sprite* Rpawn = new Sprite;
                Rpawn = Sprite::create("res/css/chess/rpawn.png");
                return Rpawn;
            }
            case RCANNON:
            {
                Sprite* Rcannon = new Sprite;
                Rcannon = Sprite::create("res/css/chess/rcannon.png");
                return Rcannon;
            }
            case RELEPHANT:
            {
                Sprite* Relephant = new Sprite;
                Relephant = Sprite::create("res/css/chess/relephant.png");
                return Relephant;
            }
            case RKNIGNT:
            {
                Sprite* Rknight = new Sprite;
                Rknight = Sprite::create("res/css/chess/rknight.png");
                return Rknight;
            }
            case RROOK:
            {
                Sprite* Rrook = new Sprite;
                Rrook = Sprite::create("res/css/chess/rrook.png");
                return Rrook;
            }
            case RMANDARIN:
            {
                Sprite* Rmandarin = new Sprite;
                Rmandarin = Sprite::create("res/css/chess/rmandarin.png");
                return Rmandarin;
            }
        }
    }
    else if(ChessID < 0)
    {
        switch (ChessID) {
            case BKING:
            {
                Sprite* Bking = new Sprite;
                Bking = Sprite::create("res/css/chess/bking.png");
                return Bking;
            }
            case BPAWN:
            {
                Sprite* Bpawn = new Sprite;
                Bpawn = Sprite::create("res/css/chess/bpawn.png");
                return Bpawn;
            }
            case BCANNON:
            {
                Sprite* Bcannon = new Sprite;
                Bcannon = Sprite::create("res/css/chess/bcannon.png");
                return Bcannon;
            }
            case BELEPHANT:
            {
                Sprite* Belephant = new Sprite;
                Belephant = Sprite::create("res/css/chess/belephant.png");
                return Belephant;
            }
            case BKNIGNT:
            {
                Sprite* Bknight = new Sprite;
                Bknight = Sprite::create("res/css/chess/bknight.png");
                return Bknight;
            }
            case BROOK:
            {
                Sprite* Brook = new Sprite;
                Brook = Sprite::create("res/css/chess/brook.png");
                return Brook;
            }
            case BMANDARIN:
            {
                Sprite* Bmandarin = new Sprite;
                Bmandarin = Sprite::create("res/css/chess/bmandarin.png");
                return Bmandarin;
            }
        }
    }
    
    return nullptr;
}

//棋子类工厂
void GameScene::ClassFactory(Touch *touch,Event *unused_event)
{
    if(GameState == false)
        return;
    
    this->removeAllChildren();
    GameInterface();
    UpdateChessBoard();
    //获取鼠标对应的棋盘位置
    Point point = touch->getLocation();
    int px = (int)((point.x - 166.176+9.2)/18.4);
    int py = (int)((point.y - 60.825+9.3)/18.6);
    if(px < 0||px > 8 ||py > 9||py < 0)
        return;
    //获取棋子类型ID
    int ID = ChessBoard[px][py];
    if(GameSide == RED)
    {
        if(ID < EMPTY)
            return;
    }
    else if(GameSide == BLACK)
    {
        if(ID > EMPTY)
            return;
    }
    //如果是空白位置
    if (ID == EMPTY)
        return;
    if(ID <0 )
        ID = -ID;
    //棋子类制造
    switch (ID)
    {
        case RKING:
        {
            king Cking(ChessBoard[px][py],px,py);
            Cking.moveTrack(this,1);
            Cstack.push_back(Cking);
            return;
        }
        case RROOK:
        {
            rook Crook(ChessBoard[px][py],px,py);
            Crook.moveTrack(this,1);
            Cstack.push_back(Crook);
            return;
        }
        case RKNIGNT:
        {
            knight Cknight(ChessBoard[px][py],px,py);
            Cknight.moveTrack(this,1);
            Cstack.push_back(Cknight);
            return;
        }
        case RCANNON:
        {
            Cannon Ccannon(ChessBoard[px][py],px,py);
            Ccannon.moveTrack(this,1);
            Cstack.push_back(Ccannon);
            return;
        }
        case RMANDARIN:
        {
            Mandarin Cmandarin(ChessBoard[px][py],px,py);
            Cmandarin.moveTrack(this,1);
            Cstack.push_back(Cmandarin);
            return;
        }
        case RELEPHANT:
        {
            Elephant Celephant(ChessBoard[px][py],px,py);
            Celephant.moveTrack(this,1);
            Cstack.push_back(Celephant);
            return;
        }
        case RPAWN:
        {
            Pawn Cpawn(ChessBoard[px][py],px,py);
            Cpawn.moveTrack(this,1);
            Cstack.push_back(Cpawn);
            return;
        }
        default:
            break;
    }
    return ;
}

//游戏棋盘界面
void GameScene::GameInterface()
{
    //打开音效
//    SimpleAudioEngine::getInstance()->playBackgroundMusic("res/bgm/bgmusic.mp3");
    
    //    auto ChessBoard = Sprite::create("res/css/backgroud/chessboard.png");
    auto ChessBoard = Sprite::create("res/css/backgroud/chessboard.png");
    
    Size visibleSize = Director::getInstance()->getWinSize();
    ChessBoard ->setScale(1, 1);
    ChessBoard ->setAnchorPoint(Point(0.5,0.5));
    ChessBoard ->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    this->addChild(ChessBoard,0);
    
    
    //悔棋按钮
    auto Regret = MenuItemImage::create("res/css/button/bregret_normal.png","res/css/button/bregret_selected.png",CC_CALLBACK_1(GameScene::BRegret, this));
    Regret ->setPosition(-70,-132);
    Regret->setScale(1.2);
    //认输按钮
    auto GiveUp = MenuItemImage::create("res/css/button/bgiveup_normal.png","res/css/button/bgiveup_selected.png",CC_CALLBACK_1(GameScene::BGiveUp, this));
    GiveUp ->setPosition(-35,-132);
    GiveUp->setScale(1.2);
    //求和按钮
    auto Peace = MenuItemImage::create("res/css/button/bpeace_normal.png","res/css/button/bpeace_selected.png",CC_CALLBACK_1(GameScene::BPeace, this));
    Peace ->setPosition(-0,-132);
    Peace->setScale(1.2);
    //重新按钮
    auto Replay = MenuItemImage::create("res/css/button/bagain_normal.png","res/css/button/bagain_selected.png",CC_CALLBACK_1(GameScene::BReplay, this));
    Replay ->setPosition(35,-132);
    Replay ->setScale(1.2);
    //离开按钮
    auto Leave = MenuItemImage::create("res/css/button/bleave_normal.png","res/css/button/bleave_selected.png",CC_CALLBACK_1(GameScene::BLeave, this));
    Leave ->setPosition(70,-132);
    Leave->setScale(1.2);
    //注册按钮
    auto menu = Menu::create(Regret,GiveUp,Peace,Replay,Leave,NULL);
    this->addChild(menu);
}
