/* Calvin Aduma
 * CPSC 1071:001
 * Code Blooded
 * 03/12/2023
 */

#include <iostream>
#include <string>
#include "Card.h"

using namespace std;
Card::Card(){
  face = NULL;
  suit = NULL;
}
//constructor, f=face, s=suit
Card::Card(int f, int s) {
  //initialize face and suit to input
  face = f;
  suit = s;
}

//array of strings for faces and suits
const string Card::faceArray[] = { "Ace", "Deuce", "Three", "Four", "Five",
				    "Six", "Seven", "Eight", "Nine",
				    "Ten", "Jack", "Queen", "King" };
const string Card::suitArray[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

//toString method takes in Card and returns a string, c=card
string Card::toString() {
  string faceOfSuit;

  //use the string arrays to determine the Card object's element and set it to a string
  faceOfSuit = Card::faceArray[this->face] + " of " + Card::suitArray[this->suit]; //FIXME: error no match for operand[]

  return faceOfSuit;
}
