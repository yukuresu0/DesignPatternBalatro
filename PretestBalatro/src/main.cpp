#include "RunSession.h"
#include <iostream>

using namespace std;

int main() {

    cout << "Design Pattern Balatro Project\n";

    while (true) {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1) Start Game\n";
        cout << "0) Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            RunSession run;
            run.start();
        }
        else if (choice == 0) {
            cout << "Exiting game...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}