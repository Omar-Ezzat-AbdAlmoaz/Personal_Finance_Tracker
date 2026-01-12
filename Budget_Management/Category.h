#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

using namespace std;
class Category
{
public:
    string name;
    double budget;
    double Limit;
    double TotalSpend;

    Category(string name) : name(name) {
        budget = 0;
        Limit = 0;
        TotalSpend = 0;
    }
    Category(string name, double budget) : name(name), budget(budget) {
        Limit = budget * 0.9;
        TotalSpend = 0;
    }

    void setBudget(double budget){
        this->budget = budget;
        Limit = budget * 0.9;
    }
  
};

#endif