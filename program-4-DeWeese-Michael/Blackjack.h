#ifndef PROGRAM4_BLACKJACK_H
#define PROGRAM4_BLACKJACK_H

#include <iostream>
#include "Deck.h"
#include "Hand.h"

class Blackjack {
public:
    Blackjack();

    void play();

private:
    int bet;
    string s;//file
    string entry;
    int loop = 1;
    Deck deck;
    Hand dealer;
    Hand player;
};


#endif