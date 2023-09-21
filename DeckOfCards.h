/* Calvin Aduma
 * CPSC 1071:001
 * Code Blooded
 * 03/13/2023
 */

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H
#include "Card.h"
#include <vector>

using namespace std;

class DeckOfCards {
  private:
    //represent next card to deal
    int currentCard;

    int deckSize;

 public:  
  //vector of Cards named deck to store Cards
  vector<Card> deck;

  //default constructor
  DeckOfCards();

  //shuffle function that iterates through vector
  void shuffle();

  //returns next Card from deck
  Card dealCard();

  //check if there are more cards to deal
  bool moreCards();

  //adds cards
  void addCard(vector<Card>);

  //gets size();
  int size(){
    return deck.size();
  }
  // sets value for current card
  void setCurrentCard(int);
};

#endif
