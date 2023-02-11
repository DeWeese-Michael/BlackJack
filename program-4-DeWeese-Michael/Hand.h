#ifndef PROGRAM4_HAND_H
#define PROGRAM4_HAND_H
#include <vector>
#include "Card.h"

class Hand {
public:
    Hand();
    void printHand();
    int getScore();
    void addCard(Card c);
private:
    std::vector<Card> cards;
};
#endif //PROGRAM4_HAND_H
