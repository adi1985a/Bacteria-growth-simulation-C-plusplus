#pragma once
#include <cstdint>
#include <iostream>
#include <limits>

struct Config {
    uint64_t maxPopulation = 1000000000;
    uint64_t initialPopulation = 1;
    double growthRate = 2.0;
    bool showVisualization = true;
    int visualizationDelay = 100;

    void getUserInput() {
        int choice;
        std::cout << "\nChoose simulation mode:\n";
        std::cout << "1. Set target bacteria count\n";
        std::cout << "2. Set simulation time (hours)\n";
        std::cout << "Choice (1 or 2): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::cout << "Enter initial number of bacteria (default=1): ";
                std::string input;
                std::getline(std::cin, input);
                if (!input.empty()) {
                    initialPopulation = std::stoull(input);
                }

                std::cout << "Enter target population (default=1000000000): ";
                std::getline(std::cin, input);
                if (!input.empty()) {
                    maxPopulation = std::stoull(input);
                }
                break;
            }
            case 2: {
                std::cout << "Enter initial number of bacteria (default=1): ";
                std::string input;
                std::getline(std::cin, input);
                if (!input.empty()) {
                    initialPopulation = std::stoull(input);
                }

                std::cout << "Enter simulation time in hours: ";
                int simulationHours;
                std::cin >> simulationHours;
                // Calculate target population based on time
                maxPopulation = initialPopulation;
                for (int i = 0; i < simulationHours; i++) {
                    maxPopulation *= 2;
                }
                break;
            }
            default:
                std::cout << "Invalid choice. Using default values.\n";
        }
        
        std::cout << "\nSimulation parameters:";
        std::cout << "\nInitial population: " << initialPopulation;
        std::cout << "\nTarget population: " << maxPopulation << "\n\n";
    }
};
