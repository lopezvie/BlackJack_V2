/* 
 * File:   Game.h
 * Author: Omar Lopez Vie
 *
 * Created on April 20, 2021, 9:07 AM
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>


#include "Game.h"

using namespace std;

Game::Game() {
    for (int k = 0; k < NUM_STACK; k++) {
        Deck newDeck;
        newDeck.shuffle();
        decks.push(newDeck);
    }

    for (int l = 0; l < NUM_PLYRS; l++) {
        std::string name = "Player ";
        int i = 0;
        if (l == 1) {
            name += "(Computer)";
            i = 2;
        } else {
            name += "(You)";
            i = 1;
        }
        Player temp = Player(name, 2500.0f, i);
        players.push_back(temp);
    }
}

Game::~Game() {
}

void Game::dealCard(std::list<Player>::iterator i) {
    if (count == 52) { //if all cards of the first deck on the stack are delivered already, a new deck is used 
        decks.pop();
        count = 0;
    }
    // Assigns the deck on top of the stack to the temp variable in order to deliver it
    (*i).pushCard(decks.top().dealCard(count));
    count++;
}

void Game::start() {
    std::cout << "\n\tBLACJACK\n\nInitial Hand:\n";
    for (i = players.begin(); i != players.end(); i++) {
        dealCard(i);
        dealCard(i); //This function deals 2 cards to each player
        std::cout << "\n" << (*i).getUserName() << " :";
        (*i).displayCards();
    }
    i = players.begin();
    std::cout << "\n\n\tEnter the amount of money you wish to bet (MAX: $" << (*i).getMoneyToBet() << "): ";
    std::cin >> betAmount;
    while (betAmount < 0 || (betAmount > ((*i).getMoneyToBet()))) { //Make sure that the bet is not negative nor the bet exceeds the maximum amount that each player has initially
        std::cout << "\n\tInvalid Input!!\n\tEnter the amount of money you wish to bet (MAX: $2500.00): ";
        std::cin >> betAmount;
    }

}

void Game::play() {
    while (isProgramRunning) {
        start(); //Start game loop, Displays menu
        while (isOver) {
            int choice = displayMenu();
            switch (choice) {
                case 1: hit();
                    break;
                case 2: stand();
                    break;
                case 3: doubleBet();
                    break;
                case 4: quit();
                    break;
            }
        }
        isProgramRunning = askUser(isOver);
    }
}

int Game::displayMenu() {
    int choice = 0;
    std::cout << "\n\tBlackjack Menu\n1. Hit\n2. Stand\n3. Double\n4. Quit\n\tChoice: "; //Only three options for the player
    std::cin >> choice;
    while (choice < 1 || choice > 4) {
        std::cout << "\n\tBlackjack Menu\n\tInvalid Input \n1. Hit\n2. Stand\n3. Double\n\tChoice: "; //If the input is not 1,2, or three, the computer keeps asking for a choice, alerting the user of an error
        std::cin >> choice;
    }
    std::cout << "\n*********************************Blackjack********************************";
    return choice;
}

void Game::hit() {
    dealCard(players.begin());
    displayCards();
}

void Game::stand() {
    computerGame();
    declareWinner(whoWins());
}

void Game::doubleBet() {
    betAmount *= 2;
}

void Game::computerGame() {
    i = players.begin();
    unsigned short int plyr = (*i).getCount();
    std::advance(i, 1);
    unsigned short int cmptr = (*i).getCount();
    while (cmptr <= 16) //The strategy of the computer is always to hit something close to 17, in order to avoid surpassing 21 
    {
        dealCard(i);
        cmptr = (*i).getCount();
    }
}

void Game::quit() {
    isOver = false;
    gameInfo(records);
}

void Game::displayCards() {
    for (i = players.begin(); i != players.end(); i++) {
        std::cout << "\n" << (*i).getUserName() << " :";
        (*i).displayCards();
    }
}

int Game::whoWins() {
    int plyr = 0, cmptr = 0;
    for (i = players.begin(); i != players.end(); i++) {
        if ((*i).getTurn() == 1)
            plyr = (*i).getCount();
        else if ((*i).getTurn() == 2)
            cmptr = (*i).getCount();
    }
    if (plyr > cmptr && plyr <= 21) //Checks all possible scenarios of who wins any given hand
        return 1;
    else if (cmptr > plyr && cmptr <= 21)
        return 2;
    else if (plyr > 21 && cmptr <= 21)
        return 2;
    else if (cmptr > 21 && plyr <= 21)
        return 1;
    else
        return 0;
}

void Game::declareWinner(int option) {
    i = players.begin();
    if (option == 1) {
        std::cout << "\n**************************************************************************\n" <<
                "**************************************************************************\n" <<
                "***************************Player 1 (You) Wins****************************\n" <<
                "**************************************************************************\n" <<
                "**************************************************************************\n";
        (*i).setMoneyToBet(betAmount); //Adds to the winner
        std::cout << "\n\n\tWinner (You): $" << (*i).getMoneyToBet() << " Count: " << (*i).getCount();
        ;
        std::advance(i, 1);
        (*i).setMoneyToBet((betAmount*-1)); //Deduct from looser
        std::cout << "\n\tLooser (Computer): $" << (*i).getMoneyToBet() << " Count: " << (*i).getCount();
        ;
    } else if (option == 2) {
        std::cout << "\n**************************************************************************\n" <<
                "**************************************************************************\n" <<
                "***************************Player 2 (Computer) Wins***********************\n" <<
                "**************************************************************************\n" <<
                "**************************************************************************\n";
        (*i).setMoneyToBet((betAmount*-1)); //Deduct from looser
        std::cout << "\n\n\tLooser (You): $" << (*i).getMoneyToBet() << " Count: " << (*i).getCount();
        std::advance(i, 1);
        (*i).setMoneyToBet(betAmount); //Adds to the winner
        std::cout << "\n\tWinner (Computer): $" << (*i).getMoneyToBet() << " Count: " << (*i).getCount();
    } else {
        std::cout << "\n**************************************************************************\n" <<
                "**************************************************************************\n" <<
                "*********************************Push!************************************\n" <<
                "**************************************************************************\n" <<
                "**************************************************************************\n";
        std::cout << "\n\n\tPlayer 1 (You): $" << (*i).getMoneyToBet() << " Count: " << (*i).getCount();
        std::advance(i, 1);
        std::cout << "\n\tPlayer 2 (Computer): $" << (*i).getMoneyToBet() << " Count: " << (*i).getCount();
    }
    gameInfo(records); //Prints records of the game onto a outside txt file
    quit(); // quits game
}

void Game::gameInfo(std::ofstream& file) {
    file.open("records.txt", std::ios_base::app); // Appends to records.txt
    if (file.is_open()) {
        file << "\n\tBLACJACK\n";
        i = players.begin();
        file << "\n" << (*i).getUserName() << " :";
        (*i).printCards(file);
        file << "\nBank: $" << (*i).getMoneyToBet() << std::endl;
        std::advance(i, 1);
        file << "\n" << (*i).getUserName() << " :";
        (*i).printCards(file);
        file << "\nBank: $" << (*i).getMoneyToBet() << std::endl;
        file.close();
    } else {
        std::cout << "\n\tError: Unable to open file";
        play();
    }
}

bool Game::askUser(bool &game) {
    unsigned short int option = 0;
    std::cout << "\n\n\t1. Continue Playing\n\t0. Quit\n\t Choice: ";
    std::cin >> option;
    while (option > 1 && option < 0) {
        std::cout << "\n\tInvalid Input!\n\n\t1. Continue Playing\n\t0. Quit\n\t Choice: ";
        std::cin >> option;
    }
    if (option == 1) { // If user desires to continue playing, their cards vectors are emptied out
        game = true;
        i = players.begin();
        (*i).emptyCards();
        std::advance(i, 1);
        (*i).emptyCards();
        return true;
    } else if (option == 0) {
        game = false;
        return false;
    } else
        return false;
}


