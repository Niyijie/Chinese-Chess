#include"ChessClass.h"
#include"GameScene.h"
void addCanset(Scene *scene,int x,int y)
{
    auto canset = Sprite::create("res/css/chess/canset.png");
    canset->setScale(0.8);
    canset->setPosition(Point(166.197+x*18.4,60.845+y*18.6));
    scene->addChild(canset);
}

//将、帅类
void king::moveTrack(Scene *scene,int mode)
{
    int x = this->cx;
    int y = this->cy;
    bool derail = false;
    //左
    if(x-1 >= 3)
    {
        for(int py = 0;py < 10;py++)
        {
            if(ChessBoard[x][y]+ChessBoard[x-1][py] == 0)
                derail = true;
        }

        
        if ((this->color == RED)&&(derail == false))
        {
            if(ChessBoard[x-1][y] <= EMPTY)
            {
                if(ChessBoard[x-1][y] == BKING)
                    checkFlag = true;
                ChessBoardFlag[x-1][y] = ChessBoard[x][y];
                if(mode == 1)
                    addCanset(scene, x-1, y);
            }
        }
        else if((this->color == BLACK)&&(derail == false))
        {
            if(ChessBoard[x-1][y] >= EMPTY)
            {
                if(ChessBoard[x-1][y] == RKING)
                    checkFlag = true;
                ChessBoardFlag[x-1][y] = ChessBoard[x][y];
                if(mode == 1)
                    addCanset(scene, x-1, y);
            }
        }
    }
    derail = false;
    //右
    if(x+1 <= 5)
    {
        for(int py = 0;py < 10;py++)
        {
            if(ChessBoard[x][y]+ChessBoard[x+1][py] == 0)
                derail = true;
        }
        
        if((this->color == RED)&&(derail == false))
        {
            if(ChessBoard[x+1][y] <= EMPTY)
            {
                if(ChessBoard[x+1][y] == BKING)
                    checkFlag = true;
                ChessBoardFlag[x+1][y] = ChessBoard[x][y];
                addCanset(scene, x+1, y);
            }
        }
        else if((this->color == BLACK)&&(derail == false))
        {
            if(ChessBoard[x+1][y] >= 0)
            {
                if(ChessBoard[x+1][y] == RKING)
                    checkFlag = true;
                ChessBoardFlag[x+1][y] = ChessBoard[x][y];
                if(mode == 1)
                    addCanset(scene, x+1, y);
            }
        }
        
    }
    //上
    if((y <= 1&&this->color==RED)||(y <= 8&&this->color==BLACK))
    {
        if(this->color == RED)
        {
            if(ChessBoard[x][y+1] <= 0)
            {
                if(ChessBoard[x][y+1] == BKING)
                    checkFlag = true;
                ChessBoardFlag[x][y+1] = ChessBoard[x][y];
                if(mode == 1)
                    addCanset(scene, x, y+1);
            }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[x][y+1] >= 0)
            {
                if(ChessBoard[x][y+1] == RKING)
                    checkFlag = true;
                ChessBoardFlag[x][y+1] = ChessBoard[x][y];
                if(mode == 1)
                    addCanset(scene, x, y+1);
            }
        }
    }
    //下
    if((y >= 1&&this->color==RED)||(y >= 8&&this->color==BLACK))
    {
        if(this->color == RED)
        {
            if(ChessBoard[x][y-1] <= 0)
            {
                if(ChessBoard[x][y-1] == BKING)
                    checkFlag = true;
                ChessBoardFlag[x][y-1] = ChessBoard[x][y];
                if(mode == 1)
                    addCanset(scene, x, y-1);
            }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[x][y-1] >= 0)
            {
                if(ChessBoard[x][y-1] == RKING)
                    checkFlag = true;
                ChessBoardFlag[x][y-1] = ChessBoard[x][y];
                if(mode == 1)
                    addCanset(scene, x, y-1);
            }
        }
    }

}

