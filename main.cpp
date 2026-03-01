#include <vector>
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

class Card {
public:
    char variant;   // A atau B
    int number;     // 1 - 4

    Card(char v, int n) {
        variant = v;
        number = n;
    }

    void display() {
        cout << variant << number;
    }
};



class RunSession {
private:
    ScoringSystem scoring;
    ShopSystem shop;
    IModifier* currentModifier = nullptr;

     vector<Card> deck;


public:
    void start() {
    deck.clear();
        // Create deck
    deck.push_back(Card('A',1));
    deck.push_back(Card('A',2));
    deck.push_back(Card('A',3));
    deck.push_back(Card('A',4));
    deck.push_back(Card('B',1));
    deck.push_back(Card('B',2));
    deck.push_back(Card('B',3));
    deck.push_back(Card('B',4));

        cout << "\nStart Run\n";

        for (int round = 1; round <= 3; round++) {
            cout << "\n=== Round " << round << " ===\n";

    vector<Card> hand;

        // ambil 3 kartu
        for (int i = 0; i < 3; i++) {
        if (!deck.empty()) {
        hand.push_back(deck.back());
        deck.pop_back();
    }
}

            cout << "Your cards:\n";
        for (int i = 0; i < hand.size(); i++) {
        cout << i << ": ";
        hand[i].display();
        cout << endl;
}

    // pilih kartu
            int pick1, pick2;
    cout << "Pick 2 card indexes: ";
    cin >> pick1 >> pick2;

            int baseScore = 0;

        if (pick1 >= 0 && pick1 < hand.size())
        baseScore += hand[pick1].number;

        if (pick2 >= 0 && pick2 < hand.size())
        baseScore += hand[pick2].number;

            int finalScore = scoring.calculateScore(baseScore, currentModifier);

            cout << "Final Score: " << finalScore << endl;

            delete currentModifier; 
            currentModifier = shop.chooseModifier();
        }

        delete currentModifier;
        currentModifier = nullptr;

        cout << "\nEnd Run\n";
    }
};

int main() {

    cout << "Design Pattern Balatro Project" << endl;

    RunSession run;
    run.start();

    return 0;
}