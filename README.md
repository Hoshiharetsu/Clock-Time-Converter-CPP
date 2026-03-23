# Clock Application (C++)

## Overview
This project is a console-based clock application that displays time in both 12-hour and 24-hour formats simultaneously. Users can interact with the program to update the clock values and observe how the two time systems correspond.

The application focuses on user input, time formatting, and maintaining consistent program state across multiple displays.

---

## Features
- Displays time in both 12-hour and 24-hour formats
- Allows users to update hours, minutes, and seconds
- Keeps both clock displays synchronized
- Uses a menu-driven console interface
- Reinforces formatted output and control logic

---

## Technologies and Concepts
- C++
- Object-oriented programming (classes and methods)
- Control structures and loops
- Input handling and validation
- Time formatting logic
- Console-based user interaction

---

## Development Approach
This project was built using a modular design approach, with attention given to separating time-handling logic from user interaction. Pseudocode planning helped organize the sequence of user choices, time updates, and display formatting before implementation.

The structure of the application was designed to keep the logic readable and maintainable while supporting multiple related outputs from the same underlying data.

---

## Challenges and Problem Solving
One of the main challenges in this project was managing time updates accurately while ensuring both the 12-hour and 24-hour displays remained synchronized. Small changes to one value, such as hours or minutes, needed to be reflected consistently across both formats.

Another challenge was adapting familiar programming logic to C++ syntax and program structure. This reinforced the importance of breaking the problem into smaller pieces, testing frequently, and validating output carefully.

---

## What I Learned
- How to manage related program state across multiple output formats
- How to format and display time in different conventions
- The importance of modular design for readability and maintenance
- How pseudocode supports planning before implementation
- How to troubleshoot logic differences when working in C++

---

## Future Improvements
- Add real-time clock functionality
- Improve input validation and menu flow
- Expand the interface beyond the console
- Add alarm or timer features for additional functionality

---

## How to Run
Compile and run using a C++ compiler:

```bash
g++ main.cpp -o clock_app
./clock_app
