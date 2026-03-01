#include "ScoringSystem.h"

int ScoringSystem::calculateScore(int baseScore, IModifier* modifier) {
    if (modifier != nullptr)
        return modifier->apply(baseScore);

    return baseScore;
}