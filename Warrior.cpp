#include "Warrior.h"
#include "Globals.h"
#include <stdlib.h>
#include <iostream>

int Warrior::attack() {
	int attack = rand() % MAX_ATTACK_NUM + 1;
	return attack;
}

int Warrior::calculateDamage()
{
	int damage = rand() % MAX_DAMAGE + 1;
	return damage;
}

