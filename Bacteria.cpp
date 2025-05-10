#include "Bacteria.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include <chrono>

Bacteria::Bacteria(const Config& cfg) : population(cfg.initialPopulation), hours(0), config(cfg) {
    if (cfg.initialPopulation == 0) {
        throw std::invalid_argument("Initial population cannot be zero");
    }
}

void Bacteria::visualizeGrowth() const {
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

void Bacteria::simulate() {
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
