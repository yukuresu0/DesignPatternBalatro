#include <iostream>
using namespace std;

    class IModifier {
public:
    virtual int apply(int baseScore) = 0;
    virtual ~IModifier() {}
};

class DoubleScoreModifier : public IModifier {
public:
    int apply(int baseScore) override {
        return baseScore * 2;
    }
};

class BonusFlatModifier : public IModifier {
public:
    int apply(int baseScore) override {
        return baseScore + 50;
    }
};

class ScoringSystem {
public:
    int calculateScore(int baseScore, IModifier* modifier) {
        if (modifier != nullptr) {
            return modifier->apply(baseScore);
        }
        return baseScore;
    }
};

class ShopSystem {
public:
    IModifier* chooseModifier() {
        int choice;
        cout << "Choose Modifier: (1) Double Score (2) Bonus +50 (0) None: ";
        cin >> choice;

        if (choice == 1)
            return new DoubleScoreModifier();
        else if (choice == 2)
            return new BonusFlatModifier();
        else
            return nullptr;
    }
};

class RunSession {
private:
    ScoringSystem scoring;
    ShopSystem shop;
    IModifier* currentModifier = nullptr;

public:
    void start() {
        cout << "\nStart Run\n";

        for (int round = 1; round <= 3; round++) {
            cout << "\n=== Round " << round << " ===\n";

            cout << "Playing hand...\n";

            int baseScore = round * 10;

            int finalScore = scoring.calculateScore(baseScore, currentModifier);

            cout << "Final Score: " << finalScore << endl;

            delete currentModifier; 
            currentModifier = shop.chooseModifier();
        }

        cout << "\nEnd Run\n";
    }
};

int main() {

    cout << "Design Pattern Balatro Project" << endl;

    RunSession run;
    run.start();

    return 0;
}