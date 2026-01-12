#ifndef INCOM_H
#define INCOM_H

#include <string>
#include <ctime>

using namespace std;
class Income
{
public:
    int processId;
    double amount;
    string source;
    time_t date;
    bool isDeleted;

    Income(int id, double amt, string src, time_t date)
        : processId(id), amount(amt), source(src), date(date), isDeleted(false) {}
};

#endif