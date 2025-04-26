#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include "NADRA.h"
using namespace std;

int main() {
    int choice;
    NADRA management;
    while (true) {
        cout << "\nNADRA Database Management System\n";
        cout << "1. Input Records\n";
        cout << "2. Update Record\n";
        cout << "3. Delete Record\n";
        cout << "4. Search Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            management.input();
            break;
        case 2:
            management.update();
            break;
        case 3:
            management.del();
            break;
        case 4:
            management.search();
            break;
        case 5:
            cout << "Exiting the NADRA system.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
