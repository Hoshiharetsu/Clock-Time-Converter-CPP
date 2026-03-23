/*
 * CS-210, Project 1: Chada Clock
 * R.DuPont
 * Program Overview: Displays 12 and 24 hour clocks. The user is provided with options to update the seconds, minutes, and hours based on menu selections.
 */

#include "clockHeader.h"
#include <iomanip> //Enables ability to format menu and clock display
#include <sstream> //Enabling the use of ostringstream to collect and build strings.

using namespace std;

// ---------- Clock (12 and 24 Hours) ---------- //
//Clock Constructor: Calls the set24HourClock class for initial values -
Clock::Clock(int hour24, int minute, int second) {
    hr = 0; min = 0; sec = 0; //initializing the constructor member variables.
    set24HourClock(hour24, minute, second); //Call to set24HourClock Method to set values.
}

void Clock::set24HourClock(int hour24, int minute, int second) {
    if (hour24 < 0) { hour24 = 0; }
    if (hour24 > 23) { hour24 = 23; }
    if (minute < 0) { minute = 0; }
    if (minute > 59) { minute = 59; }
    if (second < 0) { second = 0; }
    if (second > 59) { second = 59; }
    hr = hour24; min = minute; sec = second;
}

//Methods to handle user choices and add time based on menu selection:
void Clock::addSecond() {
    sec++;
    if (sec == 60) {
        sec = 0; addMinute();
    }
}

void Clock::addMinute() {
    min++;
    if (min == 60) {
        min = 0; addHour();
    }
}

void Clock::addHour() {
    hr++;
    if (hr == 24) {
        hr = 0;
    }
}

//Controls for two integers to control time for 00 hr: 00 min: 00 sec
string Clock::two(int n) {
    if (n < 10) {
        return "0" + to_string(n); //Handles adding zero for single numerical counts.
    }
    else {
        return to_string(n);
    }
}

// Returns "HH:MM:SS" in 24-hour format, using two() for zero-padding.
string Clock::to24() const {
    return two(hr) + ":" + two(min) + ":" + two(sec);
}

// Returns "HH:MM:SS AM/PM" in 12-hour format.
string Clock::to12() const {
    int hour12 = hr % 12;
    if (hour12 == 0) hour12 = 12;
    string ampm = (hr < 12) ? "AM" : "PM";
    return two(hour12) + ":" + two(min) + ":" + two(sec) + " " + ampm;
}

// ---------- UI Layout & Presentation ------------------
void displayClocks(const Clock& c, ostream& out) {
    //UPDATE: Rework Layout into cleaner code
    const string top = "**************************";
    const string label1 = "*     12-Hour Clock      *";
    const string label2 = "*     24-Hour Clock      *";
    // Row 1
    out << top << "    " << top << "\n";
    // Row 2
    out << label1 << "    " << label2 << "\n";
    // Row 3
    out << "*       " << setw(11) << left << c.to12() << "      *"
        << "    "
        << "*       " << setw(11) << left << c.to24() << "      *" << "\n";
    // Row 4
    out << top << "    " << top << "\n\n";
}

//User Menu and Options:
void clockMenu(ostream& out) {
    out << "**************************\n"
        << "*     Menu Selection      *\n"
        << "**************************\n"
        << "* 1 - Add One Hour        *\n"
        << "* 2 - Add One Minute      *\n"
        << "* 3 - Add One Second      *\n"
        << "* 4 - Exit Program        *\n"
        << "**************************\n"
        << "Enter your choice: ";
}

//Handles user input based on displayMenu() displayed options:
bool userChoice(Clock& c, int choice, ostream& out) {
    switch (choice) {
    case 1: c.addHour();   return true;
    case 2: c.addMinute(); return true;
    case 3: c.addSecond(); return true;
    case 4: return false; // exit
    default: //Handling user-input outside of cases.
        out << "Invalid selection. Select a menu option between 1 through 4.\n";
        return true;
    }
}

//Give control of the core program launch. run() is called in the main() method.
//Create additional updates as needed and replace in main() for testing.
void run(istream& in, ostream& out) {
    int h{}, m{}, s{}; //Local Variables to collect user input
    out << "Welcome to Chada Clock! Please enter the starting time using the format HH MM SS: ";
    
    if (!(in >> h >> m >> s)) {
        in.clear(); //Clear and dump error state
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        out << "Invalid input. Using 00:00:00.\n";
        h = m = s = 0;
    }

    Clock clock(h, m, s); //Create clock object based on user input
    bool keepGoing = true; //tracks to continue running program

    while (keepGoing) {
        displayClocks(clock, out);
        clockMenu(out);

        int choice{};
        if (!(in >> choice)) {
            in.clear(); //Clearing out the error state.
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            out << "Please enter a number 1-4.\n\n"; //Reprint the options for the user.
            continue;
        }

        keepGoing = userChoice(clock, choice, out);
        out << "\n";
    }

    out << "Thank you for using the Chada-Clock Systems!\n"; //Alert the user they exit the program.
}

//Main Method for the program:
int main() {
    run(); //Set Up core program construction into a method. Keep main() tight.
    return 0;
}
