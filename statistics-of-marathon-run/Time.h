/**
 * Time.h
 * For use with 4003-703-01, Homework 4
 * Fall '14
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Shraddha Atrawalkar
 */
#ifndef __TIME_H__
#define __TIME_H__

#include <string>
#include<iostream>
#include<stdexcept>
#include<exception>

//using namespace std;
/**
 * This class gets the mean, median, mode, maximum and minimum of all time values provided in a marathon
 */
class Time {
public:
    /**
     * Default constructor. Time is set to 0
     */
    Time();

    /**
     * Time constructor that takes a string that represents time in the
     * format hh:mm:ss
     * @param time Time in the format hh:mm:ss
     */
    Time(std::string time);

    /**
     * Time constructor that takes elapsed number of seconds since the epoch
     * @param seconds the number of seconds since the epoch
     */
    Time(int seconds);

    /**
     * Convert the time in format hh:mm:ss  to seconds
     * @param t Time to add to self
     * @return current time plus the new time
     */
    
    void setTime(std::string time);

    friend std::ostream& operator<<(std::ostream &stream, const Time &t);

    friend std::istream& operator>>(std::istream &stream, Time &t);

    bool operator<(Time t) const;
    bool operator>(Time t) const;
    bool operator==(Time t) const;
    Time operator+(Time t);
    Time operator/(Time t);

private:
    /**
     * Number of seconds since the epoch
     */
    int seconds;

  
};

#endif // __TIME_H_HH
