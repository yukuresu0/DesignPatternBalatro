#include "ModifierFactory.h"
#include "modifiers/ModifierA.h"
#include "modifiers/ModifierB.h"

IModifier* ModifierFactory::createModifier(int choice) {

    if (choice == 1) {
        return new ModifierA();
    }
    else if (choice == 2) {
        return new ModifierB();
    }
    else {
        return nullptr;
    }
}