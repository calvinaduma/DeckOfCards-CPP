/* Calvin Aduma
* CPSC 1071:001
* Code Blooded
* 03/13/2023
*/

#include "DeckOfCards.h"
#include "Card.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

const int NUM_CARDS = 52;
void swapCards(vector<Card>&, int &, int &);

//constructor that uses a vector of Cards
DeckOfCards::DeckOfCards() {
  int suit = 0;
  //loop until the end of vector, which is size 52
  for(int i = 0; i < NUM_CARDS; i++) {
    int face = i % 13;
    if( i > 0 && i % 13 == 0) suit++;
    //create Card object
    Card card = Card(face, suit); //is this needed if it is defined in Card.h?
    //add Card object into deck vector
    deck.push_back(card);
    // increase deck size counter
  }
  DeckOfCards::deckSize = deck.size();
  DeckOfCards::currentCard = 0;

}

//function shuffles deck of card
void DeckOfCards::shuffle() {
  unsigned seed = time(0);
  srand(seed); // seeds randomn number generator
  int randNum = rand() % NUM_CARDS; // randomly select card to swap for each index
  for(int i=0; i<NUM_CARDS; i++){
    swapCards(deck, i, randNum);
    randNum = rand() % NUM_CARDS;
  }
}

//returns next Card from deck
Card DeckOfCards::dealCard(){
  // checks if there is more cards to deal in deck
  if(DeckOfCards::deckSize <= 0){ // if no more cards to deal
    return Card(0,0);
  }
  Card cardReturned = DeckOfCards::deck[DeckOfCards::currentCard];
  DeckOfCards::currentCard++;
  return cardReturned;
}

//check if there are more cards to deal
bool DeckOfCards::moreCards(){
  // returns true if current card is at end of deck
  return !(DeckOfCards::currentCard >= NUM_CARDS-1);
}

//adds cards to end of deck
void DeckOfCards::addCard(vector<Card> d){
  deck.insert(deck.end(), d.begin(), d.end());
  this->deckSize += d.size(); // increases size of the deck
}

void DeckOfCards::setCurrentCard(int num){
  this->currentCard = num;
}

void swapCards(vector<Card> &deckShuffle, int &cardOne, int &cardTwo){
  Card tempCard = deckShuffle[cardOne];
  deckShuffle[cardOne] = deckShuffle[cardTwo];
  deckShuffle[cardTwo] = tempCard;
}
