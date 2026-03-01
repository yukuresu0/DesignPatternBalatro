#ifndef RUNSESSION_H
#define RUNSESSION_H

#include "ScoringSystem.h"
#include "ShopSystem.h"
#include <vector>

class RunSession {
private:
    ScoringSystem scoring;
    ShopSystem shop;
    IModifier* currentModifier = nullptr;

    int coins = 0;

public:
    void start();
};

#endif