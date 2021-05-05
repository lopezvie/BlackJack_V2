/* 
 * File:   Deck.h
 * Author: Omar Lopez Vie
 *
 * Created on April 18, 2021, 5:01 AM
 */
#include <algorithm>
#include <random>
#include <iomanip>
#include <string>

#include "Deck.h"
//Initializes a deck of a standard 52-card decks

Deck::Deck() {
    for (int j = 0; j < NUM_SUITS; j++) {
        for (int k = 0; k < NUM_RANKS; k++) {
            Card temp;
            temp.suit = SUITS[j];
            temp.rank = RANKS[k];
            if (k > 9) {
                temp.value = VALUES[9];
            } else
                temp.value = VALUES[k];
            cards.push_back(temp);
        }
    }

}

Deck::~Deck() {
}

//This functions shuffles the standard 52-card deck

void Deck::shuffle() {
    std::random_shuffle(cards.begin(), cards.end());
}

//This function displays Deck for reference

void Deck::display() {
    std::cout << "\nRank" << std::right << std::setw(18) << "Suit" << std::right << std::setw(18) << "Value\n";
    for (i = cards.begin(); i != cards.end(); i++) {
        std::cout << (*i).rank << std::right << std::setw(18) << (*i).suit << std::right << std::setw(18) << (*i).value << std::endl;
    }
}

int Deck::getSize() const {
    return SIZE;
}

Card Deck::dealCard(int c) {
    if (count == 52)
        count = 0;
    return cards[c];
    count++;
}

