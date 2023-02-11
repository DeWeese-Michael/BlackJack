#include "Deck.h"
using namespace std;

Deck::Deck()
{
    for(int i = 0 ; i < 4 ; i++)
    {
        for(int j = 0 ; j < 13 ; j++)
        {
            cards.push_back(Card(i,j));
        }//end j
    }//end i
}//end push back in the deck

void Deck::shuffle()
{
    // TODO: Implement shuffle
    srand(time(0));
    for(int i = 0 ; i < cards.size() ; i++)
    {
        int card = i + (rand() % 52 - i);
        swap(cards[i],cards[card]);
    }//end swap or shuffle action
}//end shuffle


Card Deck::dealCard()
{
    // TODO: Implement Deal Card
    // Should remove the "top" card in the deck
    Card temp = cards.at(cards.size()-1);
    cards.pop_back();
    return temp;
}//dealers card / top card

void Deck::addCard(Card newCard)
{
    // TODO: Implement Add Card
    cards.push_back(newCard);
}//addCard / remove card