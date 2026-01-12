#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <string>
#include <limits>
using namespace std;

class InputValidator {
public:
    static int readInt(const string& msg);
    static double readDouble(const string& msg);
    static string readString(const string& msg);
    static char readYesNo(const string& msg);
};

#endif
