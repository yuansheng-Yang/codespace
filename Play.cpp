#include<iostream>
#include"Board.h"
#include"Board.cpp"
int myBoard[15][15];//15 * 15 board
int history[225][3];//storage coordinate of each round
int np = 0;//number of pieces on board

int main()
{
    Board board;
    GameManager gm;
    PVP pvp;
    Judge judger;
    
    //Initiate and display board
    board.Initiate(myBoard);
    
    //Select game mode and enjoy game
    char mode = gm.SelectMode();//Select mode
    
    if('1' == mode)//PVP mode
    {
        while(1)
        {
            pvp.SetP1(myBoard, history, np);//P1 lays black piece down
            if(judger.iswin(myBoard))//winner judgement
            {
                std::cout << "\nP1(Black) Win!\n";
                break;
            }
            
            pvp.SetP2(myBoard, history, np);//P2 lays white piece down
            if(judger.iswin(myBoard))//winner judgement
            {
                std::cout << "\nP2(White) Win!\n";
                break;
            }
        }
    }
    
    else if('2' == mode)//PVE mode
    {

    }
    return 0;
}