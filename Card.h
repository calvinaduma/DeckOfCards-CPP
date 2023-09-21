/* Calvin Aduma
 * CPSC 1071:001
 * Code Blooded
 * 03/12/2023
 */

#ifndef CARD_H
#define CARD_H
#include <string>

using namespace std;

class Card {
 public:
  //initialized enums
  enum Faces { Ace = 1, //initialized to 1
	       Deuce,
	       Three,
	       Four,
	       Five,
	       Six,
	       Seven,
	       Eight,
	       Nine,
	       Ten,
	       Jack,
	       Queen,
	       King };
  
  enum Suits { Hearts = 1, //initialized to 1
	       Diamonds,
	       Clubs,
	       Spades };
  
  //static arrays of strings
  static const string faceArray[13];
  static const string suitArray[4];
  
  // empty contstructor for empty card
  Card();
  //constructor that takes in 2 int variables
  Card(int, int);

  // card entities
  int face, suit;

  //method that returns Card as a string
  string toString();

};

#endif
