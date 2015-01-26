#include "card.h"
#include <sstream>

using namespace std;

//constructor of class Card
Card::Card(){

}

//accessor to private variables of the class Card
Card::Card(Card::SUITS _suit, Card::COUNT _val) {
    suit = _suit;
    value = _val;
}

//method to get the string representation of the card
string Card::str() {
    ostringstream os;
    os << valToStr() << suitToStr();
    return os.str();
}

/* Your code here */

//Get the suit of the card
Card::SUITS Card::getSuit() {
    return suit;
}

//Get the value of the card
Card::COUNT Card::getValue() {
    return value;
}

//Convert the suit to string
string Card::suitToStr() {
    int card_suit = getSuit();
    string suit;
    switch (card_suit) {
    case 1:
        suit = "C"; //clubs
        break;
    case 2:
        suit = "D"; //diamond
        break;
    case 3:
        suit = "H"; //heart
        break;
    case 4:
        suit = "S"; //spades
        break;
    }

    return suit;
}

//Convert the value to string
string Card::valToStr() {
    string value;
    int card_value = getValue();

    switch (card_value) {
    case 2:
        value = "2";
        break;
    case 3:
        value = "3";
        break;
    case 4:
        value = "4";
        break;
    case 5:
        value = "5";
        break;
    case 6:
        value = "6";
        break;
    case 7:
        value = "7";
        break;
    case 8:
        value = "8";
        break;
    case 9:
        value = "9";
        break;
    case 10:
        value = "10";
        break;
    case 11:
        value = "J";
        break;
    case 12:
        value = "Q";
        break;
    case 13:
        value = "K";
        break;
    case 14:
        value = "A";
        break;
    }

    return value;
}

