/* 
 * File:   Game.h
 * Author: Omar Lopez Vie
 *
 * Created on April 19, 2021, 7:37 AM
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

#include "Player.h"
#include "Rank_Suit.h"

Player::Player(std::string user_name, float money, int number) {
    userName = user_name;
    moneyToBet = money;
    turn = number;
}

Player::~Player() {
}

void Player::pushCard(Card newCard) {
    cards.push_back(newCard);
}

void Player::displayCards() {
    for (i = cards.begin(); i != cards.end(); i++) {
        std::cout << "\n" << (*i).suit << " " << (*i).rank;
    }
    std::cout << std::endl << " count: " << getCount() << std::endl;
}

std::string Player::getUserName() {
    return userName;
}

float Player::getMoneyToBet() {
    return moneyToBet;
}

void Player::setMoneyToBet(float amount) {
    moneyToBet += amount;
}

int Player::getCount() {
    int count = 0;
    for (i = cards.begin(); i != cards.end(); i++) {
        count += (*i).value;
    }
    return count;
}

void Player::printCards(std::ofstream& records) {
    for (i = cards.begin(); i != cards.end(); i++) {
        records << "\n" << (*i).suit << " " << (*i).rank;
    }
    records << std::endl << " count: " << getCount() << std::endl;
}

void Player::emptyCards(){
    while (!cards.empty())
  {
     cards.pop_back();
  }
}