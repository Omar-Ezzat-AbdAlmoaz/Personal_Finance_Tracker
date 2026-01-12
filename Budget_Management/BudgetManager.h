#ifndef BUDGET_MANAGER_H
#define BUDGET_MANAGER_H

#include "../Manager.h"
#include "Category.h"
#include <string>

using namespace std;
class BudgetManager
{
public:
    Manager &manager;

    BudgetManager(Manager &manager) : manager(manager) {}

    void setBudget(double budget, string &category)
    {
        if (!manager.validateAmount(budget))
        {
            return;
        }
        if (!manager.validateCategory(category))
        {
            return;
        }

        auto it = manager.getCategory(category);
        if (it != manager.budgets.end())
        {
            it->second.setBudget(budget);
        }
        else
        {
            manager.budgets.insert({category, Category(category, budget)});
        }

        cout << "Budget For Category: " << category << " Set Successfully\n";
    }


    
};
#endif