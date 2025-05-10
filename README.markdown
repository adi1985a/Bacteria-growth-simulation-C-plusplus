# Bacteria Growth Simulator

## Overview
This C++ console application simulates exponential bacteria growth, where the population doubles each hour until reaching a user-defined maximum. It features a real-time ASCII progress bar, configurable settings, and overflow protection. Users input initial population, maximum population, growth rate, and visualization preferences.

## Features
- **Bacteria Class**:
  - Tracks population (`uint64_t`), hours, and configuration.
  - `simulate`: Runs growth simulation, doubling population per hour.
  - `visualizeGrowth`: Displays ASCII progress bar and population stats.
- **Config Struct**:
  - Stores user settings: `initialPopulation`, `maxPopulation`, `growthRate`, `showVisualization`, `visualizationDelay`.
  - `getUserInput`: Prompts for configuration values.
- **Visualization**:
  - Real-time ASCII progress bar showing growth ratio.
  - Displays hours and current population.
- **Error Handling**:
  - Validates non-zero initial population.
  - Prevents overflow with `UINT64_MAX` checks.
  - Uses exception handling for robustness.
- **Main Program**:
  - Displays introductory message and simulation details.
  - Collects user input and runs simulation.
  - Waits for keypress to start and exit.

## Requirements
- C++ compiler (e.g., g++, MSVC) with C++11 or later
- Windows OS (for `windows.h`, `_getch`, `system("cls")`)
- Standard C++ libraries: `<iostream>`, `<windows.h>`, `<string>`, `<thread>`, `<chrono>`, `<conio.h>`, `<cstdint>`, `<stdexcept>`
- Operating system: Windows (due to console functions)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Save the provided code as `bacteria_sim.cpp`.
3. Compile the program:
   ```bash
   g++ bacteria_sim.cpp -o bacteria_sim
   ```
4. Run the program:
   ```bash
   .\bacteria_sim
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays a welcome message and simulation details.
   - Prompts for:
     - Initial population
     - Maximum population
     - Growth rate (e.g., 2 for doubling)
     - Visualization toggle (1 for yes, 0 for no)
     - Visualization delay (ms)
3. **Actions**:
   - Press Enter to start simulation.
   - View real-time progress bar (if enabled) with population and hours.
   - See final results: population and hours taken.
   - Press any key to exit.
4. **Output**:
   - Example: "Final population: 1000000000, Time taken: 30 hours".
   - Errors: "Initial population cannot be zero" or "Population overflow detected".

## File Structure
- `bacteria_sim.cpp`: Main C++ source file with program logic.
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific due to `windows.h`, `_getch`, and `system("cls")`; adapt for other OS (e.g., `system("clear")` for Unix).
- Uses `uint64_t` for large populations, with overflow checks.
- Visualization delay controls update speed; adjust for performance.
- Extend by adding logging, more growth models, or cross-platform support.
- No input validation for negative numbers; assumes valid user input.
- No external dependencies beyond standard C++ and Windows libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.