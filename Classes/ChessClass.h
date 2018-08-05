#ifndef ChessClass_h
#define ChessClass_h
#include "cocos2d.h"
USING_NS_CC;
#define RED 1
#define BLACK -1
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
class chess
{
public:
    chess()
    {
        for(int i=0;i<=9;i++)
            for(int j=0;j<=10;j++)
                ChessBoardFlag[i][j] = 0;
        checkFlag = false;
        chessID = 0;
    }
    
    virtual void moveTrack(Scene *scene,int mode)
    {
        CCLOG("chess moving...");
    }
    int ChessBoardFlag[9][10];
    bool checkFlag;   //是否将军的标志
    int chessID;
    int color;
    int cx;
    int cy;
};

class king:public chess
{
public:
    king(int ID,int xx,int yy)
    {
        checkFlag = false;
        cx = xx;
        cy = yy;
        if(ID > 0)
        {
            chessID = RKING;
            color = RED;
        }
        else if(ID<0)
        {
            chessID = BKING;
            color = BLACK;
        }
        
    }
    void moveTrack(Scene *scene,int mode);
};

class rook:public chess
{
public:
    rook(int ID,int xx,int yy)
    {
        checkFlag = false;
        cx = xx;
        cy = yy;
        if(ID > 0)
        {
            chessID = RROOK;
            color = RED;
        }
        else if(ID<0)
        {
            chessID = BROOK;
            color = BLACK;
        }
    }
    void moveTrack(Scene *scene,int mode);
};

class knight:public chess
{
public:
    knight(int ID,int xx,int yy)
    {
        checkFlag = false;
        cx = xx;
        cy = yy;
        if(ID > 0)
        {
            chessID = RKNIGNT;
            color = RED;
        }
        else if(ID<0)
        {
            chessID = BKNIGNT;
            color = BLACK;
        }
    }
    void moveTrack(Scene *scene,int mode);
};

class Cannon:public chess
{
public:
    Cannon(int ID,int xx,int yy)
    {
        checkFlag = false;
        cx = xx;
        cy = yy;
        if(ID > 0)
        {
            chessID = RCANNON;
            color = RED;
        }
        else if(ID<0)
        {
            chessID = BCANNON;
            color = BLACK;
        }
    }
    void moveTrack(Scene *scene,int mode);
};

class Mandarin:public chess
{
public:
    Mandarin(int ID,int xx,int yy)
    {
        checkFlag = false;
        cx = xx;
        cy = yy;
        if(ID > 0)
        {
            chessID = RMANDARIN;
            color = RED;
        }
        else if(ID<0)
        {
            chessID = BMANDARIN;
            color = BLACK;
        }
    }
    void moveTrack(Scene *scene,int mode);
};

class Elephant:public chess
{
public:
    Elephant(int ID,int xx,int yy)
    {
        checkFlag = false;
        cx = xx;
        cy = yy;
        if(ID > 0)
        {
            chessID = RELEPHANT;
            color = RED;
        }
        else if(ID<0)
        {
            chessID = BELEPHANT;
            color = BLACK;
        }
    }
    void moveTrack(Scene *scene,int mode);
};

class  Pawn:public chess
{
public:
    Pawn(int ID,int xx,int yy)
    {
        checkFlag = false;
        cx = xx;
        cy = yy;
        if(ID > 0)
        {
            chessID = RPAWN;
            color = RED;
        }
        else if(ID<0)
        {
            chessID = BPAWN;
            color = BLACK;
        }
    }
    void moveTrack(Scene *scene,int mode);
};
#endif

