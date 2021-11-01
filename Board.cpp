#include<iostream>
#include"Board.h"

bool Judge::iswin(const int (*bo)[15])
{
	int i, j;
	for(i = 0; i < 15; ++i)
	{
		for(j = 0; j < 15 ; ++j)
		{
			//horizontal
			if
			(
				(j < 11)  
				&& 
				(
					   (50 == (bo[i][j] + bo[i][j+1] + bo[i][j+2] + bo[i][j+3] + bo[i][j+4]))
					|| (51 == (bo[i][j] + bo[i][j+1] + bo[i][j+2] + bo[i][j+3] + bo[i][j+4]))
					|| (100 == (bo[i][j] + bo[i][j+1] + bo[i][j+2] + bo[i][j+3] + bo[i][j+4]))
					|| (101 == (bo[i][j] + bo[i][j+1] + bo[i][j+2] + bo[i][j+3] + bo[i][j+4]))
				)
				&&((10 <= bo[i][j]) && (bo[i][j] <= 21))
				&&((10 <= bo[i][j+1]) && (bo[i][j+1] <= 21))
				&&((10 <= bo[i][j+2]) && (bo[i][j+2] <= 21))
				&&((10 <= bo[i][j+3]) && (bo[i][j+3] <= 21))
				&&((10 <= bo[i][j+4]) && (bo[i][j+4] <= 21))
			)
				return true;

			//vertical
			if
			(
				(i < 11)  
				&& 
				(
					   (50 == (bo[i][j] + bo[i+1][j] + bo[i+2][j] + bo[i+3][j] + bo[i+4][j]))
					|| (51 == (bo[i][j] + bo[i+1][j] + bo[i+2][j] + bo[i+3][j] + bo[i+4][j]))
					|| (100 == (bo[i][j] + bo[i+1][j] + bo[i+2][j] + bo[i+3][j] + bo[i+4][j]))
					|| (101 == (bo[i][j] + bo[i+1][j] + bo[i+2][j] + bo[i+3][j] + bo[i+4][j]))
				)
				&&((10 <= bo[i][j]) && (bo[i][j] <= 21))
				&&((10 <= bo[i+1][j]) && (bo[i+1][j] <= 21))
				&&((10 <= bo[i+2][j]) && (bo[i+2][j] <= 21))
				&&((10 <= bo[i+3][j]) && (bo[i+3][j] <= 21))
				&&((10 <= bo[i+4][j]) && (bo[i+4][j] <= 21))
			)
				return true;

			//45 degree
			if
			(
				((i <= 10) && (j >= 4))  
				&& 
				(
					   (50 == (bo[i][j] + bo[i+1][j-1] + bo[i+2][j-2] + bo[i+3][j-3] + bo[i+4][j-4]))
					|| (51 == (bo[i][j] + bo[i+1][j-1] + bo[i+2][j-2] + bo[i+3][j-3] + bo[i+4][j-4]))
					|| (100 == (bo[i][j] + bo[i+1][j-1] + bo[i+2][j-2] + bo[i+3][j-3] + bo[i+4][j-4]))
					|| (101 == (bo[i][j] + bo[i+1][j-1] + bo[i+2][j-2] + bo[i+3][j-3] + bo[i+4][j-4]))
				)
				&&((10 <= bo[i][j]) && (bo[i][j] <= 21))
				&&((10 <= bo[i+1][j-1]) && (bo[i+1][j-1] <= 21))
				&&((10 <= bo[i+2][j-2]) && (bo[i+2][j-2] <= 21))
				&&((10 <= bo[i+3][j-3]) && (bo[i+3][j-3] <= 21))
				&&((10 <= bo[i+4][j-4]) && (bo[i+4][j-4] <= 21))
			)
				return true;

			//-45 degree
			if
			(
				((i <= 10) && (j <= 10))  
				&& 
				(
					   (50 == (bo[i][j] + bo[i+1][j+1] + bo[i+2][j+2] + bo[i+3][j+3] + bo[i+4][j+4]))
					|| (51 == (bo[i][j] + bo[i+1][j+1] + bo[i+2][j+2] + bo[i+3][j+3] + bo[i+4][j+4]))
					|| (100 == (bo[i][j] + bo[i+1][j+1] + bo[i+2][j+2] + bo[i+3][j+3] + bo[i+4][j+4]))
					|| (101 == (bo[i][j] + bo[i+1][j+1] + bo[i+2][j+2] + bo[i+3][j+3] + bo[i+4][j+4]))
				)
				&&((10 <= bo[i][j]) && (bo[i][j] <= 21))
				&&((10 <= bo[i+1][j+1]) && (bo[i+1][j+1] <= 21))
				&&((10 <= bo[i+2][j+2]) && (bo[i+2][j+2] <= 21))
				&&((10 <= bo[i+3][j+3]) && (bo[i+3][j+3] <= 21))
				&&((10 <= bo[i+4][j+4]) && (bo[i+4][j+4] <= 21))
			)
				return true;
		}
	}
	return false;
}

