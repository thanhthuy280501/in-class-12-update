#include <iostream>
#include "llist.h"

using namespace std;

int main() {
    LList<int> L1;  // Integer linked list
    string choice;
    int tmp;

    cout << "Options are insert, append, remove, search, sortedInsert, print." << endl;

    while (true) {
        cout << "Enter a choice (or 'quit'): ";
        cin >> choice;
        if (choice == "quit") break;

        if (choice == "insert") {
            cin >> tmp;
            L1.insert(tmp);
            L1.print();
        } else if (choice == "append") {
            cin >> tmp;
            L1.append(tmp);
            L1.print();
        } else if (choice == "search") {
            cin >> tmp;
            if (L1.search(tmp))
                cout << "Found " << tmp << endl;
            else
                cout << "Not found." << endl;
        } else if (choice == "sortedInsert") {
            cin >> tmp;
            L1.sortedInsert(tmp);
            L1.print();
        } else if (choice == "remove") {
            if (L1.remove(tmp))
                cout << "Removed " << tmp << endl;
            else
                cout << "Remove failed." << endl;
            L1.print();
        } else if (choice == "print") {
            L1.print();
        }
    }

    return 0;
}
