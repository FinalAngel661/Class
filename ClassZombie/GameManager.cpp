#include "GameManager.h"
#include "Zombie.h"

void GameManager::init()
{
	zombies[0].init("Sally", "Librarian");
	zombies[1].init("Milly", "Butcher");
	zombies[2].init("Sam", "Tailor");
	zombies[3].init("Junpei", "Baseball Player");
}

void GameManager::start()
{
	printf("The Contestants are:\n");
	drawStatus();
	printf("\nLet the battle Begin!\n");


}


void GameManager::drawStatus() const
{
	for (int i = 0; i < Z_Count; i++)
		zombies[i].draw(true);
}

void GameManager::update()
{
	for (int i = 0; i < Z_Count; i++)
		if (zombies[i].isAlive())
			zombies[rand() % Z_Count].takeDamage(zombies[i].rollAttack());
}

bool GameManager::isGameOver() const
{
	int livingZombies = 0;
	for (int i = 0; i < Z_Count; i++)
		if (zombies[i].isAlive())
			livingZombies++;

	return livingZombies == 1;
}