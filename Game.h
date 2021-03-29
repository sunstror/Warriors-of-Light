#pragma once
#include "Player.h"
#include "Warrior.h"

class Game
{
public:
	bool gameOver = false;
	int roundNumber = 1;

	Player player1;
	Player player2;
	
	void run();
	void checkForGameOver();
	void handleRound();
	void handleBattle(std::shared_ptr<Warrior> warrior1, std::shared_ptr<Warrior> warrior2);
	void battle(std::shared_ptr<Warrior> warrior1, std::shared_ptr<Warrior> warrior2);
};

