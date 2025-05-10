#pragma once
#include "Config.h"
#include <cstdint>
#include <stdexcept>

class Bacteria {
private:
    uint64_t population;
    int hours;
    Config config;

    void visualizeGrowth() const;

public:
    explicit Bacteria(const Config& cfg);
    void simulate();
    uint64_t getPopulation() const { return population; }
    int getHours() const { return hours; }
};
