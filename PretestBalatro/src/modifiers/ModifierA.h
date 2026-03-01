#ifndef MODIFIERA_H
#define MODIFIERA_H

#include "IModifier.h"

class ModifierA : public IModifier {
public:
    int apply(int baseScore) override;
};

#endif