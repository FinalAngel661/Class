#include "GameManager.h"
#include "Zombie.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

void GameManager::init()
{
	zombies[0].init("Sally", "Librarian");
	zombies[1].init("Milly", "Butcher");
	zombies[2].init("Sam", "Tailor");
	zombies[3].init("Junpei", "Baseball Player");
}

void GameManager::Start()
{
	printf("The Contestants are:\n");
	drawStatus();
	printf("\nLet the battle Begin!\n");


}

void GameManager::drawStatus() const
{
	for (int i = 0; i < Z_Count; ++i)
		zombies[i].draw(false);
}

void GameManager::drawRound() const
{
	printf("\n###### Combat Round ######\n");
	for (int i = 0; i < Z_Count; ++i)
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


void GameManager::drawWinner() const
{
	printf("\n\n##### The battle is over!! #####\n");
	for (int i = 0; i < Z_Count; ++i)
		if (zombies[i].isAlive())
			zombies[i].draw(false);

	printf("The victor has emerged!");
}