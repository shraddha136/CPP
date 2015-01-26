/**
 * Time.cpp
 * Homework 4
 * Author: Shraddha Atrawalkar
 */
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Time.h"
#include <istream>
#include<stdexcept>

using namespace std;

Time::Time(void) { //constructor to initialize seconds to 0
    seconds = 0;
}

Time::Time(int _seconds) { //constructor to set the seconds value
    seconds = _seconds;
}

Time::Time(string t) { //constructor to set the time i.e. convert input to seconds

    setTime(t);
}

/**
*   Overloading operator >> to convert input to output
*   @param stream input stream
*   @param t      time object
*   @return stream input character stream
*/
istream &operator>>(istream &stream, Time &t) {
    string input; //string to get input stream
    stream >> input; //insert the stream to the string
    t.setTime(input);//pass the string to the method to convert time to seconds

    return stream;//return the converted input stream
}

/**
*   Overloading operator >> to convert input to output
*   @param stream output stream
*   @param t      time object
*   @return stream output character stream
*/
ostream &operator<<(ostream &stream, const Time &t) {

//convert seconds to the stream to display in hh:mm:ss format
    stream << (t.seconds / 3600) << ":" << setfill('0') << setw(2)
            << (t.seconds / 60) % 60 << ":" << setfill('0') << setw(2)
            << t.seconds % 60;
    return stream;//return the output stream

}

/**
*   Method to convert the input stream from hh:mm:ss to seconds
*   @param t input stream in hh:mm:ss format
*/
void Time::setTime(std::string t) { //method to convert the input hh:mm time to seconds

    int hour; //variable to store hours in seconds
    int mins; //variable to store minutes in seconds

    int secs; //variable to store seconds in seconds
    
    int index = t.find_first_of(':'); //variable to get the position of the first: in hh:mm:ss
    int index2 = t.find_last_of(':'); //variable to get the position of the last : in hh:mm:ss

    seconds = 0; //reset the seconds to 0
//if the user enters only the hours
    if (index == -1 && index2 == -1) {
        string hh = t; //get the string with value for hours
        istringstream hhvalue(hh); //convert the string hours into integer value
        hhvalue >> hour;//value of hours
        mins = 0;
        secs = 0;

    } else if (index == 0) {//if no hours are entered
        hour = 0;
    } else {//if the hours are entered by the user
        string hh = t.substr(0, index); //get the string with value for hours
        istringstream hhvalue(hh); //convert the string hours into integer value
        hhvalue >> hour;//value of hours
    }
    if (hour < 0) { //if the hours go negative
        throw runtime_error("Invalid time entry");
    }
    seconds += hour * 3600; //convert hours to seconds

    //if the input entered is not just hours, set the minutes and seconds values
    if (index != -1 && index2 != -1) {
        string mm;//string to store the minutes
        int temp_ind = index + 1;//temporary variable to compare index of :
        if (index == index2) //there is only 1 colon and format is hh:mm
            {
            mm = t.substr(index + 1, t.size()); //get the string with value for minutes
            istringstream mmvalue(mm); //convert the string hours into integer value
            mmvalue >> mins;//get the minutes value

        } else if (index2 == temp_ind) { //if the input is in format hh: set the minutes to 0
            mins = 0;
        } else {
            mm = t.substr(index + 1, index2); //get the string with value for minutes
            istringstream mmvalue(mm); //convert the string hours into integer value
            mmvalue >> mins;//get the minutes value

        }
        if (mins < 0 || mins >= 60) { //if the minutes entered is out of bounds
            throw runtime_error("Invalid time entry");
            seconds = 0; //reset the seconds
        } else {
            seconds += mins * 60; //convert minutes to seconds
        }

        //set the seconds value
        string ss;
        //if the user has entered seconds
        if (index != index2) {
            ss = t.substr(index2 + 1, t.size()); //get the string with value for seconds
            if (ss == "") {//if the seconds value is not entered by the user
                secs = 0;
            } else {
                istringstream ssvalue(ss); //convert the string hours into integer value
                ssvalue >> secs;//get the seconds value
            }

        } else if (index2 == t.size()) { //if the input is in format hh: set the seconds to 0
            secs = 0;
        } else {
            secs = 0;
        }
        if (secs < 0 || secs >= 60) { //if the minutes entered is out of bounds
            throw runtime_error("Invalid time entry");
            seconds = 0; //reset the seconds
        } else {
            seconds += secs; //convert minutes to seconds
        }

    }
}



/**
*
*Overload the + operator for Time objects
* @param t time object
*/
Time Time::operator +(Time t) {
    Time sum;//variable to store the sum
    sum.seconds = (t.seconds) + seconds;//add values
    return sum;//return the sum
}


/**
*
*Overload the / operator for Time objects
* @param t time object
*/
Time Time::operator /(Time t) {
    Time div;//variable to store quotient
    div.seconds = seconds / t.seconds;//divide values
    return div;//return quotient
}

/**
*
*Overload the < operator for Time objects
* @param t time object
*/
bool Time::operator <(Time t) const {
//compare values to check lesser value
    if (seconds < t.seconds) {
        return true;
    } else {
        return false;
    }
}

/**
*
*Overload the > operator for Time objects
* @param t time object
*/
bool Time::operator >(Time t) const {
//compare values to check greater value    
    if (seconds > t.seconds) {
        return true;
    } else {
        return false;
    }
}

/**
*
*Overload the == operator for Time objects
* @param t time object
*/
bool Time::operator ==(Time t) const {
//compare values for equality
    if (seconds == t.seconds) {
        return true;
    } else {
        return false;
    }
}
