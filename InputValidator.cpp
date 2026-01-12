#include "InputValidator.h"
#include <iostream>
#include <limits>

int InputValidator::readInt(const string& msg) {
    int value;
    while (true) {
        cout << msg;
        cin >> value;

        if (!cin.fail())
            return value;

        cout << "Invalid input. Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double InputValidator::readDouble(const string& msg) {
    double value;
    while (true) {
        cout << msg;
        cin >> value;

        if (!cin.fail())
            return value;

        cout << "Invalid input. Please enter a valid amount.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string InputValidator::readString(const string& msg) {
    string value;
    cout << msg;
    cin >> value;   
    return value;
}

char InputValidator::readYesNo(const string& msg) {
    char c;
    while (true) {
        cout << msg;
        cin >> c;

        if (c == 'Y' || c == 'y' || c == 'N' || c == 'n')
            return c;

        cout << "Please enter Y or N only.\n";
    }
}
