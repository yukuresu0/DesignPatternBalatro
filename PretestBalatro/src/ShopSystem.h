#ifndef SHOPSYSTEM_H
#define SHOPSYSTEM_H

#include "modifiers/IModifier.h"

class ShopSystem {
public:
    IModifier* chooseModifier();
};

#endif