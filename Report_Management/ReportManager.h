#ifndef REPORT_MANAGER_H
#define REPORT_MANAGER_H

#include "../Manager.h"
#include <iostream>

using namespace std;
class ReportManager
{
private:
    Manager &manager;

public:
    ReportManager(Manager &manager) : manager(manager) {};

    void viewIncomes()
    {
        cout << "---- Income List ----\n";
        for (auto &inc : manager.incomes)
        {

            if (!inc.isDeleted)
            {
                DisplayIncome(inc.processId - 1);
            }
        }

        cout << "Total Income: " << manager.totalIncomes << "\n";
    }
    void DisplayIncome(int processId){
        auto &inc = manager.incomes[processId];
        string Date = manager.convertDateToString(inc.date);
        cout << "ID: " << inc.processId
             << " | Amount: " << inc.amount
             << " | Source: " << inc.source
             << " | Date: " << Date << "\n";
        cout << "==========================================================================\n";
    }


    void viewExpanses()
    {
        cout << "---- Expanse List ----\n";
        for (auto &exp : manager.expanses)
        {
            if (!exp.isDeleted)
            {
                DisplayExpanse(exp.processId - 1);
            }
        }

        cout << "Total Expanse: " << manager.totalExpenses << "\n";
    }
    void DisplayExpanse(int processId){
        auto &exp = manager.expanses[processId];
        string Date = manager.convertDateToString(exp.date);
        cout << "ID: " << exp.processId
             << " | Amount: " << exp.amount
             << " | Category: " << exp.category
             << " | Date: " << Date << "\n";
        cout << "==========================================================================\n";
    }


    void viewBudgets()
    {
        cout << "---- Budget List ----\n";
        for (auto &budget : manager.budgets)
        {
            if(budget.second.budget){
                cout << "Category: " << budget.first << " | Budget: " << budget.second.budget
                     << " | Total Spend: " << budget.second.TotalSpend << " | Limit: " << budget.second.Limit << "\n";
                cout << "==========================================================================\n";
            }
        }
    }


    void getNetBalance(){
        cout << "Total Incomes:  " << manager.totalIncomes << "\n";
        cout << "Total Expenses: " << manager.totalExpenses << "\n";
        cout << "Net Balance: " << manager.totalIncomes - manager.totalExpenses << "\n";
    }

    void searchByCategory(string &category){
        if (!manager.validateCategory(category))
        {
            return;
        }
        auto cat = manager.getCategory(category);
        if(cat == manager.budgets.end()){
            cout << "Category Not Found\n";
            return;
        }
        cout << "Category: " << cat->first << " | Budget: " << cat->second.budget
             << " | Total Spend: " << cat->second.TotalSpend << " | Limit: " << cat->second.Limit << "\n";
        cout << "==========================================================================\n";

        for(auto &exp : manager.expanses){
            if(exp.category == category && !exp.isDeleted){
                string Date = manager.convertDateToString(exp.date);
                cout << "ID: " << exp.processId
                     << " | Amount: " << exp.amount
                     << " | Category: " << exp.category
                     << " | Date: " << Date << "\n";
                cout << "==========================================================================\n";
            }
        }
    }
    void searchByDatePeriod(pair<string, string> &datePeriod){

        if(!manager.validateTimePeriod(datePeriod)){
            return;
        }

        time_t dt1 = manager.convertStringToDate(datePeriod.first);
        time_t dt2 = manager.convertStringToDate(datePeriod.second);

        double totalIncome = 0;
        double totalExpanse = 0;
        cout << "\n---- Income List Between " << manager.convertDateToString(dt1) << " And " << manager.convertDateToString(dt2) << "----\n";
        for(auto &inc : manager.incomes){
            if(!inc.isDeleted && inc.date >= dt1 && inc.date <= dt2){
                DisplayIncome(inc.processId - 1);
                totalIncome += inc.amount;
            }
        }
        cout << "Total Income: " << totalIncome << "\n\n";

        cout << "\n---- Expanse List Between " << manager.convertDateToString(dt1) << " And " << manager.convertDateToString(dt2) << "----\n";
        for(auto &exp : manager.expanses){
            if(!exp.isDeleted && exp.date >= dt1 && exp.date <= dt2){
                DisplayExpanse(exp.processId - 1);
                totalExpanse += exp.amount;
            }
        }
        cout << "Total Expanse: " << totalExpanse << "\n\n";

        cout << "\nNet Balance: " << totalIncome - totalExpanse << "\n\n";
    }

    
    
    ~ReportManager() {};
};

#endif