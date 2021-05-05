/* 
 * File:   Deck.h
 * Author: Omar Lopez Vie
 *
 * Created on April 18, 2021, 5:01 AM
 */

#include <iostream>
#include <string> 
#include <vector>
#include <iterator>

#include "Rank_Suit.h"

#ifndef DECK_H
#define DECK_H

//Holds 52 cards and their actions in a game

class Deck {
private:
    std::vector<Card> cards;
    std::vector<Card>::iterator i;
    const unsigned short int NUM_SUITS = 4;
    const unsigned short int NUM_RANKS = 13;
    const unsigned short int SIZE = NUM_SUITS * NUM_RANKS;
    unsigned short int count = 0;
public:
    //Constructor: Initiates the deck by assigning all 52 cards their respective suit and rank
    Deck();
    ~Deck();
    void shuffle(); // This function shuffles the vector of cards
    void display(); // This function is intended for debugging purposes. Note: this function is not utilized during the running application
    int getSize() const; // This function returns the total number of cards in a 8 standard decks of 52 cards each
    Card dealCard(int); // This Function returns a card to be added into a vector of cards
};

#endif /* DECK_H */

