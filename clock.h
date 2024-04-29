/************************************
Nazareth Diaz
CS210
Project 1

"clock.h" header file.
This is the header file for the clock program.
This program resembles a 12-hour and a 24-hour clock for the user.
The user enters an initial time to set the clock,
then can add seconds, minutes, and hours
until program exit.
**************************************/

#include <string>


void displayClocks(int& seconds, int& minutes, int& hour);
std::string characterDisplay(int size, char c);
std::string formatted12clock(int& seconds, int& minutes, int& hour);
std::string twoDigitString(int n);
std::string formatted24clock(int& seconds, int& minutes, int& hour);
void printMenu();
int getMenuChoice();
void addOneSecond(int& second, int& minute, int& hour);
void addOneMinute(int& second, int& minute, int& hour);
void addOneHour(int& second, int& minute, int& hour); 
