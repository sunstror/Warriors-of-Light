#include "Player.h"
#include "Medic.h"
#include "Berserker.h"
#include "Tank.h"
#include <iostream>
#include <sstream>
#include <string>


Player::Player() {

    team.push_back(std::make_shared<Berserker>());
    team.push_back(std::make_shared<Berserker>());
    team.push_back(std::make_shared<Tank>());
    team.push_back(std::make_shared<Tank>());
    team.push_back(std::make_shared<Medic>());

    isDefeated = false;
    chosenWarriorIndex = 0;
}
void Player::heal() {
    int totalHeal;
    for (auto iter : team) {
        if (iter->getType() == "Medic") {
           totalHeal = iter->getTotalHeal();
           bool done = false;
           while(totalHeal > 0 && !done){
               listTeam();
               std::cout << name << " has " << totalHeal << " hp of healing to use this round." << std::endl;
               chooseWarriorHeal();
               if (warriorToHeal >= 0) {
                   int maxHp;
                   std::string warriorType = team[warriorToHeal]->getType();
                   if (warriorType == "Tank") {
                       maxHp = 20;
                   }
                   else {
                       maxHp = 10;
                   }
                   int remainingHealth = team[warriorToHeal]->getHp();
                   chooseHealAmount(totalHeal, remainingHealth, maxHp);
                   team[warriorToHeal]->incrementHp(amountHeal);
                   totalHeal = totalHeal - amountHeal;
                   iter->setTotalHeal(totalHeal);
                   amountHeal = 0;
                   warriorToHeal = -1;
               }
               else {
                   done = true;
               }
           }          
        }
    }
    
    
}

bool Player::hasMedic() {
    for (auto iter : team) {
        if (iter->getType() == "Medic") {
            return true;
        }
    }
    return false;
}

void Player::resetMedic() {
    for (auto iter : team) {
        if (iter->getType() == "Medic") {
            iter->resetTotalHeal();
        }
    }
}

void Player::listTeam() {
    int index = 1;
    for (auto warrior : team) {
        std::cout << index << ") " << warrior->getType() << "(" << warrior->getHp() << "hp)" << std::endl;
        index++;
    }
}

void Player::removeDefeatedWarrior() {
    std::vector<std::shared_ptr<Warrior>>::iterator iter;
    for (iter = team.begin(); iter != team.end();) {
        if((*iter)->getHp() <= 0) {
            iter = team.erase(iter);
        }
        else {
            iter++;
        }
    }
}

void Player::checkDefeatedWarrior() {
    isDefeated = false;
    for (auto warrior : team) { 
        if (warrior->getHp() <= 0) {
            isDefeated = true;
        }
    }
}

void Player::getPlayerName() {
    std::getline(std::cin, name);
}

void Player::chooseWarrior() {
    bool warriorSelected = false;
    while (!warriorSelected) {
        std::cout << name << ", please type the number of the warrior you want to choose for battle: " << std::endl;
        std::string warriorString; 
        std::getline (std::cin, warriorString);
        bool isNum = true;
        for (auto elem : warriorString) {
            if (!std::isdigit(elem)) {
                isNum =  false;                
            }
        }
        if (isNum) {
            int warriorNum;
            std::stringstream ss;
            ss << warriorString;
            ss >> warriorNum;
            if (warriorNum <= team.size() && warriorNum > 0) {
                warriorSelected = true;
                chosenWarriorIndex = warriorNum - 1;
            }
            else {
                std::cout << "That number is not in the correct range. Please enter a number from 1 to " << team.size() << std::endl;
            }
        }
        else {
            std::cout << "That is not a number. Please try again." << std::endl;
        }
    }   
}

void Player::chooseWarriorHeal() {
    bool warriorSelected = false;
    while (!warriorSelected) {
        std::cout << "Enter number of warrior you want to heal. Enter 0 if you don't wish to heal at this time." << std::endl;
        std::string warriorString;
        std::getline(std::cin, warriorString);
        bool isNum = true;
        for (auto elem : warriorString) {
            if (!std::isdigit(elem)) {
                isNum = false;
            }
        }
        if (isNum) {
            int warriorNum;
            std::stringstream ss;
            ss << warriorString;
            ss >> warriorNum;
            if (warriorNum <= team.size() && warriorNum >= 0) {
                warriorSelected = true;
                warriorToHeal = warriorNum - 1;
            }
            else {
                std::cout << "That number is not in the correct range. Please enter a number from 1 to " << team.size() << ". Enter 0 if you do not want to heal." << std::endl;
            }
        }
        else {
            std::cout << "That is not a number. Please try again." << std::endl;
        }
    }
}

void Player::chooseHealAmount(int totalHeal, int healthRemaining, int maxHp) {
    
    bool healSelected = false;
    while (!healSelected) {
        std::cout << "How much healing do you want to use? You have " << totalHeal << " available. Enter 0 if you do not want to heal." << std::endl;
        std::string healString;
        std::getline(std::cin, healString);
        bool isNum = true;
        for (auto elem : healString) {
            if (!std::isdigit(elem)) {
                isNum = false;
            }
        }
        if (isNum) {
            int healNum;
            std::stringstream ss;
            ss << healString;
            ss >> healNum;
            if (healthRemaining + healNum <= maxHp) {
                if (healNum <= totalHeal && healNum >= 0) {
                    healSelected = true;
                    amountHeal = healNum;
                }
                else {
                    std::cout << "That number is not in the correct range. Please enter a number from 0 to " << totalHeal << "." << std::endl;
                }
            }
            else {
                std::cout << "You can't heal more than the max hp of 20 for a Tank and 10 for the other warrior types. Try again" << std::endl;
            }
                
        }
        else {
            std::cout << "That is not a number. Please try again." << std::endl;
        }
    }
}