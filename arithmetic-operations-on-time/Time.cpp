/**
 * Time.cpp
 * Homework 2
 * Author: Shraddha Atrawalkar
 */
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"
#include <istream>

using namespace std;

bool invalid; //variable to indicate that the value id invald

Time::Time(void) { //constructor to initialize seconds to 0
    seconds = 0;
}

Time::Time(int _seconds) { //constructor to set the seconds value
    seconds = _seconds;
}

Time::Time(string t) { //constructor to set the time i.e. convert input to seconds

    setTime(t);
}

Time Time::add(Time t) { //method to add the 2 times entered
    if (invalid != true) {
        return seconds += t.seconds;
    }
    return 0;

}

Time Time::subtract(Time t) { //method to subtract the 2 times entered
    if (invalid != true) {
        return seconds -= t.seconds;
    }
    return 0;
}

std::string Time::str() const { //method to display the result in hh:mm format
    ostringstream oss;
    oss << seconds / 3600 << ":" << setfill('0') << setw(2)
            << (seconds % 3600) / 60;
    return oss.str();

}

void Time::setTime(std::string t) { //method to convert the input hh:mm time to seconds

    int hour; //variable to store hours in seconds
    int mins; //variable to store minutes in seconds
    int index = t.find_first_of(':'); //variable to get the position of the : in hh:mm

    seconds = 0; //reset the seconds to 0

    string hh = t.substr(0, index); //get the string with value for hours

    istringstream hhvalue(hh); //convert the string hours into integer value
    hhvalue >> hour;
    if (!hhvalue) { //if the input is in format :mm set the hours to 0
        hour = 0;
    }
    if (hour < 0) //if the hours go negative
            {
        cerr << "Hours is out of bounds: " << hour << endl;
    }
    seconds += hour * 3600; //convert hours to seconds

    string mm = t.substr(index + 1, t.length()); //get the string with value for minutes
    istringstream mmvalue(mm); //convert the string hours into integer value
    mmvalue >> mins;
    if (!mmvalue) { //if the input is in format hh: set the minutes to 0
        mins = 0;
    }
    if (mins < 0 || mins >= 60) { //if the minutes entered is out of bounds
        cerr << "Minutes is out of bounds: " << mins << endl;
        invalid = true;
        seconds = 0; //reset the seconds

    } else {
        invalid = false;
        seconds += mins * 60; //convert minutes to seconds
    }
}

