#ifndef MANAGER_H
#define MANAGER_H

#include "Income_Management/Income.h"
#include "Expanse_Management/Expanse.h"
#include "Budget_Management/Category.h"

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <regex>
#include <map>

using namespace std;

class Manager
{
public:
    double totalIncomes;
    vector<Income> incomes;

    double totalExpenses;
    vector<Expanse> expanses;

    map<string, Category> budgets;

    time_t now;

    Manager()
    {
        now = time(0);
        totalIncomes = 0;
        totalExpenses = 0;
    }

    bool checkIncomeEnough(double amountExpanse)
    {
        return totalIncomes >= amountExpanse + totalExpenses;
    }

    bool checkIncomeAfterDelete(double amountIncome){
        return totalIncomes - amountIncome >= totalExpenses;
    }

    auto getCategory(string &category)
    {
        return budgets.find(category);
    }

    void notify(string &category)
    {
        auto it = getCategory(category);
        if (it == budgets.end())
            return;

        Category &cat = it->second;

        if (cat.Limit == 0 || cat.budget == 0)
            return;

        if (cat.TotalSpend > cat.budget)
        {
            cout << "Budget Exceeded for Category: " << category << "\n";
        }
        else if (cat.TotalSpend > cat.Limit)
        {
            cout << "Budget Limit Exceeded for Category: " << category << "\n";
        }
    }

    // int getYear(string &data)
    // {
    //     return stoi(data.substr(0, 4));
    // }

    // int getMonth(string &data)
    // {
    //     return stoi(data.substr(5, 7));
    // }

    // int getDay(string &data)
    // {
    //     return stoi(data.substr(8, 10));
    // }

    bool validateID(int index)
    {

        if (index < 0 || index >= incomes.size() || incomes[index].isDeleted)
        {
            cout << "Invalid Income ID\n";
            return false;
        }

        return true;
    }

    bool validateIncome(double amount, string &date, string &source)
    {
        if (!validateAmount(amount))
            return false;

        if (!validateSource(source))
            return false;

        if (!validateDate(date))
            return false;

        return true;
    }
    bool validateExpanse(double amount, string &date, string &category)
    {
        if (!validateAmount(amount))
            return false;

        if (!validateCategory(category))
            return false;

        if (!validateDate(date))
            return false;

        return true;
    }

    bool validateAmount(double amount)
    {
        if (amount <= 0)
        {
            cout << "Amount Should be greater than 0.\n";
            return false;
        }

        return true;
    }

    bool validateSource(string &source)
    {
        if (source.empty())
        {
            cout << "Source cannot be empty.\n";
            return false;
        }
        if (source.find(',') != string::npos) {
            cout << "Invalid input: ',' is not allowed.\n";
            return false;
        }

        return true;
    }
    bool validateCategory(string &category)
    {
        if (category.empty())
        {
            cout << "Category cannot be empty.\n";
            return false;
        }

        if (category.find(',') != string::npos) {
            cout << "Invalid input: ',' is not allowed.\n";
            return false;
        }

        return true;
    }

    bool validateDate(const string &date)
    {
        regex re(R"(^\d{4}-\d{2}-\d{2}$)");
        if (!regex_match(date, re))
        {
            cout << "Invalid date format. Use YYYY-MM-DD\n";
            return false;
        }

        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        if (month < 1 || month > 12)
        {
            cout << "Invalid month value, month should be between 1 and 12\n";
            return false;
        }

        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (month == 2)
        {
            bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (leap)
                daysInMonth[1] = 29;
        }

        if (day < 1 || day > daysInMonth[month - 1])
        {
            cout << "Invalid day value, day should be between 1 and " << daysInMonth[month - 1] << "\n";
            return false;
        }

        return true;
    }

    bool validateTimePeriod(pair<string, string> &datePeriod)
    {
        if(!validateDate(datePeriod.first) || !validateDate(datePeriod.second))
            return false;

        time_t dt1 = convertStringToDate(datePeriod.first);
        time_t dt2 = convertStringToDate(datePeriod.second);

        if(dt1 > dt2){
            cout << "Invalid Date Period, Start Date should be less than End Date\n";
            return false;
        }

        return true;
    }

    string getCurrentDate()
    {
        now = time(0);
        tm *localTime = localtime(&now);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", localTime);
        return string(buffer);
    }

    time_t convertStringToDate(string &date)
    {
        tm tmDate = {};
        istringstream ss(date);
        ss >> get_time(&tmDate, "%Y-%m-%d");

        if (ss.fail())
        {
            throw runtime_error("Invalid date format");
        }

        tmDate.tm_hour = 0;
        tmDate.tm_min  = 0;
        tmDate.tm_sec  = 0;

        return mktime(&tmDate);
    }

    string convertDateToString(time_t date)
    {
        tm tm = *localtime(&date);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
        return string(buffer);
    }

    ~Manager() {}
};

#endif