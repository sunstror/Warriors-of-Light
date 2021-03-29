#pragma once
#include "Warrior.h"
#include <string>
class Berserker :
    public Warrior
{
public:
    Berserker();
    int calculateDamage();
};

