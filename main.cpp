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

class Card {
public:
    char variant;
    int number;

    Card(char v, int n) {
        variant = v;
        number = n;
    }

    int getPoint() {
        return number * 5;
    }

    void display() {
        cout << variant << number;
    }
};

class ShopSystem {
public:
    IModifier* chooseModifier() {
        int choice;
        cout << "\nChoose Modifier:\n";
        cout << "1) Double Score\n";
        cout << "2) Bonus +50\n";
        cout << "0) None\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "You bought: Double Score (Next round x2)\n";
            return new DoubleScoreModifier();
        }
        else if (choice == 2) {
            cout << "You bought: Bonus +50 (Next round +50)\n";
            return new BonusFlatModifier();
        }
        else {
            cout << "No modifier selected.\n";
            return nullptr;
        }
    }
};

class RunSession {
private:
    ScoringSystem scoring;
    ShopSystem shop;
    IModifier* currentModifier = nullptr;

    vector<Card> deck;
    int coins = 0;

public:
    void start() {
        deck.clear();

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

            for (int i = 0; i < 3 && !deck.empty(); i++) {
                hand.push_back(deck.back());
                deck.pop_back();
            }

            cout << "Your cards:\n";
            for (int i = 0; i < hand.size(); i++) {
                cout << i << ": ";
                hand[i].display();
                cout << endl;
            }

            int pick1, pick2;

            while (true) {
                cout << "Pick 2 DIFFERENT card indexes: ";
                cin >> pick1 >> pick2;

                if (pick1 < 0 || pick1 >= hand.size() ||
                    pick2 < 0 || pick2 >= hand.size()) {
                    cout << "Invalid index!\n";
                    continue;
                }

                if (pick1 == pick2) {
                    cout << "Cannot pick same card twice!\n";
                    continue;
                }

                break;
            }

            Card card1 = hand[pick1];
            Card card2 = hand[pick2];

            int point1 = card1.getPoint();
            int point2 = card2.getPoint();
            int baseScore = point1 + point2;

            cout << "\nYou played: ";
            card1.display();
            cout << " (" << point1 << " pts) + ";
            card2.display();
            cout << " (" << point2 << " pts)\n";

            cout << "Base Score: " << baseScore << endl;

            if (card1.number == card2.number ||
                card1.variant == card2.variant) {
                coins += 1;
                cout << "Combo! +1 coin!\n";
            }

            int finalScore = scoring.calculateScore(baseScore, currentModifier);

            if (currentModifier != nullptr)
                cout << "Modifier applied!\n";

            cout << "Final Score: " << finalScore << endl;
            cout << "Coins: " << coins << endl;

            delete currentModifier;
            currentModifier = shop.chooseModifier();
        }

        delete currentModifier;
        currentModifier = nullptr;

        cout << "\nEnd Run\n";
    }
};

int main() {

    cout << "Design Pattern Balatro Project\n";

    RunSession run;
    run.start();

    return 0;
}