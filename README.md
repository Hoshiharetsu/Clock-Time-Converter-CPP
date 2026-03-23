# Clock Application (C++)

## Overview
This application displays time in both 12-hour and 24-hour formats and allows users to update time values interactively.

The program focuses on time formatting, user input handling, and maintaining consistent program state across multiple representations.

---

## Features

- Displays time in 12-hour and 24-hour formats simultaneously  
- Allows user-controlled updates to hours, minutes, and seconds  
- Synchronizes both time formats in real time  
- Provides a menu-driven interface  

---

## Technologies and Concepts

- C++  
- Object-oriented programming  
- Control structures and loops  
- Input handling and validation  
- Time formatting logic  
- Console-based interaction  

---

## Design Approach

The application maintains a single internal representation of time and updates both display formats based on that state.

This ensures consistency and demonstrates separation between data representation and output formatting.

---

## Key Challenges

- Keeping both time formats synchronized  
- Managing updates across multiple time components  
- Ensuring correct formatting for user display  

---

## Future Enhancements

- Add real-time clock functionality  
- Implement alarm and timer features  
- Improve user interface  
- Expand to graphical display  

---

## How to Run

```bash
g++ main.cpp -o clock_app
./clock_app
