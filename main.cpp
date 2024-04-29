/************************************
Nazareth Diaz
CS210
Project 1

"main.cpp" file.
This is the file where the main function is.
The main function controls the program and
controls the user selection to run the clock
program.
**************************************/
#include <iostream>
#include <string>
#include <iomanip>
#include "clock.h"

using namespace std;


int main() {


    int seconds; // keep track of seconds
    int minutes;  // keep track of minutes
    int hour;  // keep track of hours
    int menuChoice;
    bool exitMenu = true;
    const int addHour = 1,
        addMinute = 2,
        addSecond = 3,
        exit = 4;


    //start
    // set original clock time
    cout << "Enter seconds (0-59):";
    cin >> seconds;
    while (seconds > 59 || seconds < 0) {
        cout << "Enter correct input: ";
        cin >> seconds;
    }
    cout << "Enter minutes (0-59):";
    cin >> minutes;
    while (minutes > 59 || minutes < 0) {
        cout << "Enter correct input: ";
        cin >> minutes;
    }
    cout << "Enter hour (0-23)";
    cin >> hour;
    while (hour > 23 || hour < 0) {
        cout << "Enter correct input: ";
        cin >> hour;
    }


    do {
        //display clock in both formats
        displayClocks(seconds, minutes, hour);
        printMenu(); // print menu for user choice
        menuChoice = getMenuChoice();

        if (menuChoice == addHour) {
            // call addOneHour
            addOneHour(seconds, minutes, hour);
        }
        if (menuChoice == addMinute) {
            // call addOneMinute
            addOneMinute(seconds, minutes, hour);
        }
        if (menuChoice == addSecond) {
            // call addOneSecond
            addOneSecond(seconds, minutes, hour);
        }
        if (menuChoice == exit) {
            exitMenu = false;
        }






    } while (exitMenu);

}
