/**
 * Statistics.h
 * Homework 4
 * Author: Shraddha Atrawalkar
 */

#ifndef _STATISTICS_H_
#define _STATISTICS_H_

#include<set>
#include<vector>
#include<algorithm>
#include<numeric>
#include<stdexcept>
#include<iostream>
#include<iterator>
#include<deque>
#include"Time.h"

/**
*   The container class that I have used in this program is a deque (Double ended queue)
*   The reason I used a deque is because deques are fast when elements are added in them
*   either from front or end and not when done from the middle and here I am adding elements 
*   to the end of the deque and not the middle, hence a deque would be efficient.
*   Deque allows duplicate elements to be stored in them, the time values to be stored
*   for this code can be the same values multiple times(duplicates).
*   To get the median values, I needed a container class that provided efficient positional
*   access and a deque allows positional access using index.
*/


template<class T>
/**
* Class to compute the mean, mode, median, minimum and maximum of time values
*/
class Statistics {
public:

//Define the valuetype of the templatized type
    typedef T value_type;
    /**
     * Calculate the mean (average) of the data entered.
     *
     * @return the mean of the data pushed into our data set
     */
    T mean();

    /**
     * Calculate the median (middle element when the data is sorted)
     *
     * @return the mode of the data pushed into our data set
     */
    T median();

    /**
     * Calculate the mode (most common element).
     *
     * @return a set of the most common elements.  This can be the empty set if
     * there is a uniform distribution
     */
    std::set<T> mode();

    /**
     * Get the value of the smallest element
     *
     * @return the minimum value of the data pushed in
     */
    T min();

    /**
     * Get the value of the largest element
     *
     * @return the maximum value of the data pushed in
     */
    T max();

    /**
     * Add an element to our data set
     *
     * @param t Element to add to our data
     */
    void push(T t);

    /**
     * Removes all elements from the data
     */
    void clear();

private:
    //create a vector to hold the input data
    std::deque<T> time_ip;
    //set to hold the mode set
    std::set<T> mode_set;
    //vector to hold the occurrence of each element
    std::vector<int> occurences;
    
};

template<class T>
T Statistics<T>::mean() {
    if (time_ip.empty()) {
//Throw an exception if no values are entered
    throw std::underflow_error("Not enough data");
    } else {
    //compute the mean by getting the sum and dividing by the number of values
      T sum = accumulate(time_ip.begin(), time_ip.end(), T());
        T mean = (sum / (time_ip.size()));
        return mean;
    }
}

template<class T>
T Statistics<T>::median() {
    T median;
    //sort the container
    sort(time_ip.begin(), time_ip.end());
    int size = time_ip.size();//get size of the container
    if (size % 2 != 0) {//if there are odd elements, median is the middle element
        int middle = size / 2;
        median = (time_ip.at(middle));
    } else {//if there are even elements, median is the average of the 2 elements at the centre
        median = ((time_ip.at(size / 2) + time_ip.at((size / 2) - 1)) / 2);
    }
    return median;
}

template<class T>
std::set<T> Statistics<T>::mode() {
//sort the container
sort(time_ip.begin(), time_ip.end());
//compute the occurrence of each element in the container
 for (int iter = 0;iter<time_ip.size();iter++) {
        int counter = count(time_ip.begin(), time_ip.end(), time_ip.at(iter));
        occurences.push_back(counter);
    }
    
//get the maximum number of occurrence of elements  
int max = *(max_element(occurences.begin(),
          occurences.end()));
          
          if(max !=1){
          //copy each element which has the maximum occurrence into the mode set
          for (int i = 0; i < occurences.size(); i++)
      {
         if (occurences[i] == max)
         {
            mode_set.insert( time_ip[i]);
         }
      }
          
    }
    return mode_set;

}

template<class T>
T Statistics<T>::min() {
//get the minimum element from the container  
  T min = *(min_element(time_ip.begin(), time_ip.end()));
    return min;
}

template<class T>
T Statistics<T>::max() {
//get the maximum element from the container
    T max = *(max_element(time_ip.begin(), time_ip.end()));
    return max;
}

template<class T>
void Statistics<T>::push(T t) {
//push each time value entered into the deque container
    time_ip.push_back(t);

}

template<class T>
void Statistics<T>::clear() {
//clear the contents of all the containers used
    time_ip.clear();
    mode_set.clear();
    occurences.clear();

}
#endif // _STATISTICS_H_