//车类
void rook::moveTrack(cocos2d::Scene *scene,int mode)
{
    CCLOG("in here");
    int x = this->cx;
    int y = this->cy;
    //左
    int px = x-1;
    while (px >= 0)
    {
        if(this->color == RED)
        {
            if(ChessBoard[px][y] <= EMPTY)
            {
                if(ChessBoard[px][y] == BKING)
                {
                    checkFlag = true;
                }
                if(mode == 1)
                    addCanset(scene, px, y);
                ChessBoardFlag[px][y] = ChessBoard[x][y];
            }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[px][y] >= EMPTY)
            {
                if(ChessBoard[px][y] == RKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, px, y);
                ChessBoardFlag[px][y] = ChessBoard[x][y];
            }
        }
        if(ChessBoard[px][y] != EMPTY)
            break;
        px = px-1;
    }
    //右
    px = x+1;
    while (px <= 8)
    {
        if(this->color == RED)
        {
            if(ChessBoard[px][y] <= EMPTY)
            {
                if(ChessBoard[px][y] == BKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, px, y);
                ChessBoardFlag[px][y] = ChessBoard[x][y];
            }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[px][y] >= EMPTY)
            {
                if(ChessBoard[px][y] == RKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, px, y);
                ChessBoardFlag[px][y] = ChessBoard[x][y];
            }
        }
        if(ChessBoard[px][y] != EMPTY)
            break;
        px = px+1;
    }
    //上
    int py = y+1;
    while (py <= 9)
    {
        if(this->color == RED)
        {
            if(ChessBoard[x][py] <= EMPTY)
            {
                if(ChessBoard[x][py] == BKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, x, py);
                ChessBoardFlag[x][py] = ChessBoard[x][y];
            }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[x][py] >= EMPTY)
            {
                if(ChessBoard[x][py] == RKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, x, py);
                ChessBoardFlag[x][py] = ChessBoard[x][y];
            }
        }
        if(ChessBoard[x][py] != EMPTY)
            break;
        py = py+1;
    }
    //下
    py = y-1;
    while (py >= 0)
    {
        if(this->color == RED)
        {
            if(ChessBoard[x][py] <= EMPTY)
            {
                if(ChessBoard[x][py] == BKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, x, py);
                ChessBoardFlag[x][py] = ChessBoard[x][y];
            }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[x][py] >= EMPTY)
            {
                if(ChessBoard[x][py] == RKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, x, py);
                ChessBoardFlag[x][py] = ChessBoard[x][y];
            }
        }
        if(ChessBoard[x][py] != EMPTY)
            break;
        py = py-1;
    }
}

