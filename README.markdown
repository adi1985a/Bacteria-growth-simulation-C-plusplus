# 🦠🔬 BioGrowth Simulator: Exponential Bacteria Dynamics 🌱
_A C++ console application simulating exponential bacteria population growth with real-time ASCII visualization, configurable parameters, and overflow protection._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1. [Overview](#-overview)
2. [Key Features](#-key-features)
3. [Screenshots](#-screenshots)
4. [System Requirements](#-system-requirements)
5. [Installation and Setup](#️-installation-and-setup)
6. [Usage Guide](#️-usage-guide)
7. [File Structure](#-file-structure)
8. [Technical Notes](#-technical-notes)
9. [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**BioGrowth Simulator** (by Adrian Lesniak) is a C++ console application for modeling and visualizing exponential bacteria population growth. Users can configure parameters such as initial population, target population or simulation time, growth rate (e.g., doubling per hour), visualization mode, and animation delay. The program runs in hourly steps, updating the population until the target is reached or the specified number of hours elapses. Key features include a dynamic ASCII progress bar, colored interface, input validation, overflow protection (`uint64_t`), exception handling, and Windows console support.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features

* 🦠 **Bacteria Growth Simulation (`Bacteria` class):**
    * Two modes: grow until target population **or** for a fixed number of hours.
    * Tracks current population (`uint64_t`) and elapsed hours.
    * Overflow protection for large numbers.
* ⚙️ **Configurable Parameters (`Config` struct):**
    * Initial population, target population, growth rate, simulation mode, simulation time, visualization, animation delay.
    * Full input validation (no invalid values allowed).
* 📊 **Real-Time ASCII Visualization:**
    * Progress bar showing population growth toward the target.
    * Displays hours elapsed and current population.
    * Optional animation with configurable delay.
* ✔️ **Robust Error Handling:**
    * Error messages for invalid input, overflow, and unexpected exceptions.
    * Colored output for clarity (Windows).
* 🖥️ **Interactive, Colored Console Interface:**
    * ASCII art header and bacteria.
    * Main menu, "About" section, return to menu after simulation.
* ⏱️ **Controlled Animation Speed:** Uses `std::this_thread::sleep_for` with `std::chrono::milliseconds`.

## 🖼️ Screenshots

_Screenshots: main menu, parameter configuration, progress bar during simulation, final result._

<p align="center">
  <img src="screenshots/1.jpg" width="300"/>
  <img src="screenshots/2.jpg" width="300"/>
  <img src="screenshots/3.jpg" width="300"/>
  <img src="screenshots/4.jpg" width="300"/>
  <img src="screenshots/5.jpg" width="300"/>
  <img src="screenshots/6.jpg" width="300"/>
  <img src="screenshots/7.jpg" width="300"/>
  <img src="screenshots/8.jpg" width="300"/>
</p>

## ⚙️ System Requirements

* **Operating System:** Windows (uses `<windows.h>`, `system("cls")`, `<conio.h>`, console colors)
* **C++ Compiler:** C++11 or newer (e.g., g++, MSVC)
* **Standard Libraries:** `<iostream>`, `<string>`, `<thread>`, `<chrono>`, `<cstdint>`, `<stdexcept>`, `<limits>`, `<conio.h>`, `<windows.h>`

## 🛠️ Installation and Setup

1. **Clone the repository:**
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
2. **Ensure you have the source file:**
    The main file is e.g. `main.cpp` (or `bacteria_sim.cpp`).
3. **Compile** (example for MinGW g++):
    ```bash
    g++ main.cpp -o bacteria_sim.exe -std=c++11 -pthread -static-libgcc -static-libstdc++
    ```
    *(For MSVC: `cl main.cpp` or use Visual Studio)*
4. **Run the program:**
    ```bash
    .\bacteria_sim.exe
    ```

## 💡 Usage Guide

1. Run the program.
2. In the menu, choose:
    * `1` - Run simulation (go to parameter configuration)
    * `2` - About
    * `3` - Exit
3. **Simulation configuration:**
    * Enter initial population (>=1)
    * Choose mode:
        * `1` - Target population (enter target)
        * `2` - Fixed simulation time (enter number of hours)
    * Enter growth rate (>=1.0, e.g. 2 for doubling)
    * Choose whether to show visualization (1/0)
    * If yes, enter animation delay (ms)
4. **Simulation:**
    * Press ENTER to start.
    * Watch the progress bar and statistics.
    * After completion, press any key to return to the menu.
5. **Errors:**
    * The program reports invalid input, overflow, or unexpected errors.

## 🗂️ File Structure

* `main.cpp`: Main source file with all program logic.
* `README.md`: This file.
* `screenshots/`: Folder with screenshots.

## 📝 Technical Notes

* **Windows only:** Uses `<windows.h>`, `<conio.h>`, console colors, `system("cls")`.
* **Large numbers:** Uses `uint64_t` and checks for overflow before each operation.
* **Input validation:** Every input field is validated (no bad data allowed).
* **ASCII art:** Header and bacteria for better readability.
* **Possible extensions:** Logging results to file, logistic models, cross-platform support.

## 🤝 Contributing

Want to add features, improve code or visualization? Fork the repository, create a branch, make your changes, and open a Pull Request. Comments and good C++ practices are welcome!

## 📃 License

This project is licensed under the **MIT License**.  
See the LICENSE file for details.

## 📧 Contact

Author: **Adrian Lesniak**  
For questions or suggestions, open an issue on GitHub or contact the repository owner.

---
🌍 _Modeling the fascinating dynamics of life's exponential expansion._
