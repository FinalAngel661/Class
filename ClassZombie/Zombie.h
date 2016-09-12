#pragma once


class Zombie
{
private:
	char name[64], prior[64];
	int health, attack, critRate, kills;

public:
	void init(const char a_name[], const char a_occ[]);
	int rollAttack() const;
	void takeDamage(int dmg);
	void draw(bool breif) const;
	bool isAlive() const;

};