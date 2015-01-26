/**
 * main.cpp
 * Author: Shraddha Atrawalkar
 */
#include "Time.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string str;

    char operator1 = ' '; //variable to store the current operator
    char op;        //variable to be used in switch for setting operators

    //get the line from the console into a string
    do {
        getline(cin, str);
        istringstream linestream(str);

        //Initial value
        linestream >> str;

        //Create object of class Time and set the time for the first hh:mm
        Time mytime(str);

        //Keep parsing till the end of input string
        while (linestream >> str) {
            //set the operator
            if (operator1 == ' ') {      //if operator is not set
                op = str[0];        //get the operator in the input

                //set the operator for further computation
                switch (op) {
                case '+':
                    operator1 = '+';
                    break;
                case '-':
                    operator1 = '-';
                    break;
                }
            }
            //carry out the operation as per the operator
            if (str != "+" && str != "-") {
                if (operator1 == '+') {
                    mytime.add(Time(str));
                    //reset the operator
                    operator1 = ' ';

                } else if (operator1 == '-') {

                    mytime.subtract(Time(str));
                    //reset the operator
                    operator1 = ' ';

                }
            }
        }

        if (!cin.eof()) {        //Display the result of the computation
            cout << mytime.str() << endl;
        }

    } while (!cin.eof());

}
