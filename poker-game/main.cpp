/**
Author: Shraddha Atrawalkar

Topic: homework 3: Poker game
 */

#include "deck.h"
#include "hand.h"
#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;
int main() {
    vector<Hand> hands;
    vector<Card> mycards;
    Deck deck;
    Card cards;
    Hand hand;
    int players;
    int seed;
    int sizeOfHand = 5;
    int total_cards = 0;

    cout << "Enter seed: ";
    cin >> seed;
    srand(unsigned(seed));

    cout << "Enter number of players: ";
    cin >> players;

    hand.totalplayers = players;
    deck.Shuffle();

    /* Your code here */
    /* Deal cards from the deck and do a round robin distribution to the
     * players.  Thus, if you had 5 players, and they each needed 5 cards you
     * would pull 5 cards off the deck and assign the first card to player one,
     * the second to player 2, etc.. Then you would deal 5 more and repeat the
     * process until 25 cards are dealt
     */

    total_cards = players * sizeOfHand;
    if (total_cards <= 52) {
        for (int i = 0; i < sizeOfHand; i++) {
            mycards = deck.Deal(players);
            deck.ShowDeck();
            for (int j = 1; j < mycards.size()+1; j++) {
                hand.playernumber = j;
                hand.add(mycards[j-1]);
            }

            hands.erase(hands.begin(), hands.end());
        }

    }

    hand.check();
}
