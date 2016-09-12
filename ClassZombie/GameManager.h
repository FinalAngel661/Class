#pragma once


#include "Zombie.h"

class GameManager
{
	const int Z_count = 4;
	Zombie zombies[4];

public:
	void init();
	void update();
	void drawStatus() const;
	void drawRound() const;
	void draw() const;
	bool isGameOver() const;


};