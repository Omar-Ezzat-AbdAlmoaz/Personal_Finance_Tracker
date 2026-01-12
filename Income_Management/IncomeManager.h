#ifndef INCOMMANAGER_H
#define INCOMMANAGER_H

#include "../Manager.h"
#include "Income.h"

#include <iostream>
#include <stack>

using namespace std;
class IncomeManager
{
private:
    Manager &manager;
    int nextProcessId;
    stack<int> deletedIds;

public:
    IncomeManager(Manager &manager) : manager(manager)
    {
        nextProcessId = 1;
        deletedIds = stack<int>();
    };

    void addIncome(double amount, string &source, string &date)
    {
        if (!manager.validateIncome(amount, date, source))
        {
            return;
        }

        time_t dt = manager.convertStringToDate(date);

        if (!deletedIds.empty())
        {
            int index = deletedIds.top() - 1;
            deletedIds.pop();

            manager.incomes[index].amount = amount;
            manager.incomes[index].date = dt;
            manager.incomes[index].source = source;
            manager.incomes[index].isDeleted = false;
        }
        else
        {
            manager.incomes.push_back(
                Income(nextProcessId++, amount, source, dt));
        }
        manager.totalIncomes += amount;

        cout << "Income Added Successfully\n";
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

        manager.totalIncomes -= manager.incomes[index].amount;

        manager.incomes[index].amount = amount;

        manager.totalIncomes += amount;

        cout << "Amount of Income " << processId << " Updated Successfully\n";
    }

    void UpdateSource(int processId, string &source)
    {
        int index = processId - 1;
        if (!manager.validateID(index))
        {
            return;
        }

        if (!manager.validateSource(source))
        {
            return;
        }

        manager.incomes[index].source = source;

        cout << "Source of Income " << processId << " Updated Successfully\n";
    }

    void UpdateDate(int processId, string &date)
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

        manager.incomes[index].date = dt;

        cout << "Date of Income " << processId << " Updated Successfully\n";
    }

    // void updateIncome(int processId, double amount, string source, string date)
    // {
    //     int index = processId - 1;
    //     if (!validateID(index)){
    //         return;
    //     }

    //     if (!validateIncome(amount, date, source)){
    //         return;
    //     }

    //     UpdateAmount(processId, amount);
    //     UpdateSource(processId, source);
    //     UpdateDate(processId, date);

    //     cout << "Income " << processId << " Updated Successfully\n";
    // }

    void deleteIncome(int processId)
    {
        int index = processId - 1;
        if (!manager.validateID(index))
            return;

        double amount = manager.incomes[index].amount;
        if(!manager.checkIncomeAfterDelete(amount)){
            cout << "Income " << processId << " Cannot be Deleted, You expense money already and Total Incomes will be less than Total Expenses\n";
            return;
        }

        manager.incomes[index].isDeleted = true;
        manager.totalIncomes -= amount;
        deletedIds.push(processId);

        cout << "Income " << processId << " Deleted Successfully\n";
    }

    
};

#endif