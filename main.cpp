/*******************************************************************************
 * Bacteria Growth Simulation
 * -------------------------
 * This program simulates the exponential growth of a bacteria population.
 * 
 * Features:
 * - Simulates bacterial division where population doubles each hour
 * - Visualizes growth progress with ASCII progress bar
 * - Tracks population until it reaches 1 billion units
 * - Handles overflow protection and error conditions
 * - Provides real-time visualization of growth progress
 * 
 * Technical details:
 * - Uses 64-bit integers to handle large population numbers
 * - Implements exception handling for safety
 * - Configurable initial conditions through Config structure
 * - Visual feedback with progress bar and population counter
 ******************************************************************************/

#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <chrono>
#include <conio.h>
#include <cstdint>
#include <stdexcept>

struct Config {
    uint64_t initialPopulation;
    uint64_t maxPopulation;
    double growthRate;
    bool showVisualization;
    int visualizationDelay;

    void getUserInput() {
        std::cout << "Enter initial population: ";
        std::cin >> initialPopulation;
        std::cout << "Enter maximum population: ";
        std::cin >> maxPopulation;
        std::cout << "Enter growth rate (e.g., 2 for doubling): ";
        std::cin >> growthRate;
        std::cout << "Show visualization? (1 for yes, 0 for no): ";
        std::cin >> showVisualization;
        std::cout << "Enter visualization delay in milliseconds: ";
        std::cin >> visualizationDelay;
    }
};

class Bacteria {
private:
    uint64_t population;
    int hours;
    Config config;

    void visualizeGrowth() const {
        if (!config.showVisualization) return;

        system("cls");
        const int width = 50;
        double ratio = static_cast<double>(population) / config.maxPopulation;
        int bars = static_cast<int>(ratio * width);

        std::cout << "\nProgress: [";
        for (int i = 0; i < width; ++i) {
            std::cout << (i < bars ? '|' : ' ');
        }
        std::cout << "]\n";
        std::cout << "Hours: " << hours << " Population: " << population << "\n";
        
        std::this_thread::sleep_for(std::chrono::milliseconds(config.visualizationDelay));
    }

public:
    explicit Bacteria(const Config& cfg) : population(cfg.initialPopulation), hours(0), config(cfg) {
        if (cfg.initialPopulation == 0) {
            throw std::invalid_argument("Initial population cannot be zero");
        }
    }

    void simulate() {
        try {
            while (population < config.maxPopulation) {
                if (population > UINT64_MAX / 2) {
                    throw std::overflow_error("Population overflow detected");
                }
                
                population *= config.growthRate;
                hours++;
                visualizeGrowth();
            }
            
            std::cout << "\nSimulation complete!\n";
            std::cout << "Final population: " << population << "\n";
            std::cout << "Time taken: " << hours << " hours\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Error during simulation: " << e.what() << std::endl;
            throw;
        }
    }
};

int main() {
    try {
        std::cout << "=================================================\n";
        std::cout << "           Bacteria Growth Simulator             \n";
        std::cout << "=================================================\n\n";
        std::cout << "This program simulates bacterial population growth\n";
        std::cout << "through cell division. Each bacterium divides into\n";
        std::cout << "two new bacteria every hour, creating exponential\n";
        std::cout << "growth of the population.\n\n";
        std::cout << "You can either:\n";
        std::cout << "1. Set a target bacteria count to reach\n";
        std::cout << "2. Set a specific simulation time in hours\n\n";
        std::cout << "The program will show:\n";
        std::cout << "- Real-time visualization of growth\n";
        std::cout << "- Time taken to reach target population\n";
        std::cout << "- Final population count\n\n";
        
        Config config;
        config.getUserInput();  // Get user input before starting simulation
        
        std::cout << "Press ENTER to start simulation...";
        _getch();

        Bacteria bacteria(config);
        bacteria.simulate();
        
        std::cout << "\nPress any key to exit...";
        _getch();
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << std::endl;
        _getch();
        return 1;
    }
}
