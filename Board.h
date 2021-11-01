#ifndef _Board_H_
#define _Board_H_

class Board
{
public:
    void Display(const int (*bo)[15]);
    void ClearBoardArray(int (*bo)[15]);
    void Initiate(int (*bo)[15]);
};

class Judge
{
public:
    bool iswin(const int (*bo)[15]);
};

class GameManager
{
public:
    char SelectMode();
};

class PVP : public Board
{
public:
    void SetP1(int (*bo)[15], int (*hi)[3], int& np);
    void SetP2(int (*bo)[15], int (*hi)[3], int& np);
};

class PVE
{};
#endif