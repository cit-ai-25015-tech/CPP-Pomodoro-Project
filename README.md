# OOP Pomodoro Manager System (C++)

## Project Description
An interactive C++ application designed to manage work and break cycles using the Pomodoro technique. Demonstrates key Object-Oriented Programming (OOP) principles.

## Features
- Interactive Timer System with Pomodoro technique.
- Random motivational quotes generator using C++ `rand()`.

## Applied OOP Concepts
1. **Classes & Objects**: `Timer`, `PomodoroTimer`.
2. **Encapsulation & Access Modifiers**: `private` and `protected` data protection.
3. **Constructors & Destructors**: Object creation and memory cleanup.
4. **Inheritance**: `PomodoroTimer` inherits from base `Timer`.
5. **Polymorphism & Virtual Functions**: `virtual void start()`.
6. **Function Overloading**: Overloaded `setTime()` functions.

## How to Compile & Run
1. Compile using g++:
   ```bash
   g++ main.cpp -o PomodoroTimer
