/* Calvin Aduma
 * CPSC 1071:001
 * Code Blooded
 * 03/31/2023
 */

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "DeckOfCards.h"

using namespace std;

class Game {
    public:
        DeckOfCards playerDeck;
        DeckOfCards computerDeck;
        Game();
        void runGame();
        void runMenu();
        void runTurnByTurn();
        void runSimulation();
};

#endif