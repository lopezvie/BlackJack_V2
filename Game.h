/* 
 * File:   Game.h
 * Author: Omar Lopez Vie
 *
 * Created on April 19, 2021, 7:37 AM
 */
#include <iostream>
#include <cstdlib>
#include <list>
#include <stack>
#include <fstream>
#include <map>
#include <string>

#include "Deck.h"
#include "Player.h"

#ifndef GAME_H
#define GAME_H

class Game {
private:
    std::list<Player> players; //This version only has 2 players ( user and the computer)
    std::stack<Deck> decks;
    std::list<Player>::iterator i;
    std::map<int, std::string> myPrevGames;
    std::ofstream records; //Text File
    std::ofstream myRecords; //Text File
    std::ifstream myRecords_2;
    const unsigned short int NUM_PLYRS = 2; // This version only takes into consideration the scenario of only two players
    const unsigned short int NUM_STACK = 8; // Number of decks in a standard stack 
    unsigned short int count = 0; // Keeps track of cards delivered in a stack (8 stacks total)
    bool isOver = true;
    bool isProgramRunning = true;
    unsigned short int choice = 0; //Keeps record of the choice selected by player from menu (options)
    int betAmount = 0; // keeps record of the amount of the bet
    float runningCount = 0; // Keeps record of the running count at any given hand
    float trueCount = 0; // Keeps record of the true count at any given hand
public:
    Game(); // Constructor assigns users name and initially $2500 per player
    ~Game();
    void dealCard(std::list<Player>::iterator);
    void start(); //Delivers two cards to each player and displays 
    void play();
    int displayMenu(); //Displays menu (options) to players, and returns choice (integer)
    void hit(); // delivers a new card to the user
    void stand(); // player's turn play is over and handles out the game to the computer
    void doubleBet(); // doubles user's bet and delivers a new card to the player (user), increments the computer's bet too
    void computerGame(); //a little algorithm for the computer strategy for any game
    void quit(); // Terminates game 
    void displayCards(); //Displays players cards
    int whoWins(); // Checks who wins every time a card is delivered
    void declareWinner(int); // Declares winner by calling function whoWins() and displaying the results onto the screen for the user
    bool askUser(bool&); //Ask User if wants to continue running the program
    /******************************************************************************************************************************
     ******************************************************************************************************************************
     * The next functions keep track of data for further analysis on files*********************************************************
     * ****************************************************************************************************************************
     ******************************************************************************************************************************/
    void gameInfo(std::ofstream &); // records cards given and counts on records.txt
    void getMyRecords(std::ifstream &);
    void setMyRecords(std::ofstream &);
    void getPrevGames(std::ifstream &);
};


#endif /* GAME_H */

