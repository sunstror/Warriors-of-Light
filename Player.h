#pragma once
#include "Warrior.h"
#include <vector>
#include <string>
#include <memory>

class Player
{
public:
	std::vector<std::shared_ptr<Warrior>> team;
	std::string name;
	int chosenWarriorIndex;
	int warriorToHeal;
	int amountHeal;
	bool isDefeated;

	Player();
	bool hasMedic();
	void resetMedic();
	void heal();
	void listTeam();
	void getPlayerName();
	void chooseWarrior();
	void chooseWarriorHeal();
	void chooseHealAmount(int totalHeal, int remainingHealth, int maxHp);
	void removeDefeatedWarrior();
	void checkDefeatedWarrior();
};

