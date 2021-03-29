#include <iostream>
#include "Warrior.h"
#include "Berserker.h"
#include "Medic.h"
#include "Tank.h"
#include "Player.h"
#include "Game.h"
#include <ctime>
#include <vector>


using std::cout;
using std::endl;
using std::vector;

void listTeam(vector<Warrior>& team) {
    int index = 1;
    for (Warrior warrior : team) {
        cout << index << ") " << warrior.getType() << "(" << warrior.getHp() << " hp)" << endl;
        index++;
    }
}

bool checkVictoryCondition(vector<Warrior>& team) {
    if (team.empty()) {
        return true;
    }
    else {
        return false;
    }
}

void initTeam(vector<Warrior> &team) {
    Berserker berserker1;
    Berserker berserker2;
    Tank tank1;
    Tank tank2;
    Medic medic;

    team.push_back(berserker1);
    team.push_back(berserker2);
    team.push_back(tank1);
    team.push_back(tank2);
    team.push_back(medic);
}

void battle(Warrior &warrior1, Warrior &warrior2) {
    int damage;
    if (warrior1.attack() > warrior2.attack()) {
        damage = warrior1.calculateDamage();
        warrior2.decrementHp(damage);
    }
    else {
        damage = warrior2.calculateDamage();
        warrior1.decrementHp(damage);
    }
}

bool isDefeated(Warrior &warrior) {
    if (warrior.getHp() <= 0) {
        return true;
    }
    else {
        return false;
    }
}

void removeDefeatedWarrior(vector<Warrior> &team) {
    for (auto iter = team.begin(); iter != team.end();) {
        if (isDefeated(*iter)) {
            iter = team.erase(iter);
        }
        else {
            iter++;
        }
    }
}

int main()
{
    srand((unsigned)time(0));
       
    Game game;
    game.run();

    return 0;
 }

