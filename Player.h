/* 
 * File:   Player.h
 * Author: Omar Lopez Vie
 *
 * Created on April 18, 2021, 5:22 AM
 */

#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <iterator>

#include "Rank_Suit.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    std::string userName;
    int moneyToBet;
    std::vector<Card> cards;
    std::vector<Card>::iterator i;
    short int turn;
public:
    Player(std::string, float, int);
    ~Player();
    void pushCard(Card);//Pushes a new card to the player vector of cards
    void displayCards(); // Displays cards in the player stack of cards
    std::string getUserName(); // returns the name of the player. Note: this version does not allow a player to pick usernames
    float getMoneyToBet(); // Returns the amount of money in players bank. Note: initially, each player has 2500.00
    void setMoneyToBet(float); //Restates the amount of money left for betting  
    int getCount(); // returns the count of the sum of values of each cars. Note: this version only considers Ace as one in value
    void printCards(std::ofstream &); // This function prints the cards rank, suit, values, and total count on to an external file, records.txt
    int getTurn(){return turn;} // Returns turn of the player
    void emptyCards(); // Takes away previously given cards from player, for a new game (hand)
};

#endif /* PLAYER_H */

