
/* 
 * File:   main.cpp
 * Author: Omar Lopez Vie
 *
 * Created on April 19, 2021, 4:56 AM
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <fstream>

#include "Deck.h"
#include "Player.h"
#include "Game.h"

using namespace std;

bool askGameOver();

int main(int argc, char** argv) {
    
    std::srand(static_cast<int> (time(0)));
    Game game; //Initiate game object: Initial deck of cards are created, players are created, and initial cards (initial cards) are given out
    game.play(); //Start game loop, Displays menu, and a while loop keeps game running, and control functions direct the ongoing of the game

    return 0;
}