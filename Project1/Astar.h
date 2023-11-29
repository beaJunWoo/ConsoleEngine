#pragma once
#include "Header.h"
#include "PriorityQueue.h"
#include "math.h"

#define Right nowPos.X+1
#define Left nowPos.X-1
#define Up nowPos.Y-1
#define Down nowPos.Y+1

class Astar
{
	int map[20][20]=
	{
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	};
	COORD startPos;
	COORD endPos;
	COORD control;
	PriorityQueue p_queue;
	Node* firstNode;
public:
	Astar()
	{
		control = { 1,1 };
		startPos = { 2,8 };
		endPos = { 15,5 };
	}
	void StartSearch()
	{
		Search(startPos ,0);
	}
	int Geth(int x, int y)
	{
		
		int GabX = abs(endPos.X - x);
		int GabY = abs(endPos.Y - y);
		if (GabX > GabY)
		{
			return GabY * 14 + (GabX - GabY) * 10;
		}
		else
		{
			return GabX * 14 + (GabY + GabX) * 10;
		}
	}
	void PushQueue(COORD nowPos, int g)
	{
		if (map[Down][nowPos.X] == 0)
		{
			p_queue.Push(nowPos.X, Down, Geth(nowPos.X, Down), g + 10);
		}
			

		if (map[Up][nowPos.X] == 0)
			p_queue.Push(nowPos.X, Up, Geth(nowPos.X, Up), g + 10);

		if (map[nowPos.Y][Left] == 0)
			p_queue.Push(Left, nowPos.Y, Geth(Left, nowPos.Y), g + 10);

		if (map[nowPos.Y][Right] == 0)
			p_queue.Push(Right, nowPos.Y, Geth(Right, nowPos.Y), g + 10);

		if (map[Up][Left] == 0)
			p_queue.Push(Left, Up, Geth(Left, Up), g + 14);

		if (map[Up][Right] == 0)
			p_queue.Push(Right, Up, Geth(Right, Up), g + 14);

		if (map[Down][Left] == 0)
			p_queue.Push(Left, Down, Geth(Left, Down), g + 14);

		if (map[Down][Right] == 0)
			p_queue.Push(Right, Down, Geth(Right, Down), g + 14);
	}
	void Search(COORD nowPos, int g)
	{
		PushQueue(nowPos, g);

		Node node = p_queue.Pop();
		map[node.y][node.x] = -1;

		COORD nextIdx = { node.x, node.y };
		if (node.h != 0)
		{
			Search(nextIdx, node.g);
			
		}
		
		
	}
	void SetPosition(int x, int y)
	{
		COORD pos;
		pos.X = x * 2;
		pos.Y = y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	void SetColor(int color)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}
	void ShowMap()
	{
		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{

				SetPosition(x, y);
				if (control.X == x && control.Y == y)
				{
					SetColor(GREEN);
					cout << "бс";
					continue;
				}
				else if (startPos.X == x && startPos.Y == y)
				{
					SetColor(CYAN);
					cout << "бс";
				}
				else if (endPos.X == x && endPos.Y == y)
				{
					SetColor(CYAN);
					cout << "бс";
				}
				else
				{
					switch (map[y][x])
					{
					case -1:
						SetColor(RED);
						cout << "бс";
						break;
					case 0:
						SetColor(WHITE);
						cout << "бр";
						break;
					case 1:
						SetColor(WHITE);
						cout << "бс";
						break;
					default:
						break;
					}
				}
			}
		}
	}
	void Clear()
	{
		while (!p_queue.IsEmpty())
		{
			p_queue.Pop();
		}
		for (int y = 1; y < 19; y++)
		{
			for (int x = 1; x < 19; x++)
			{
				if (map[y][x] != 1)
				{
					map[y][x] = 0;
				}	
			}
		}
	}
	void Move()
	{
		if (GetAsyncKeyState(VK_RIGHT))
		{
			control.X++;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			control.X--;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			control.Y--;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			control.Y++;
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			map[control.Y][control.X] = 1;
		}
	}
};

