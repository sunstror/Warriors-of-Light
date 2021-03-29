#include "Berserker.h"
#include "Globals.h"

Berserker::Berserker() {
	type = "Berserker";
}

int Berserker::calculateDamage() {
	int damage = rand() % MAX_BERSERKER_DAMAGE + 1;
	return damage;
}