//马类
void knight::moveTrack(cocos2d::Scene *scene,int mode)
{
    int x = this->cx;
    int y = this->cy;
    
    //上
    if(y <= 7)
    {
        if(this->color == RED)
        {
           if(ChessBoard[x][y+1] == EMPTY)
           {
               //上左
               if(x >= 1)
                    if(ChessBoard[x-1][y+2] <= EMPTY)
                    {
                        if(ChessBoard[x-1][y+2] == BKING)
                            checkFlag = true;
                        ChessBoardFlag[x-1][y+2] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x-1, y+2);
                    }
               //上右
               if(x <= 7)
                   if(ChessBoard[x+1][y+2] <= EMPTY)
                   {
                       if(ChessBoard[x+1][y+2] == BKING)
                           checkFlag = true;
                       ChessBoardFlag[x+1][y+2] = ChessBoard[x][y];
                       if(mode == 1)
                           addCanset(scene, x+1, y+2);
                   }
           }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[x][y+1] == EMPTY)
            {
                //上左
                if(x >= 1)
                    if(ChessBoard[x-1][y+2] >= EMPTY)
                    {
                        if(ChessBoard[x-1][y+2] == RKING)
                            checkFlag = true;
                        ChessBoardFlag[x-1][y+2] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x-1, y+2);
                    }
                //上右
                if(x <= 7)
                    if(ChessBoard[x+1][y+2] >= EMPTY)
                    {
                        if(ChessBoard[x+1][y+2] == RKING)
                            checkFlag = true;
                        ChessBoardFlag[x+1][y+2] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x+1, y+2);
                    }
            }
        }
    }
    //下
    if(y >= 2)
    {
        if(this->color == RED)
        {
            if(ChessBoard[x][y-1] == EMPTY)
            {
                //下左
                if(x >= 1)
                    if(ChessBoard[x-1][y-2] <= EMPTY)
                    {
                        if(ChessBoard[x-1][y-2] == BKING)
                            checkFlag = true;
                        ChessBoardFlag[x-1][y-2] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x-1, y-2);
                    }
                //下右
                if(x <= 7)
                    if(ChessBoard[x+1][y-2] <= EMPTY)
                    {
                        if(ChessBoard[x+1][y-2] == BKING)
                            checkFlag = true;
                        ChessBoardFlag[x+1][y-2] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x+1, y-2);
                    }
            }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[x][y-1] == EMPTY)
            {
                //下左
                if(x >= 1)
                    if(ChessBoard[x-1][y-2] >= EMPTY)
                    {
                        if(ChessBoard[x-1][y-2] == RKING)
                            checkFlag = true;
                        ChessBoardFlag[x-1][y-2] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x-1, y-2);
                    }
                //下右
                if(x <= 7)
                    if(ChessBoard[x+1][y-2] >= EMPTY)
                    {
                        if(ChessBoard[x+1][y-2] == RKING)
                            checkFlag = true;
                        ChessBoardFlag[x+1][y-2] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x+1, y-2);
                    }
            }
        }
    }
    //左
    if(x >= 2)
    {
        if(this->color == RED)
        {
            if(ChessBoard[x-1][y] == EMPTY)
            {
                //左上
                if(y <= 8)
                    if(ChessBoard[x-2][y+1] <= EMPTY)
                    {
                        if(ChessBoard[x-2][y+1] == BKING)
                            checkFlag = true;
                        ChessBoardFlag[x-2][y+1] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x-2, y+1);
                    }
                //左下
                if(y >= 1)
                    if(ChessBoard[x-2][y-1] <= EMPTY)
                    {
                        if(ChessBoard[x-2][y-1] == BKING)
                            checkFlag = true;
                        ChessBoardFlag[x-2][y-1] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x-2, y-1);
                    }
            }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[x-1][y] == EMPTY)
            {
                //左上
                if(y <= 8)
                    if(ChessBoard[x-2][y+1] >= EMPTY)
                    {
                        if(ChessBoard[x-2][y+1] == RKING)
                            checkFlag = true;
                        ChessBoardFlag[x-2][y+1] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x-2, y+1);
                    }
                //左下
                if(y >= 1)
                    if(ChessBoard[x-2][y-1] >= EMPTY)
                    {
                        if(ChessBoard[x-2][y-1] == RKING)
                            checkFlag = true;
                        ChessBoardFlag[x-2][y-1] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x-2, y-1);
                    }
            }
        }
    }
    //右
    if(x <= 6)
    {
        if(this->color == RED)
        {
            if(ChessBoard[x+1][y] == EMPTY)
            {
                //右上
                if(y <= 8)
                    if(ChessBoard[x+2][y+1] <= EMPTY)
                    {
                        if(ChessBoard[x+1][y+1] == BKING)
                            checkFlag = true;
                        ChessBoardFlag[x+2][y+1] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x+2, y+1);
                    }
                //右下
                if(y >= 1)
                    if(ChessBoard[x+2][y-1] <= EMPTY)
                    {
                        if(ChessBoard[x+1][y-1] == BKING)
                            checkFlag = true;
                        ChessBoardFlag[x+2][y-1] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x+2, y-1);
                    }
            }
        }
        else if(this->color == BLACK)
        {
            if(ChessBoard[x+1][y] == EMPTY)
            {
                //右上
                if(y <= 8)
                    if(ChessBoard[x+2][y+1] >= EMPTY)
                    {
                        if(ChessBoard[x+2][y+1] == RKING)
                            checkFlag = true;
                        ChessBoardFlag[x+2][y+1] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x+2, y+1);
                    }
                //右下
                if(y >= 1)
                    if(ChessBoard[x+2][y-1] >= EMPTY)
                    {
                        if(ChessBoard[x+2][y-1] == RKING)
                            checkFlag = true;
                        ChessBoardFlag[x+2][y-1] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, x+2, y-1);
                    }
            }
        }
    }
}
//炮类
void Cannon::moveTrack(cocos2d::Scene *scene,int mode)
{
    int x = this->cx;
    int y = this->cy;
    //左
    int px = x-1;
    while (px >= 0)
    {
        if(ChessBoard[px][y] == EMPTY)
        {
            ChessBoardFlag[px][y] = ChessBoard[x][y];
            if(mode == 1)
                addCanset(scene, px, y);
        }
        if(ChessBoard[px][y] != EMPTY)
        {
            //寻找可以吃的子
            px = px-1;
            while(px >= 0)
            {
                if(this->color == RED)
                {
                    if(ChessBoard[px][y] < EMPTY)
                    {
                        if(ChessBoard[px][y] == BKING)
                            checkFlag = true;
                        ChessBoardFlag[px][y] = ChessBoard[x][y];
                        if(mode == 1)
                            addCanset(scene, px, y);
                        break;
                    }
                    if(ChessBoard[px][y] > EMPTY || px == 0)
                    {
                        break;
                    }
                }
                else if(this->color == BLACK)
                {
                    if(ChessBoard[px][y] > EMPTY)
                    {
                        ChessBoardFlag[px][y] = ChessBoard[x][y];
                        if(ChessBoard[px][y] == RKING)
                            checkFlag = true;
                        if(mode == 1)
                            addCanset(scene, px, y);
                        break;
                    }
                    if(ChessBoard[px][y] < EMPTY || px == 0)
                    {
                        break;
                    }
                }
                px = px - 1;
            }
            break;
        }
        px = px-1;
    }
    //右
    px = x+1;
    while (px <= 8)
    {
        if(ChessBoard[px][y] == EMPTY)
        {
            ChessBoardFlag[px][y] = ChessBoard[x][y];
            if(mode == 1)
                addCanset(scene, px, y);
        }
        if(ChessBoard[px][y] != EMPTY)
        {
            //寻找可以吃的子
            px = px+1;
            while(px <= 8)
            {
                if(this->color == RED)
                {
                    if(ChessBoard[px][y] < EMPTY)
                    {
                        ChessBoardFlag[px][y] = ChessBoard[x][y];
                        if(ChessBoard[px][y] == BKING)
                            checkFlag = true;
                        if(mode == 1)
                            addCanset(scene, px, y);
                        break;
                    }
                    if(ChessBoard[px][y] > EMPTY || px == 8)
                    {
                        break;
                    }
                }
                else if(this->color == BLACK)
                {
                    if(ChessBoard[px][y] > EMPTY)
                    {
                        ChessBoardFlag[px][y] = ChessBoard[x][y];
                        if(ChessBoard[px][y] == RKING)
                            checkFlag = true;
                        if(mode == 1)
                            addCanset(scene, px, y);
                        break;
                    }
                    if(ChessBoard[px][y] < EMPTY || px == 8)
                    {
                        break;
                    }
                }
                px = px + 1;
            }
            break;
        }
        px = px+1;
    }
    //上
    int py = y+1;
    while (py <= 9)
    {
        if(ChessBoard[x][py] == EMPTY)
        {
            ChessBoardFlag[x][py] = ChessBoard[x][y];
            if(mode == 1)
                addCanset(scene, x, py);
        }
        if(ChessBoard[x][py] != EMPTY)
        {
            //寻找可以吃的子
            py = py+1;
            while(py <= 9)
            {
                if(this->color == RED)
                {
                    if(ChessBoard[x][py] < EMPTY)
                    {
                        ChessBoardFlag[x][py] = ChessBoard[x][y];
                        if(ChessBoard[x][py] == BKING)
                            checkFlag = true;
                        if(mode == 1)
                            addCanset(scene, x, py);
                        break;
                    }
                    if(ChessBoard[x][py] > EMPTY || py == 9)
                    {
                        break;
                    }
                }
                else if(this->color == BLACK)
                {
                    if(ChessBoard[x][py] > EMPTY)
                    {
                        ChessBoardFlag[x][py] = ChessBoard[x][y];
                        if(ChessBoard[x][py] == RKING)
                            checkFlag = true;
                        if(mode == 1)
                            addCanset(scene, x, py);
                        break;
                    }
                    if(ChessBoard[x][py] < EMPTY || py == 9)
                    {
                        break;
                    }
                }
                py = py + 1;
            }
            break;
        }
        py = py+1;
    }
    //下
    py = y-1;
    while (py >= 0)
    {
        if(ChessBoard[x][py] == EMPTY)
        {
            ChessBoardFlag[x][py] = ChessBoard[x][y];
            if(mode == 1)
                addCanset(scene, x, py);
        }
        if(ChessBoard[x][py] != EMPTY)
        {
            //寻找可以吃的子
            py = py-1;
            while(py >= 0)
            {
                if(this->color == RED)
                {
                    if(ChessBoard[x][py] < EMPTY)
                    {
                        ChessBoardFlag[x][py] = ChessBoard[x][y];
                        if(ChessBoard[x][py] == BKING)
                            checkFlag = true;
                        if(mode == 1)
                            addCanset(scene, x, py);
                        break;
                    }
                    if(ChessBoard[x][py] > EMPTY && py == 0)
                    {
                        break;
                    }
                }
                else if(this->color == BLACK)
                {
                    if(ChessBoard[x][py] > EMPTY)
                    {
                        ChessBoardFlag[x][py] = ChessBoard[x][y];
                        if(ChessBoard[x][py] == RKING)
                            checkFlag = true;
                        if(mode == 1)
                            addCanset(scene, x, py);
                        break;
                    }
                    if(ChessBoard[x][py] < EMPTY && px == 0)
                    {
                        break;
                    }
                }
                py = py - 1;
            }
            break;
        }
            py = py-1;
    }
}
//士类
void Mandarin::moveTrack(cocos2d::Scene *scene,int mode)
{
    int x = this->cx;
    int y = this->cy;
    
    if(x >= 4)
    {
        if((y <= 1&&this->color==RED)||(y <= 8&&this->color==BLACK))  //左上
        {
            if(this->color == RED)
            {
                if(ChessBoard[x-1][y+1] <= EMPTY)
                {
                    ChessBoardFlag[x-1][y+1] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x-1, y+1);
                }
            }
            else if(this->color == BLACK)
            {
                if(ChessBoard[x-1][y+1] >= EMPTY)
                {
                    ChessBoardFlag[x-1][y+1] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x-1, y+1);
                }
            }
        }
        if((y >= 1&&this->color==RED)||(y >= 8&&this->color==BLACK)) //左下
        {
            if(this->color == RED)
            {
                if(ChessBoard[x-1][y-1] <= EMPTY)
                {
                    ChessBoardFlag[x-1][y-1] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x-1, y-1);
                }
            }
            else if(this->color == BLACK)
            {
                if(ChessBoard[x-1][y-1] >= EMPTY)
                {
                    ChessBoardFlag[x-1][y-1] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x-1, y-1);
                }
            }
        }
    }
    if(x <= 4)
    {
        if((y <= 1&&this->color==RED)||(y <= 8&&this->color==BLACK)) //右上
        {
            if(this->color == RED)
            {
                if(ChessBoard[x+1][y+1] <= EMPTY)
                {
                    ChessBoardFlag[x+1][y+1] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x+1, y+1);
                }
            }
            else if(this->color == BLACK)
            {
                if(ChessBoard[x+1][y+1] >= EMPTY)
                {
                    ChessBoardFlag[x+1][y+1] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x+1, y+1);
                }
            }
        }
        if((y >= 1&&this->color==RED)||(y >= 8&&this->color==BLACK)) //右下
        {
            if(this->color == RED)
            {
                if(ChessBoard[x+1][y-1] <= EMPTY)
                {
                    ChessBoardFlag[x+1][y-1] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x+1, y-1);
                }
            }
            else if(this->color == BLACK)
            {
                if(ChessBoard[x-1][y+1] >= EMPTY)
                {
                    ChessBoardFlag[x+1][y-1] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x+1, y-1);
                }
            }
        }
    }
}
//象类
void Elephant::moveTrack(cocos2d::Scene *scene,int mode)
{
    int x = this->cx;
    int y = this->cy;
    //左
    if(x >= 2)
    {
        if((y<=2&&this->color==RED)||(y<=7&&this->color==BLACK))//左上
        {
            if(this->color == RED)
            {
                if(ChessBoard[x-1][y+1]==EMPTY&&ChessBoard[x-2][y+2]<=EMPTY)
                {
                    ChessBoardFlag[x-2][y+2] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x-2, y+2);
                }
            }
            else if(this->color == BLACK)
            {
                if(ChessBoard[x-1][y+1]==EMPTY&&ChessBoard[x-2][y+2]>=EMPTY)
                {
                    ChessBoardFlag[x-2][y+2] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x-2, y+2);
                }
            }
        }
        if((y>=2&&this->color==RED)||(y>=7&&this->color==BLACK))//左下
        {
           if(this->color == RED)
           {
                if(ChessBoard[x-1][y-1]==EMPTY&&ChessBoard[x-2][y-2]<=EMPTY)
                {
                    ChessBoardFlag[x-2][y-2] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x-2, y-2);
                }
           }
           else if(this->color == BLACK)
           {
               if(ChessBoard[x-1][y-1]==EMPTY&&ChessBoard[x-2][y-2]>=EMPTY)
               {
                   ChessBoardFlag[x-2][y-2] = ChessBoard[x][y];
                   if(mode == 1)
                       addCanset(scene, x-2, y-2);
               }
           }
        }
        
    }
    //右
    if(x <= 6)
    {
        if((y<=2&&this->color==RED)||(y<=7&&this->color==BLACK))//右上
        {
            if(this->color == RED)
            {
                if(ChessBoard[x+1][y+1]==EMPTY&&ChessBoard[x+2][y+2]<=EMPTY)
                {
                    ChessBoardFlag[x+2][y+2] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x+2, y+2);
                }
            }
            else if(this->color == BLACK)
            {
                if(ChessBoard[x+1][y+1]==EMPTY&&ChessBoard[x+2][y+2]>=EMPTY)
                {
                    ChessBoardFlag[x+2][y+2] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x+2, y+2);
                }
            }
        }
        
        if((y>=2&&this->color==RED)||(y>=7&&this->color==BLACK))//右下
        {
            if(this->color == RED)
            {
                if(ChessBoard[x+1][y-1]==EMPTY&&ChessBoard[x+2][y-2]<=EMPTY)
                {
                    ChessBoardFlag[x+2][y-2] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x+2, y-2);
                }
            }
            else if(this->color == BLACK)
            {
                if(ChessBoard[x+1][y-1]==EMPTY&&ChessBoard[x+2][y-2]>=EMPTY)
                {
                    ChessBoardFlag[x+2][y-2] = ChessBoard[x][y];
                    if(mode == 1)
                        addCanset(scene, x+2, y-2);
                }
            }
        }
    }
}

