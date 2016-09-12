#include <cstdio>
#include <cstdlib>
#include "GameManager.h"


void main()
{
	
	GameManager gs;
	gs.init();

	while (!gs.isGameOver())
	{

		gs.update();
		gs.drawRound();
	}

	gs.drawWinner();

	system("pause");

}