void PVP::SetP1(int (*bo)[15], int (*hi)[3], int& np)
{
	//std::cout << np << std::endl;
	char x[2];
	int i, j;
	if(np >= 2)
	std::cout << "To replay last round, input .b\n";
	std::cout << "P1(Black): ";
	std::cin >> x[0] >> x[1];
	
	if((np >= 2) && ('.' == x[0]) && ('b' == x[1]))//.b inputed, replay last round
	{
		bo[hi[np-1][0]][hi[np-1][1]] = hi[np-1][2];
		bo[hi[np-2][0]][hi[np-2][1]] = hi[np-2][2];
		np -= 2;
		if(2 <= np)
		{
			bo[hi[np-1][0]][hi[np-1][1]] += 1;
			bo[hi[np-2][0]][hi[np-2][1]] += 1;
		}
		Display(bo);
		if(0 == np)
		ClearBoardArray(bo);
		SetP1(bo, hi, np);
		return;
		//return false;
	}
	
	if(('0' <= x[0]) && (x[0] <= '9'))
	i = x[0] - '0';
	if(('u' <= x[0]) && (x[0] <= 'y'))
	i = x[0] - 'u' + 10;
	
	j = x[1] - 'a';
	
	if((10 != bo[i][j]) && (20 != bo[i][j]) && (11 != bo[i][j]) && (21 != bo[i][j]))
	{
		hi[np][2] = bo[i][j];
		bo[i][j] = 10;
		hi[np][0] = i;
		hi[np][1] = j;
		np++;
		bo[hi[np-1][0]][hi[np-1][1]] += 1;
		if(3 <= np)
		bo[hi[np-3][0]][hi[np-3][1]] -= 1;
		Display(bo);
	}
	else{
		std::cout << "Position Occupied! Retry\n";
		//SetP1(bo, hi, np);
	}
}

void PVP::SetP2(int (*bo)[15], int (*hi)[3], int& np)
{
	//std::cout << np << std::endl;
	char x[2];
	int i, j;
	if(np >= 2)
	std::cout << "To replay last round, input .b\n";
	std::cout << "P2(White): ";
	std::cin >> x[0] >> x[1];
	
	if((np >= 2) && ('.' == x[0]) && ('b' == x[1]))//.b inputed, replay last round
	{
		bo[hi[np-1][0]][hi[np-1][1]] = hi[np-1][2];
		bo[hi[np-2][0]][hi[np-2][1]] = hi[np-2][2];
		np -= 2;
		if(2 <= np)
		{
			bo[hi[np][0]][hi[np][1]] += 1;
			bo[hi[np-1][0]][hi[np-1][1]] += 1;
		}
		Display(bo);
		if(0 == np)
		ClearBoardArray(bo);
		SetP2(bo, hi, np);
		return;
		//return false;
	}
	
	if(('0' <= x[0]) && (x[0] <= '9'))
	i = x[0] - '0';
	if(('u' <= x[0]) && (x[0] <= 'y'))
	i = x[0] - 'u' + 10;
	
	j = x[1] - 'a';

	if((10 != bo[i][j]) && (20 != bo[i][j]) && (11 != bo[i][j]) && (21 != bo[i][j]))
	{
		hi[np][2] = bo[i][j];
		bo[i][j] = 20;
		hi[np][0] = i;
		hi[np][1] = j;
		np++;
		bo[hi[np-1][0]][hi[np-1][1]] += 1;
		if(3 <= np)
		bo[hi[np-3][0]][hi[np-3][1]] -= 1;
		Display(bo);
	}
	else{
		std::cout << "Position Occupied! Retry\n";
		//SetP2(bo, hi, np);
	}
}

char GameManager::SelectMode()
{
	std::cout << "\nPlease select game mode：\n" << "inout \"1\":PVP\n" << "input \"2\":PVE\n";
	std::cout << "input here: ";
	char a;
	std::cin >> a;
	if(a == '1'){
		std::cout << "\nPVP Game Start!\n\n";
		return a;
	}

	else if(a == '2'){
		std::cout << "\nPVE Game Start!\n\n";
		return a;
	}
}

void Board::Initiate(int (*bo)[15])
{
	ClearBoardArray(bo);
    Display(bo);
}

void Board::Display(const int (*bo)[15]) //画棋盘
{	
	system("cls"); 
    system("color f0");
	
	int i, j;

	for(i = 0; i <= 14; i++)
	{
		if(i < 10)
		std::cout << i;
		else
		std::cout << (char)('u' + i - 10);
		for(j = 0; j <= 14; j++)
		{
			switch(bo[i][j] % 100)//%100为了适应将来有分值的情形
			{
			case 1:
				std::cout << "┏ ";
				break;

			case 2:
				std::cout << "┓";
				break;

			case 3:
				std::cout << "┛";
				break;

			case 4:
				std::cout << "┗ ";
				break;

			case 5:
				std::cout << "┠ ";
				break;

			case 6:
				std::cout << "┯ ";
				break;

			case 7:
				std::cout << "┨";
				break;

			case 8:
				std::cout << "┷ ";
				break;

			case 9:
				std::cout << "┼ ";
				break;

			case 10:
				std::cout << "●";
				break;

			case 11:
				std::cout << "▲";
				break;

			case 20:
				std::cout << "○";
				break;

			case 21:
				std::cout << "△";
				break;
			}
			if (j == 14)
			{
				std::cout << "\n";
			}
		}
	}
	std::cout << "  a b c d e f g h i j k l m n o\n";
}

void Board::ClearBoardArray(int (*bo)[15])
{
	int i, j; //i＝行，j＝列

	bo[0][0] = 1;
	bo[0][14] = 2;
	bo[14][14] = 3;
	bo[14][0] = 4;

	for (i = 1; i <= 13; i++)
	{
		bo[i][0] = 5;
	}
	
	for (i = 1; i <= 13; i++)
	{
		bo[i][14] = 7;
	}
	
	for (j = 1; j <= 13; j++)
	{
		bo[0][j] = 6;
	}
	for (j = 1; j <= 13; j++)
	{
		bo[14][j] = 8;
	}

	for (i = 1; i <= 13; i++)
	{
		for (j = 1; j <= 13; j++)
		{
			bo[i][j] = 9;
		}
	}
}
