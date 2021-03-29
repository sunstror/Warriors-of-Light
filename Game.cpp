#include "Game.h"
#include "Berserker.h"
#include "Medic.h"
#include "Tank.h"
#include <iostream>

using std::cout;
using std::endl;

void Game::handleRound() {
    int battleNum = 1;

    if (player1.hasMedic()) {
        player1.resetMedic();
    }
    if (player2.hasMedic()) {
        player2.resetMedic();
    }
    cout << "Welcome to Round " << roundNumber << endl << endl;
    while (battleNum <= NUM_BATTLES_IN_ROUND) {
        std::cout << endl << endl;
        std::cout << "Prepare for Battle #" << battleNum << std::endl;
        player1.listTeam();
        player1.chooseWarrior();

        std::cout << endl << endl;
        player2.listTeam();
        player2.chooseWarrior();
        
        std::cout << endl << endl;
        handleBattle(player1.team[player1.chosenWarriorIndex], player2.team[player2.chosenWarriorIndex]);
        if (gameOver) {
            break;
        }
        std::cout << endl << endl;
        player1.heal();

        std::cout << endl << endl;
        player2.heal();
        battleNum++;
    }
    roundNumber++;
}

void Game::handleBattle(std::shared_ptr<Warrior> warrior1, std::shared_ptr<Warrior> warrior2){
    bool battleFinished = false;
    while (!battleFinished) {
        battle(warrior1, warrior2);
        player1.checkDefeatedWarrior();
        player2.checkDefeatedWarrior();
        if (player1.isDefeated) {
            cout << player2.name << "'s " << warrior2->getType() << " defeated " << player1.name << "'s " << warrior1->getType() << std::endl;           
            player1.removeDefeatedWarrior();
            battleFinished = true;
            cout << endl << endl;
        }
        else if (player2.isDefeated) {
            cout << player1.name << "'s " << warrior1->getType() << " defeated " << player2.name << "'s " << warrior2->getType() << std::endl;
            player2.removeDefeatedWarrior();
            battleFinished = true;
            cout << endl << endl;
        }
    }
    checkForGameOver();
}

void Game::battle(std::shared_ptr<Warrior> warrior1, std::shared_ptr<Warrior> warrior2) {
    int damage;
    Warrior* warrior;
    if (warrior1->attack() > warrior2->attack()) {
        damage = warrior1->calculateDamage();
        cout << player1.name << "'s " << warrior1->getType() << " dealt "<< damage <<  " damage to " << player2.name << "'s " << warrior2->getType() << std::endl;
        warrior2->decrementHp(damage);
    }
    else {
        damage = warrior2->calculateDamage();
        cout << player2.name << "'s " << warrior2->getType() << " dealt " << damage << " damage to " << player1.name << "'s " << warrior1->getType() << std::endl;
        warrior1->decrementHp(damage);
    }
}

void Game::run() {
    cout << "Welcome to Warriors of Light where you and your team battle your way to glory. Each team consists of 2 Berserkers, 2 Tanks, and 1 Medic. " << endl;
    cout << "Berserkers use the power of the red spectrum of light. This gives them increased strength which causes them to deal up to double normal damage." << endl;
    cout << "Tanks use the power of the green spectrum of light. This increases the tanks body density which allows them to take double the damage of a normal warrior" << endl;
    cout << "Medics use the power of the blue spectrum of light and have the ability to heal up to 5 hp of damage divided (as wished) among team members each round." << endl;
    cout << "Hit Enter to continue: " << endl  << endl;
    std::cin.get();
    
    cout << "Player 1, please enter your name: " << endl;
    player1.getPlayerName();
    cout << "Hit Enter to continue: " << endl;
    std::cin.get();

    cout << "Player 2, please enter your name: " << endl;
    player2.getPlayerName();
    cout << "Hit Enter to continue: " << endl;
    std::cin.get();

    while (!gameOver) {
        handleRound();
    }
}

void Game::checkForGameOver() {
    if (player1.team.empty()) {
        cout << endl << endl;
        cout << "Congratulations, " << player2.name << " is the winner!" << endl;
        gameOver = true;
    }
    else if (player2.team.empty()) {
        cout << endl << endl;
        cout << "Congratulations, " << player1.name << " is the winner!" << endl;
        gameOver = true;
    }
}


