/************************************
Nazareth Diaz
CS210
Project 1

"clock.cpp" file.
This file contains the definitons for the
clock program functions.
**************************************/

#include "clock.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int seconds;
int minutes;
int hours;

// function to display clocks in both formats
void displayClocks(int& seconds, int& minutes, int& hour) {
    cout << characterDisplay(27, '*') << characterDisplay(3, ' ') << characterDisplay(27, '*') << endl;
    cout << characterDisplay(1, '*') << characterDisplay(6, ' ') << "12-HOUR-CLOCK" << characterDisplay(6, ' ') << characterDisplay(1, '*') << characterDisplay(3, ' ');
    cout << characterDisplay(1, '*') << characterDisplay(6, ' ') << "24-HOUR-CLOCK" << characterDisplay(6, ' ') << characterDisplay(1, '*') << endl;
    cout << endl;
    cout << characterDisplay(1, '*') << characterDisplay(6, ' ') << formatted12clock(seconds, minutes, hour) << characterDisplay(7, ' ') << characterDisplay(1, '*') << characterDisplay(3, ' ');
    cout << characterDisplay(1, '*') << characterDisplay(8, ' ') << formatted24clock(seconds, minutes, hour) << characterDisplay(9, ' ') << characterDisplay(1, '*') << endl;
    cout << characterDisplay(27, '*') << characterDisplay(3, ' ') << characterDisplay(27, '*') << endl;


}

// function to to display character clock display
string characterDisplay(int size, char c) {

    string output = ""; // string to return with desired output
    for (int i = 0; i < size; i++) {
        output.push_back(c);
    }

    return output;


}
// function returns formated 12-hour string
string formatted12clock(int& seconds, int& minutes, int& hour) {
    //cout << seconds << endl;
    //cout << minutes << endl;
    //cout << hour << endl;
    string twelveClock = ""; // returning formatted string
    int hourTime;
    string AMorPM;

    if (hour > 12) {
        hourTime = hour - 12;
        AMorPM = "P M";
    }
    else {
        AMorPM = "A M";
        hourTime = hour;
    }

    twelveClock = twoDigitString(hourTime) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds) + " " + AMorPM;

    return twelveClock;




}
// returns 24 hour string formatted
string formatted24clock(int& seconds, int& minutes, int& hour) {
    string twentyFourClock = ""; // returning formatted string

    twentyFourClock = twoDigitString(hour) + ":" + twoDigitString(minutes) + ":" + twoDigitString(seconds);

    return twentyFourClock;




}
// twoDigitString returns string format of h, m, s
string twoDigitString(int n) {
    string S = "";

    if (n <= 9) {
        S = "0" + to_string(n);
    }
    else {
        S = to_string(n);
    }

    return S;

}

//print menu with user selections
void printMenu() {

    cout << endl;
    cout << endl;
    cout << characterDisplay(27, '*') << endl;
    cout << setw(27) << left << "* 1 - Add One Hour" << right << "*" << endl;
    cout << setw(27) << left << "* 2 - Add One Minute" << right << "*" << endl;
    cout << setw(27) << left << "* 3 - Add One Second" << right << "*" << endl;
    cout << setw(27) << left << "* 4 - Exit Program" << right << "*" << endl;
    cout << characterDisplay(27, '*') << endl;

}

// process menu choice from user
int getMenuChoice() {
    int choice;
    cout << "Enter menu choice: " << endl;
    cin >> choice;
    // check for correct input
    while (choice > 4 || choice < 1) {
        cout << "Enter correct input: " << endl;
        cin >> choice;
    }
    return choice;
}

// function to add one second
void addOneSecond(int& second, int& minute, int& hour) {

    //check for second between 0 - 58
    if (second >= 0 && second <= 58) {
        second++;
    }
    else if (second == 59) {
        // calls addOneMinute
        addOneMinute(second, minute, hour);
        second = 0;
    }


}

//function to add one minute
void addOneMinute(int& second, int& minute, int& hour) {
    //check for minute between 0 - 58
    if (minute >= 0 && minute <= 58) {
        minute++;
    }
    else if (minute == 59) {
        // calls addOneHour
        addOneHour(second, minute, hour);

        minute = 0;
    }
}
//function to add one hour
void addOneHour(int& second, int& minute, int& hour) {

    if (hour == 24) {
        hour = 0;
    }
    else {
        hour += 1;
    }

}