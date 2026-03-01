#ifndef SCORINGSYSTEM_H
#define SCORINGSYSTEM_H

#include "modifiers/IModifier.h"

class ScoringSystem {
public:
    int calculateScore(int baseScore, IModifier* modifier);
};

#endif