#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "hand.h"

using namespace std;
/* Your code here */
static int player; //the current player
static int totalplay; //total players
static int player_num = 1; //the current player number

//Create objects for each player hand
Hand hand1;
Hand hand2;
Hand hand3;
Hand hand4;
Hand hand5;
Hand hand6;
Hand hand7;
Hand hand8;
Hand hand9;
Hand hand10;

//accessor to the total players
int Hand::gettotalplayers() {

    return totalplayers;
}

//accessor to the current player
int Hand::get_playernumber() {
    return playernumber;
}

//method to add a card to each player
void Hand::add(Card card) {

    totalplay = gettotalplayers();
    player = get_playernumber();

    switch (player) {
    case 1:
        hand1.cards.push_back(card);
        break;
    case 2:
        hand2.cards.push_back(card);
        break;
    case 3:
        hand3.cards.push_back(card);
        break;
    case 4:
        hand4.cards.push_back(card);
        break;
    case 5:
        hand5.cards.push_back(card);
        break;
    case 6:
        hand6.cards.push_back(card);
        break;
    case 7:
        hand7.cards.push_back(card);
        break;
    case 8:
        hand8.cards.push_back(card);
        break;
    case 9:
        hand9.cards.push_back(card);
        break;
    case 10:
        hand10.cards.push_back(card);
        break;

    }
}

//Display the hand of each player
void Hand::showHand() {

    static int x = 1;
    if (x <= totalplay) {
        switch (x) {
        case 1:
            for (vector<Card>::iterator i = hand1.cards.begin();
                    i != hand1.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        case 2:
            for (vector<Card>::iterator i = hand2.cards.begin();
                    i != hand2.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        case 3:
            for (vector<Card>::iterator i = hand3.cards.begin();
                    i != hand3.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        case 4:
            for (vector<Card>::iterator i = hand4.cards.begin();
                    i != hand4.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        case 5:
            for (vector<Card>::iterator i = hand5.cards.begin();
                    i != hand5.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        case 6:
           for (vector<Card>::iterator i = hand6.cards.begin();
                    i != hand6.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        case 7:
            for (vector<Card>::iterator i = hand7.cards.begin();
                    i != hand7.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        case 8:
            for (vector<Card>::iterator i = hand8.cards.begin();
                    i != hand8.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        case 9:
            for (vector<Card>::iterator i = hand9.cards.begin();
                    i != hand9.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        case 10:
            for (vector<Card>::iterator i = hand10.cards.begin();
                    i != hand10.cards.end(); i++) {
                
                    std::cout << std::setfill(' ') << std::setw(3) << (*i).str()
                            << " ";
            }
			cout<<"  ";
            x++;
            break;
        }

    }
}

//check the hand to see if there is any winning player
void Hand::check() {
    int kind = 0;
    int flush = 0;
    static int x = 1;
	std::string res;
    while (player_num <= totalplay) {
        switch (player_num) {
        case 1:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand1.cards.begin();
                    i != hand1.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand1.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush	
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
			res = Hand::getresult(kind, flush);
                std::cout << res;
            }
            std::cout <<std::endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;
        case 2:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand2.cards.begin();
                    i != hand2.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand2.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
                res = Hand::getresult(kind, flush);
                std::cout << res;
            }
            std::cout <<std::endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;
        case 3:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand3.cards.begin();
                    i != hand3.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand3.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
                res = Hand::getresult(kind, flush);
                std::cout << res;
            }
            std::cout <<std::endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;
        case 4:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand4.cards.begin();
                    i != hand4.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand4.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
                res = Hand::getresult(kind, flush);
                std::cout << res;
            }
            std::cout <<std::endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;
        case 5:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand5.cards.begin();
                    i != hand5.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand5.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
                res = Hand::getresult(kind, flush);
                std::cout << res;
            }
            std::cout <<std::endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;
        case 6:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand6.cards.begin();
                    i != hand6.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand6.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
                res = Hand::getresult(kind, flush);
                std::cout << res;
            }
	    std::cout<<std::endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;
        case 7:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand7.cards.begin();
                    i != hand7.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand7.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
                res = Hand::getresult(kind, flush);
                std::cout << res;
            }
            std::cout <<std::endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;
        case 8:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand8.cards.begin();
                    i != hand8.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand8.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
            res = Hand::getresult(kind, flush);
                std::cout << res;
            }
            std::cout<<endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;
        case 9:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand9.cards.begin();
                    i != hand9.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand9.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
            res = Hand::getresult(kind, flush);
                std::cout << res;
            }
            
			std::cout<<endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;
        case 10:
            std::cout << "Player " << player_num << " hand:  ";
            showHand();
            for (vector<Card>::iterator i = hand10.cards.begin();
                    i != hand10.cards.end(); ++i) {
                for (vector<Card>::iterator j = i + 1; j != hand10.cards.end();
                        j++) {
                    std::string fvalue = (*i).str();

                    std::string fvalue1 = fvalue.substr(fvalue.size() - 1);

                    std::string cardval = fvalue.erase(fvalue.size() - 1,
                            fvalue.size());

                    std::string svalue = (*j).str();
                    std::string svalue1 = svalue.substr(svalue.size() - 1);
                    std::string cardval2 = svalue.erase(svalue.size() - 1,
                            svalue.size());

                    /**
                     * count for flush
                     */

                    if (fvalue1 == svalue1) {
                        flush++;
                    }

                    /**
                     * count
                     * one pair
                     * two pair
                     * three of a kind
                     * four of a kind
                     */

                    if (cardval == cardval2) {
                        kind++;
                    }
                    /*
                     * get the result of the hand player has
                     */
                }
            }
            if (kind != 0 || flush != 0) {
                res = Hand::getresult(kind, flush);
                std::cout << res;
            }
            std::cout<<std::endl;
            kind = 0;
            flush = 0;

            player_num++;
            break;

        }
    }

}

//get the result of the hand's winning type
std::string Hand::getresult(int kind, int flush) {
    std::string result;
    if (kind == 1) {
        result = "One Pair";
    } else if (kind == 2) {
        result = "Two Pair";
    } else if (kind == 3) {
        result = "Three of A Kind";
    } else if (kind == 6) {
        result = "Four of A Kind";
    }
    if (flush == 10) {
        result = "Flush";
    }
    return result;

}
