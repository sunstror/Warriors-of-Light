#pragma once
#include "Warrior.h"
#include "Globals.h"
#include <string>

class Medic :
    public Warrior
{
public:
    Medic();
    void resetTotalHeal() { totalHeal = MAX_TOTAL_HEAL; }
};

