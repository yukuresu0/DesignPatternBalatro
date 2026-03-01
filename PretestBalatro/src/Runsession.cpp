#include "RunSession.h"
#include <iostream>

using namespace std;

class Card {
public:
    char variant;
    int number;

    Card(char v, int n) : variant(v), number(n) {}

    int getPoint() {
        return number * 5;
    }

    void display() {
        cout << variant << number;
    }
};

void RunSession::start() {

    vector<Card> deck;

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
            cout << "Pick 2 DIFFERENT card indexes (-1 to quit run): ";
            cin >> pick1;

            if (pick1 == -1) {
                cout << "You quit the run.\n";
                return;
            }

            cin >> pick2;

            if (pick2 == -1) {
                cout << "You quit the run.\n";
                return;
            }

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

        int baseScore = card1.getPoint() + card2.getPoint();

        cout << "\nYou played: ";
        card1.display();
        cout << " + ";
        card2.display();
        cout << endl;

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