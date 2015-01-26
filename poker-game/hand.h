#ifndef _HAND_H_
#define _HAND_H_

#include "card.h"
#include <vector>

class Hand {

public:

    int totalplayers; //total number of players
    int playernumber; //player number
    /**
     * Add in individual card to a player's hand
     */
    void add(Card card);

    /**
     * Dump out a user's hand to STDOUT
     */
    void showHand();

    /**
     * Dump out the current user's hand. We check for the following
     * combinations:
     *    Four of a kind
     *    Flush (all cards the same suit)
     *    Three of a kind
     *    Two pair
     *    One pair
     */
    void check();
    /**
     * get the player number
     */

    /**
     * Method to get the result of the hand the player has
     */
    std::string getresult(int kind, int flush);

    /**
     * Get the player number
     */
    int get_playernumber();

    /**
     * get the total players playing
     */
    int gettotalplayers();

    /**
     * get the vector of the player
     */
    void get_playvec(int player_num, std::vector<Card> vc);

    /**
     * check card vector of each player
     */
    void check_for_player(vector<Card> vc);


private:
    std::vector<Card> cards; //define the cards vector
    //define vectors for each player(max 10 since there are 5 cards for each player. hence max 10 players can play)
    std::vector<Card> player1;
    std::vector<Card> player2;
    std::vector<Card> player3;
    std::vector<Card> player4;
    std::vector<Card> player5;
    std::vector<Card> player6;
    std::vector<Card> player7;
    std::vector<Card> player8;
    std::vector<Card> player9;
    std::vector<Card> player10;

};

#endif // _HAND_H_
