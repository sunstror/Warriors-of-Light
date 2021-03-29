#pragma once
#include <string>
#include "Globals.h"
class Warrior
{	
public:
	int attack();
	virtual int calculateDamage();
	virtual void resetTotalHeal() { totalHeal = 0; }

	int getHp() { return hp; }
	void setHp(int hp) { this->hp = hp; }
	int getTotalHeal() { return totalHeal; }
	void setTotalHeal(int heal) { totalHeal = heal; }
	void decrementHp(int damage) { hp = hp - damage; }
	void incrementHp(int healing) { hp = hp + healing; }
	std::string getType() { return type; } 
	
protected:
	int hp = MAX_HEALTH;
	int totalHeal = 0;
	std::string type;
};

