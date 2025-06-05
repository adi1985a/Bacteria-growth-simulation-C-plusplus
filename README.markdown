# 🦠🔬 BioGrowth Simulator: Exponential Bacteria Dynamics 🌱
_A C++ console application simulating exponential bacteria population growth with real-time ASCII visualization, configurable parameters, and overflow protection._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features](#-key-features)
3.  [Screenshots (Conceptual)](#-screenshots-conceptual)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Setup](#️-installation-and-setup)
6.  [Usage Guide](#️-usage-guide)
7.  [File Structure](#-file-structure)
8.  [Technical Notes](#-technical-notes)
9.  [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**BioGrowth Simulator**, developed by Adrian Lesniak, is a C++ console application designed to model and visualize the exponential growth of a bacteria population. Users can configure key parameters such as the initial population, the maximum allowable population, and the growth rate (e.g., doubling per hour). The simulation runs in discrete time steps (hours), updating the population until it reaches or exceeds the defined maximum. A key feature is its real-time ASCII progress bar that visually represents the population's approach to the maximum. The program incorporates robust error handling, including input validation and overflow protection for large population counts (using `uint64_t`), and is primarily designed for the Windows console environment.

## ✨ Key Features

*   🦠 **Bacteria Growth Simulation (`Bacteria` Class)**:
    *   Tracks key metrics: current `population` (as `uint64_t`), `hours` elapsed.
    *   `simulate()`: Executes the core growth logic, typically doubling the population each simulated hour (or applying the user-defined `growthRate`) until `maxPopulation` is reached or an overflow is imminent.
*   ⚙️ **Configurable Parameters (`Config` Struct)**:
    *   Stores user-defined settings: `initialPopulation`, `maxPopulation`, `growthRate`, `showVisualization` (toggle), and `visualizationDelay` (in milliseconds).
    *   `getUserInput()`: Prompts the user to provide these configuration values before starting the simulation.
*   📊 **Real-Time ASCII Visualization (`visualizeGrowth`)**:
    *   Displays a dynamic ASCII progress bar indicating the current population relative to the `maxPopulation`.
    *   Shows the current `hours` elapsed and the `current population` count alongside the progress bar.
    *   Updates at an interval controlled by `visualizationDelay`.
*   ✔️ **Robust Error Handling & Validation**:
    *   Validates that the `initialPopulation` is non-zero.
    *   Includes checks to prevent `uint64_t` overflow during population calculation, halting the simulation if `UINT64_MAX` would be exceeded.
    *   Utilizes C++ exception handling (`std::runtime_error`, `std::invalid_argument`) for managing input and simulation errors.
*   🖥️ **Interactive Console Interface**:
    *   Displays an introductory message and explains the simulation details.
    *   Collects all necessary configuration inputs from the user.
    *   Requires a keypress to initiate the simulation and another to exit after completion.
*   ⏱️ **Controlled Simulation Speed**: Uses `std::this_thread::sleep_for` with `std::chrono::milliseconds` for managing the update frequency of the visualization.

## 🖼️ Screenshots (Conceptual)

**Coming soon!**

_This section would ideally show screenshots of: the initial parameter input prompts, the real-time ASCII progress bar during simulation, and the final results display._

## ⚙️ System Requirements

*   **Operating System**: Windows (due to dependencies like `<windows.h>` for console manipulation like `system("cls")` and `<conio.h>` for `_getch()`).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<string>`, `<vector>` (if used internally), `<thread>`, `<chrono>`, `<cstdint>` (for `uint64_t`), `<stdexcept>`, `<limits>`, `<iomanip>`.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Save Main Code**:
    Ensure your main program logic (including the `Bacteria` class, `Config` struct, and `main()` function) is saved as `bacteria_sim.cpp` (or your chosen main file name) in the project directory. *(The description implies a single-file structure for this project).*

3.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, etc.) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ bacteria_sim.cpp -o bacteria_sim.exe -std=c++11 -pthread -static-libgcc -static-libstdc++
    ```
    *(The `-pthread` flag is necessary if using `std::thread` with MinGW g++. Adjust if using a different compiler like MSVC, which handles threading differently. Remove `-static-libgcc -static-libstdc++` if not needed or building on other platforms with g++).*

4.  **Run the Program**:
    ```bash
    .\bacteria_sim.exe
    ```
    (or `bacteria_sim.exe` in CMD)

## 💡 Usage Guide

1.  Compile and run `bacteria_sim.exe` as detailed above.
2.  **Interface & Input**:
    *   The program will display a welcome message and details about the simulation.
    *   You will be prompted to enter the following configuration values:
        *   **Initial population**: The starting number of bacteria.
        *   **Maximum population**: The simulation stops when this population is reached or exceeded.
        *   **Growth rate**: The factor by which the population multiplies each hour (e.g., `2` for doubling).
        *   **Show visualization? (1 for yes, 0 for no)**: Toggles the real-time ASCII progress bar.
        *   **Visualization delay (ms)**: The refresh rate for the progress bar in milliseconds.
    *   Input validation will check for issues like zero initial population.
3.  **Start Simulation**:
    *   After entering all parameters, press **Enter** (or any key as prompted) to start the simulation.
4.  **View Progress (if visualization enabled)**:
    *   A real-time ASCII progress bar will show the current population's growth towards the maximum.
    *   The current number of hours passed and the current population count will also be displayed and updated.
5.  **Final Results**:
    *   Once the simulation completes (either max population reached or overflow prevented), the program will display the final population achieved and the total time taken in hours.
    *   Example: "Final population: 1000000000, Time taken: 30 hours".
6.  **Exit**:
    *   Press any key as prompted to exit the application.

*   **Error Messages**:
    *   "Initial population cannot be zero."
    *   "Population overflow detected. Simulation stopped to prevent data loss."

## 🗂️ File Structure

*   `bacteria_sim.cpp`: The main (and likely only) C++ source file containing all program logic, including the `Bacteria` class, `Config` struct, visualization functions, and the `main()` function.
*   `README.md`: This documentation file.

*(No external data or log files are mentioned as being created by default in the provided description, other than potential implicit OS behavior.)*

## 📝 Technical Notes

*   **Windows Specifics**: The project utilizes Windows-specific headers (`<windows.h>`, `<conio.h>`) for console functionalities like screen clearing (`system("cls")`) and non-buffered keypresses (`_getch()`). Adapting for true cross-platform compatibility would require alternatives (e.g., `system("clear")` for Unix-like systems, ncurses or standard input for keypresses, ANSI escape codes for any advanced cursor manipulation if used in the progress bar).
*   **Large Population Handling**: Uses `uint64_t` (unsigned 64-bit integer) to accommodate large bacteria population numbers. Crucially, it includes checks against `UINT64_MAX` to prevent arithmetic overflow before it happens.
*   **Real-Time Visualization**: The progress bar is updated using `std::this_thread::sleep_for` and `std::chrono::milliseconds` to control the refresh rate, providing a semblance of real-time updates without consuming excessive CPU.
*   **Input Validation**: The description mentions validation for non-zero initial population. Robust validation for other inputs (e.g., ensuring growth rate is positive, max population is greater than initial) would further enhance the program. The note "No input validation for negative numbers; assumes valid user input" highlights an area for improvement.
*   **Potential Enhancements**:
    *   Adding data logging for simulation parameters and results to a file.
    *   Implementing more complex growth models (e.g., logistic growth with carrying capacity, death rates).
    *   Improving cross-platform support for console interactions.
    *   Adding more detailed input validation.

## 🤝 Contributing

Contributions to **BioGrowth Simulator** are highly encouraged! If you have ideas for implementing more sophisticated growth models, enhancing the visualization, adding data logging/graphing capabilities, or improving cross-platform compatibility:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourBioSimEnhancement`).
3.  Make your changes and commit them (`git commit -m 'Feature: Implement YourBioSimEnhancement'`).
4.  Push to the branch (`git push origin feature/YourBioSimEnhancement`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🌍 _Modeling the fascinating dynamics of life's exponential expansion._