void Pawn::moveTrack(cocos2d::Scene *scene,int mode)
{
    int x = this->cx;
    int y = this->cy;
    
    //前
    if(this->color == RED)
    {
        if(ChessBoard[x][y+1] <= EMPTY)
        {
            ChessBoardFlag[x][y+1] = ChessBoard[x][y];
            if(ChessBoard[x][y+1] == BKING)
                checkFlag = true;
            if(mode == 1)
                addCanset(scene, x, y+1);
        }
    }
    else if(this->color == BLACK)
    {
        if(ChessBoard[x][y-1] >= EMPTY)
        {
            ChessBoardFlag[x][y-1] = ChessBoard[x][y];
            if(ChessBoard[x][y-1] == RKING)
                checkFlag = true;
            if(mode == 1)
                addCanset(scene, x, y-1);
        }
    }
    //左
    if((this->color==RED&&y>=5)||(this->color==BLACK&&y<=4))
    {
        if(this->color == RED)
        {
            if(x>=1&&ChessBoard[x-1][y] <= EMPTY)
            {
                ChessBoardFlag[x-1][y] = ChessBoard[x][y];
                if(ChessBoard[x-1][y] == BKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, x-1, y);
            }
        }
        else if(this->color == BLACK)
        {
            if(x>=1&&ChessBoard[x-1][y] >= EMPTY)
            {
                ChessBoardFlag[x-1][y] = ChessBoard[x][y];
                if(ChessBoard[x-1][y] == RKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, x-1, y);
            }
        }
    }
    //右
    if((this->color==RED&&y>=5)||(this->color==BLACK&&y<=4))
    {
        if(this->color == RED)
        {
            if(x<=7&&ChessBoard[x+1][y] <= EMPTY)
            {
                ChessBoardFlag[x+1][y] = ChessBoard[x][y];
                if(ChessBoard[x+1][y] == BKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, x+1, y);
            }
        }
        else if(this->color == BLACK)
        {
            if(x<=7&&ChessBoard[x+1][y] >= EMPTY)
            {
                ChessBoardFlag[x+1][y] = ChessBoard[x][y];
                if(ChessBoard[x+1][y] == RKING)
                    checkFlag = true;
                if(mode == 1)
                    addCanset(scene, x+1, y);
            }
        }
    }
}
