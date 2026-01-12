#ifndef EXPANSEMANAGER_H
#define EXPANSEMANAGER_H

#include "../Manager.h"
#include "Expanse.h"

#include <iostream>
#include <stack>

using namespace std;
class ExpanseManager
{
private:
    Manager &manager;
    int nextProcessId;
    stack<int> deletedIds;

public:
    ExpanseManager(Manager &manager) : manager(manager)
    {
        nextProcessId = 1;
        deletedIds = stack<int>();
    }

    void addExpanse(double amount, string& category, string& date)
    {
        if (!manager.validateExpanse(amount, date, category))
        {
            return;
        }
        
        if (!manager.checkIncomeEnough(amount))
        {
            cout << "Not enough Income to add this Expanse\n";
            return;
        }

        auto it = manager.getCategory(category);
        if (it == manager.budgets.end())
        {
            manager.budgets.insert({category, Category(category)});
            it = manager.getCategory(category);
            it->second.TotalSpend = amount;
        }else{
            it->second.TotalSpend += amount;
            manager.notify(category);
        }

        time_t dt = manager.convertStringToDate(date);

        if (!deletedIds.empty())
        {
            int index = deletedIds.top() - 1;
            deletedIds.pop();

            manager.expanses[index].amount = amount;
            manager.expanses[index].category = category;
            manager.expanses[index].date = dt;
            manager.expanses[index].isDeleted = false;
        }
        else
        {
            manager.expanses.push_back(
                Expanse(nextProcessId++, amount, category, dt));
        }
        manager.totalExpenses += amount;

        cout << "Expanse Added Successfully\n";
    }

    void UpdateAmount(int processId, double amount)
    {
        int index = processId - 1;
        if (!manager.validateID(index))
        {
            return;
        }

        if (!manager.validateAmount(amount))
        {
            return;
        }
        double oldAmount = manager.expanses[index].amount;

        manager.totalExpenses -= oldAmount;

        if (!manager.checkIncomeEnough(amount))
        {
            manager.totalExpenses += oldAmount;
            cout << "Not enough Income to add this Expanse Amount\n";
            return;
        }
        string cat = manager.expanses[index].category;
        auto it = manager.getCategory(cat);
        if (it != manager.budgets.end())
        {
            it->second.TotalSpend -= oldAmount;
            it->second.TotalSpend += amount;
            manager.notify(cat);
        }

        manager.expanses[index].amount = amount;
        manager.totalExpenses += amount;

        cout << "Amount of Expanse " << processId << " Updated Successfully\n";
    }

    void UpdateCategory(int processId, string& category)
    {
        int index = processId - 1;
        if (!manager.validateID(index))
        {
            return;
        }

        if (!manager.validateCategory(category))
        {
            return;
        }
        string oldCategory = manager.expanses[index].category;
        auto it = manager.getCategory(oldCategory);
        if (it != manager.budgets.end())
        {
            it->second.TotalSpend -= manager.expanses[index].amount;
        }

        manager.expanses[index].category = category;
        it = manager.getCategory(category);
        if (it != manager.budgets.end())
        {
            it->second.TotalSpend += manager.expanses[index].amount;
            manager.notify(category);
        }
        else
        {
            manager.budgets.insert({category, Category(category)});
            it = manager.getCategory(category);
            it->second.TotalSpend = manager.expanses[index].amount;
        }

        cout << "Category of Expanse " << processId << " Updated Successfully\n";
    }

    void UpdateDate(int processId, string& date)
    {
        int index = processId - 1;
        if (!manager.validateID(index))
        {
            return;
        }

        if (!manager.validateDate(date))
        {
            return;
        }

        time_t dt = manager.convertStringToDate(date);

        manager.expanses[index].date = dt;

        cout << "Date of Expanse " << processId << " Updated Successfully\n";
    }

    void deleteExpanse(int processId)
    {
        int index = processId - 1;
        if (!manager.validateID(index))
            return;

        manager.expanses[index].isDeleted = true;
        manager.totalExpenses -= manager.expanses[index].amount;
        deletedIds.push(processId);

        string cat = manager.expanses[index].category;
        auto it = manager.getCategory(cat);
        if (it != manager.budgets.end())
        {
            it->second.TotalSpend -= manager.expanses[index].amount;
        }

        cout << "Expanse " << processId << " Deleted Successfully\n";
    }
    
};

#endif
