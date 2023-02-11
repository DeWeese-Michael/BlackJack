#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Blackjack.h"

using namespace std;

Blackjack::Blackjack()
{
}
    void Blackjack::play()
    {
        // TODO: Implement play (Play the game of blackjack)
        cout << "Welcome to Blackjack! Let's Play!\n" << endl;
        cout << "Loading blank balance..." << endl;

        ifstream balance_file("../balance.txt");
        if (!balance_file.is_open())
        {
            cout << "Invalid file location. Try again" << endl;
        }//end if balance error

        getline(balance_file, s);//file opened and received
        int balance = stoi(s)  ;
        balance_file.close();

        while (entry != "q")
        {
            cout << "\n---- Hand " << loop << " ----" << endl;
            loop++;
            cout << "Your balance is $" << balance << endl;
            cout << "Place your bet: $";
            cin >> bet;
            deck = Deck();
            deck.shuffle();
            cout << endl << "Dealing cards...\n" << endl;

            cout << "Dealers Hand: " << endl << "\n";//ADD in Dealers first card of his hand
            dealer = Hand();
            dealer.addCard(deck.dealCard());
            dealer.printHand();

            cout << "Players Hand: " << endl << "\n";//ADD in players full hand
            player = Hand();
            player.addCard(deck.dealCard());
            player.addCard(deck.dealCard());
            player.printHand();


            cout << "Hand Value: " << player.getScore() << endl; //sum of players hand value

            char index;
            cout << "Enter 's' to stay or 'h' to hit: ";
            cin >> index;
            bool bust = false;

            while(index == 'h')
            {
                Card temp = deck.dealCard();
                player.addCard(temp);
                cout << "New Card: "<< endl;
                cout << temp.getRankString() << " of " << temp.getSuitString() << endl;
                cout << "Hand Value: " << player.getScore() << endl; //sum of players hand value

                if(player.getScore() > 21)
                {
                    cout << "You Busted! " << endl;
                    cout << "You lost $" << bet << endl;
                    balance -= bet;
                    bust = true;
                    break;
                }//end playerScore over

                cout << "Enter 's' to stay or 'h' to hit: ";
                cin >> index;
            }//end while hit for player

            if(!bust)
            {
                cout << "Dealer Hits..." << endl;

                while(dealer.getScore() < 17)
                {
                    Card temp = deck.dealCard();
                    dealer.addCard(temp);
                    cout << "New Card: "<< endl;
                    cout << temp.getRankString() << " of " << temp.getSuitString() << endl;
                    cout << "Hand Value: " << dealer.getScore() << endl; //sum of players hand value

                    if(dealer.getScore() > 21)
                    {
                        cout << "Dealer Busted! " << endl;
                        cout << "You won $" << bet << endl;
                        balance += bet;
                        bust = true;
                        break;
                    }//end DealerScore bust
                }//end cut dealer at 17
            }//end if not bust (Dealer)
            if(!bust)
            {
                if(player.getScore() > dealer.getScore())
                {
                    cout << "You won $" << bet << endl;
                    balance += bet;
                }//end player greater / won
                else if(player.getScore() < dealer.getScore())
                {
                    cout << "You lost $" << bet << endl;
                    balance -= bet;
                }//end player lesser / lost
                else
                {
                    cout << "Tie" << endl;
                }//end tie
            }//end if not bust (player)

            ofstream balanceOut("../balance.txt");
            balanceOut << balance ;
            balanceOut.close();

            cout << "Enter 'c` to continue or `q` to quit: ";
            cin >> entry;
        }//end while
    }//end play BlackJack :)

