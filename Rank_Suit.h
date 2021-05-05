/* 
 * File:   Rank_Suit.h
 * Author: Omar Lopez Vie
 *
 * Created on April 18, 2021, 5:27 AM
 */
//This file contains all definitions 
#include <iostream>
#include <cstdlib>
#include <string>


#ifndef RANK_SUIT_H
#define RANK_SUIT_H

//Simulates a card object

struct Card { // Simulates a card
    std::string rank;
    std::string suit;
    int value;
};

//An array to stored all possible faces in a standard 52-card deck
const std::string RANKS [] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

//An array to stored all possible values in a standard 52-card deck
const int VALUES [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//An array to stored all possible suits in a standard 52-card deck
const std::string SUITS [] = {"Spades", "Hearts", "Diamonds", "Clubs"};

#endif /* RANK_SUIT_H */

