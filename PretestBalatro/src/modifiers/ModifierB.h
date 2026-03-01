#ifndef MODIFIERB_H
#define MODIFIERB_H

#include "IModifier.h"

class ModifierB : public IModifier {
public:
    int apply(int baseScore) override;
};

#endif