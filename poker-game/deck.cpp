#include "deck.h"
#include <iostream>
#include <algorithm>

using namespace std;

//Create object of class
Card card;

//constructor of class Deck
Deck::Deck() {
    Shuffle();
}

//method to shuffle the cards
void Deck::Shuffle() {
    cards.erase(cards.begin(), cards.end());
    for (int i = Card::CLUBS; i <= Card::SPADES; i++) {
        for (int j = Card::TWO; j <= Card::ACE; j++) {
            cards.push_back(Card(Card::SUITS(i), Card::COUNT(j)));
        }
    }
    random_shuffle(cards.begin(), cards.end());
}

/* Your code here */

/**
 * take one card for each player
 */
std::vector<Card> Deck::Deal(int players) {

    carddeal.erase(carddeal.begin(), carddeal.end());

    for (int i = 0; i < players; i++) {
        carddeal.push_back(cards[i]);
    }
    return carddeal;
}

//method removes cards from the deck to distribute among hands
void Deck::ShowDeck() {
    for (int i = carddeal.size(); i < cards.size(); i++) {
        cardsleft.push_back(cards[i]);
    }
    cards.erase(cards.begin(), cards.end());

    for (int i = 0; i < cardsleft.size(); i++) {
        cards.push_back(cardsleft[i]);
    }
    cardsleft.erase(cardsleft.begin(), cardsleft.end());
    carddeal.erase(carddeal.begin(), carddeal.end());
}

