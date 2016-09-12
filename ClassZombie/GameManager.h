#pragma once


#include "Zombie.h"

class GameManager
{
	const int Z_Count = 4;
	Zombie zombies[4];

public:
	void init();
	void update();
	void Start();
	void drawStatus() const;
	void drawRound() const;
	bool isGameOver() const;
	void drawWinner() const;


};