// SnakeGameWithC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<conio.h>
#include <Windows.h>
bool gameOver;
using namespace std;
const int width = 20;
const int height = 20;
int HeadPosX, HeadPosY, fruitX, fruitY,score;
int tailX[100], tailY[100];
int nTail;
enum eDirection{STOP=0,Left,Up,Right,Down};
eDirection dir;

//setup function
void setup()
{
	gameOver = false;
	dir = STOP;
	HeadPosX = width / 2;
	HeadPosY = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
//draw function
void draw()
{
	system("cls");
	for (int i = 0; i < width+2; i++)
	{
		cout << "#";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == HeadPosY && j == HeadPosX)
				cout << "O";
			else if(i==fruitY&&j==fruitX)
			{
				cout << "f";
			}
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "0";
						print = true;
					}
					
				}
				if (!print)
					cout << " ";
				
			}
				
			if (j == width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < width+2;  i++)
	{
		cout << "#";
	}
	cout << endl;

	cout << "SCORE" << score << endl;
}
//input Func
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = Left;
			break;
		case 'w':
			dir = Up;
			break;
		case 'd':
			dir = Right;
			break;
		case 's':
			dir = Down;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
//logic of the game 
void logic()
{
	int PrevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = HeadPosX;
	tailY[0] = HeadPosY;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = PrevX;
		tailY[i] = prevY;
		PrevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case Left:
		HeadPosX--;
		break;
	case Right:
		HeadPosX++;
		break;
	case Up:
		HeadPosY--;
		break;
	case Down:
		HeadPosY++;
		break;
	default:
		break;

	}
	if (HeadPosX > width || HeadPosX < 0||HeadPosX>height||HeadPosY<0)
	{
		gameOver = true;
	}
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == HeadPosX && tailY[i] == HeadPosY)
			gameOver = true;
	}
	if (HeadPosX == fruitX && HeadPosY == fruitY)
	{
		
		score += 1;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}

int main()
{
	setup();
	while (!gameOver)
	{
		draw();
		input();
		logic();
		Sleep(10);
	}
}


