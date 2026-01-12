#ifndef EXPANSE_H
#define EXPANSE_H

#include <string>
#include <ctime>

using namespace std;
class Expanse
{
public:
    int processId;
    double amount;
    string category;
    time_t date;
    bool isDeleted;

    Expanse(int id, double amt, string cat, time_t date)
        : processId(id), amount(amt), category(cat), date(date), isDeleted(false) {}
};

#endif