# NUCES Airline Flight Reservation System

## Overview
This project is a C++ console-based Airport Management System for NUCES Airline. It allows users to:
- Register as a passenger (including dependents)
- Login as an administrator or passenger
- View and update flight schedules (local and international)
- Book and cancel flights
- View and update airline inquiry details (admin)
- Restrict the number of passengers per class (admin)

## Features
- User registration and login (with password masking and validation)
- Admin panel for managing airline details and passenger restrictions
- Flight schedule display for multiple airports
- Booking and payment calculation for local and international flights
- Seat reservation and cancellation with refund policy

## Requirements
- C++ compiler (g++, clang++, or MSVC)
- macOS, Linux, or Windows

## How to Compile and Run

### On macOS/Linux
1. **Open Terminal** and navigate to the project root directory:
   
2. **Compile the program:**
   ```sh
   g++ -o "Airport Management System 2/Program" "Airport Management System 2/Program.cpp"
   ```
3. **Run the program:**
   ```sh
   ./"Airport Management System 2/Program"
   ```

### On Windows
1. **Open Command Prompt** and navigate to the project root directory:
   ```bat
   cd "\path\to\Cpp-Airport-Management-System"
   cd "Airport Management System 2"
   ```
2. **Compile the program:**
   - If you have MinGW installed:
     ```bat
     g++ -o Program.exe Program.cpp
     ```
   - If you are using Microsoft Visual Studio (Developer Command Prompt):
     ```bat
     cl Program.cpp
     ```
3. **Run the program:**
   ```bat
   Program.exe
   ```

**Note:**
- The current codebase is adapted for macOS/Linux. To run on Windows, you may need to revert to using `#include <conio.h>`, `#include <Windows.h>`, and replace the portable `getch()`, `clear_screen()`, and `sleep_ms()` functions with their Windows equivalents (`_getch()`, `system("cls")`, and `Sleep()`).
- If you want a cross-platform experience, use the macOS/Linux version in a Unix-like environment (such as WSL on Windows).

## Notes
- The program uses ANSI escape codes to clear the terminal screen and `termios` for password masking (macOS/Linux).
- All data is stored in memory; there is no persistent storage.
- For best results, use a standard terminal (not an IDE console) to ensure password masking and screen clearing work correctly.

## Authors
- Hashim Ahmad (i222478)

## License
This project is for educational purposes only. 