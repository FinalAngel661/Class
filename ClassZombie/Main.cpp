#include <cstdio>
#include <cstdlib>
#include "Zombie.h"


void main()
{
	
	const int Z_Count = 4;
	Zombie zombies[Z_Count];

	zombies[0].init("Sally", "Librarian");
	zombies[1].init("Milly", "Butcher");
	zombies[2].init("Sam", "Tailor");
	zombies[3].init("Junpei", "Baseball Player");

	printf("The Contestants are:\n");
	for (int i = 0; i < Z_Count; i++)
		zombies[i].draw(false);
	printf("\nLet the battle Begin!\n"); 

	bool gameOver = false;

	while (!gameOver)
	{
		printf("\nCombat Round: \n");
		for (int i = 0; i < Z_Count; i++)
			if (zombies[i].isAlive())
				zombies[rand() % Z_Count].takeDamage(zombies[i].rollAttack());

		for (int i = 0; i < Z_Count; i++)
			zombies[i].draw(true);

		int livingZombies = 0;
		for (int i = 0; i < Z_Count; i++)
			if (zombies[i].isAlive())
				livingZombies++;

		gameOver = (livingZombies == 1);
	}

	system("pause");

}