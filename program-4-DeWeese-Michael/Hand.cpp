#include <iostream>
#include "Hand.h"
using namespace std;

Hand::Hand() {}

int Hand::getScore()
{
    // TODO: Implement Get Score
    int score = 0;
    int aces = 0;
    for(int i = 0 ; i < cards.size() ; i++)
    {
        score+= cards.at(i).getScore();
        if(cards.at(i).getRankString() == "Ace")
        {
            aces++;
        }//ending Ace and adds to hand
    }//end for loop counting the cards vector
    while(aces > 0 && score > 21)
    {
        score -=10;
        aces--;
    }//end while ace change to 1 if over 21
    return score;
}//end getScore function
void Hand::addCard(Card c)
{
    // TODO: Implement Add Card//add hit
    cards.push_back(c);
}
void Hand::printHand()
{
    for(int i = 0 ; i < cards.size() ; i++)
    {
        cout << cards.at(i).getRankString() << " of " << cards.at(i).getSuitString() << endl;
    }//end print line
}//end print function
