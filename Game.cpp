/* Calvin Aduma
 * CPSC 1071:001
 * Code Blooded
 * 03/31/2023
 */

#include <iostream>
#include "Game.h"
#include "DeckOfCards.h"
#include <unistd.h>
#include <string>

using namespace std;

void enterKeyCheck();
void gameScreen(DeckOfCards&,DeckOfCards&);
void tieGame(DeckOfCards &, vector<Card> &, DeckOfCards &, vector<Card> &);
void playerGameTie(DeckOfCards &, DeckOfCards &, vector<Card>);
void computerGameTie(DeckOfCards &, DeckOfCards &, vector<Card>);
void playerGame(DeckOfCards &, DeckOfCards &, vector<Card>);
void computerGame(DeckOfCards &, DeckOfCards &, vector<Card>);

Game::Game(){
    computerDeck.shuffle();
    // shuffle 3 times to have different deck than computer
    playerDeck.shuffle();
    playerDeck.shuffle();
    playerDeck.shuffle();
}

void Game::runGame(){
    string gameType;
    runMenu();
    cin >> gameType;

    // initial game startup
    while(gameType != "1" && gameType != "2" && gameType != "3"){
    cout << "Invlaid choice. Try Again";
    runMenu();
    cin >> gameType;
    }

    // exits if 3 selected
    if (gameType == "3"){
    cout << "Exiting..." << endl;
    exit(0);
    }

    // check if enter key is pressed
    enterKeyCheck();

    // start of game
    int newGameType;
    if(gameType == "1") newGameType = 1;
    else newGameType = 2;

    switch(newGameType){
        case 1: // turn by turn simulation
        {
            runTurnByTurn();
            break;
        }
        case 2:
        {
            runSimulation();
            break;
        }
    }
}

// displays menu
void Game::runMenu(){
    cout << "\nWelcome to the game of RAW!\n";
    cout << "1. Play the game turn by turn\n";
    cout << "2. Simulate the game\n";
    cout << "3. Quit\n";
    cout << "Enter your choice: ";
}

// plays option 1
void Game::runTurnByTurn(){
    while(playerDeck.size() > 27 && computerDeck.size() > 27){
        gameScreen(computerDeck, playerDeck);
        enterKeyCheck();
        playerDeck.setCurrentCard(0);
        computerDeck.setCurrentCard(0);
    }
    if (playerDeck.size() > computerDeck.size()) cout << "Computer wins the game!" << endl;
    else cout << "Player wins the game!" << endl;
}

// plays option 2
void Game::runSimulation(){
    while(playerDeck.size() > 27 && computerDeck.size() > 27){
        gameScreen(computerDeck, playerDeck);
        usleep(3000000);
        playerDeck.setCurrentCard(0);
        computerDeck.setCurrentCard(0);
    }
    if (playerDeck.size() > computerDeck.size()) cout << "Computer wins the game!" << endl;
    else cout << "Player wins the game!" << endl;
}

// checks to make sure key entered is the [ENTER] key
void enterKeyCheck(){
  cout << "Press [Enter] key to play a turn\n" << endl;
  while(cin.get() != '\n'){
    cout << "Invalid key!" << endl;
    cout << "Press [Enter] key to play a turn\n" << endl;
  }
}

// game screen for both turn-by-turn and simulation
void gameScreen(DeckOfCards &comp,DeckOfCards &play){
  vector<Card> dealtPlayerCards;
  vector<Card> dealtComputerCards;
  dealtPlayerCards.push_back(play.dealCard());
  dealtComputerCards.push_back(comp.dealCard());
  cout << "Player: " << dealtPlayerCards.back().toString() << " | Number of cards in Deck: " << play.size() << endl;
  cout << "Computer: " << dealtComputerCards.back().toString() << " | Number of cards in Deck: " << comp.size() << endl;

  if(dealtPlayerCards.back().face == dealtComputerCards.back().face){ 
    // tie
    tieGame(comp, dealtComputerCards, play, dealtPlayerCards);
    if (dealtPlayerCards.back().face == dealtComputerCards.back().face){ 
      // if tie again, keep repeating
      while (dealtPlayerCards.back().face == dealtComputerCards.back().face){
        tieGame(comp, dealtComputerCards, play, dealtPlayerCards);
      }
      // once out of tie
      if(dealtPlayerCards.back().face != 0 && (dealtPlayerCards.back().face < dealtComputerCards.back().face || dealtComputerCards.back().face == 0)){
        // player wins
        playerGameTie(play, comp, dealtComputerCards);
      } else {
        // computer wins
        computerGameTie(comp, play, dealtPlayerCards);
      }
    } else if(dealtPlayerCards.back().face != 0 && (dealtPlayerCards.back().face < dealtComputerCards.back().face || dealtComputerCards.back().face == 0)){ 
      // player wins
      playerGameTie(play, comp, dealtComputerCards);
    } else {
      // computer wins
      computerGameTie(comp, play, dealtPlayerCards);
    }
  } else if(dealtPlayerCards.back().face != 0 && (dealtPlayerCards.back().face < dealtComputerCards.back().face || dealtComputerCards.back().face == 0)){
    // player wins
    playerGame(play, comp, dealtComputerCards);
  } else {
    // computer wins
    computerGame(comp, play, dealtPlayerCards);
  }
}

// tie game algorithm
void tieGame(DeckOfCards &comp, vector<Card> &dComp, DeckOfCards &play, vector<Card> &dPlay){
  for(int i=0; i<4; i++){ // deals 4 cards to both sides
    dPlay.push_back(play.dealCard());
    dComp.push_back(comp.dealCard());
  }
}

// algorithm for if player wins during a tie
void playerGameTie(DeckOfCards &play, DeckOfCards &comp, vector<Card> dComp){
  cout << "\nPlayer wins the turn, collecting all the cards!" << endl;
  play.addCard(dComp); // adds comp cards to player deck
  Card temp = play.deck.front();
  play.deck.push_back(temp);
  play.deck.erase(play.deck.begin(), play.deck.begin()+1); // erases the front card
  comp.deck.erase(comp.deck.begin(), comp.deck.begin()+dComp.size()); // erases the lost cards and resets size of deck
}

// algorithm for if computer wins during a tie
void computerGameTie(DeckOfCards &comp, DeckOfCards &play, vector<Card> dPlay){
  cout << "\nComputer wins the turn, collecting all the cards!" << endl;
  comp.addCard(dPlay); // adds comp cards to player deck
  Card temp = comp.deck.front();
  comp.deck.push_back(temp);
  comp.deck.erase(comp.deck.begin(), comp.deck.begin()+1);
  play.deck.erase(play.deck.begin(), play.deck.begin()+dPlay.size());
}

// aglorithm for if player wins
void playerGame(DeckOfCards &play, DeckOfCards &comp, vector<Card> compCard){
  cout << "\nPlayer wins the turn" << endl;
  play.addCard(compCard);
  Card temp = play.deck.front();
  play.deck.push_back(temp);
  play.deck.erase(play.deck.begin(), play.deck.begin()+1);
  comp.deck.erase(comp.deck.begin(), comp.deck.begin()+compCard.size());
}

// algorithm for if computer wins
void computerGame(DeckOfCards &comp, DeckOfCards &play, vector<Card> playCard){
  cout << "\nComputer wins the turn" << endl;
  comp.addCard(playCard);
  Card temp = comp.deck.front();
  comp.deck.push_back(temp);
  comp.deck.erase(comp.deck.begin(), comp.deck.begin()+1);
  play.deck.erase(play.deck.begin(), play.deck.begin()+playCard.size());
}
