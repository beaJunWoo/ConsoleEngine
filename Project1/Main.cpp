#include "Astar.h"

int main()
{
	Astar astar;

	while (true)
	{
		system("cls");
		astar.StartSearch();
		astar.Move();
		astar.ShowMap();
		astar.Clear();
		Sleep(40);
	}
	


	return 0;
}