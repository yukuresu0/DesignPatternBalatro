#ifndef MODIFIERFACTORY_H
#define MODIFIERFACTORY_H

#include "modifiers/IModifier.h"

class ModifierFactory {
public:
    static IModifier* createModifier(int choice);
};

#endif