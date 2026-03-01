#include "ShopSystem.h"
#include "ModifierFactory.h"
#include <iostream>

using namespace std;

IModifier* ShopSystem::chooseModifier() {
    int choice;

    cout << "\nChoose Modifier:\n";
    cout << "1) Double Score\n";
    cout << "2) Bonus +50\n";
    cout << "0) None\n";
    cout << "Choice: ";

    cin >> choice;

    IModifier* modifier = ModifierFactory::createModifier(choice);

    if (modifier == nullptr) {
        cout << "No modifier selected.\n";
    }
    else if (choice == 1) {
        cout << "You bought: Double Score (Next round x2)\n";
    }
    else if (choice == 2) {
        cout << "You bought: Bonus +50 (Next round +50)\n";
    }

    return modifier;
}