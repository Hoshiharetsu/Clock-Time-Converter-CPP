// Chada-Tech Header: Clock class and UI entry points for CS-210 Project 1.
// Interface (declarations) only. Implementations in main.cpp.
#ifndef CS210_PROJ1_CLOCKHEADER_H
#define CS210_PROJ1_CLOCKHEADER_H

#include <string>
#include <iostream>

class Clock {
public:
    explicit Clock(int hour24 = 0, int minute = 0, int second = 0);

    void addSecond();
    void addMinute();
    void addHour();

    void set24HourClock(int hour24, int minute, int second);

    //UPDATEME - Research showed [[nodiscard]] should be added, not 100% on why. Program still runs. Research this.
    std::string to24() const;
    std::string to12() const;

private:
    int hr; // 0 to 23
    int min; // 0 to 59
    int sec; // 0 to 59

    //Zero insert/padder for single integers:
    static std::string two(int n);
};

// ---- UI Methods ----- //
void displayClocks(const Clock& c, std::ostream& out = std::cout); //Display both the 12 and 24 hour clocks
void clockMenu(std::ostream& out = std::cout); //Show user the menu options for clocks
bool userChoice(Clock& c, int choice, std::ostream& out = std::cout); //Track and respond to user input
void run(std::istream& in = std::cin, std::ostream& out = std::cout); //enables the use of default cin and out, but helps to keep main() tight.

#endif //CS210_PROJ1_CLOCKHEADER_H
