#include "Utilies/FileManager.h"
#include "Manager.h"
#include "Income_Management/Income.h"
#include "Expanse_Management/Expanse.h"
#include "Budget_Management/Category.h"
#include <iostream>
#include <fstream>
using namespace std;

string IncomeFilePath = "Files/incomes.txt";
string ExpanseFilePath = "Files/expenses.txt";
string BudgetFilePath = "Files/budgets.txt";

vector<Income> loadIncomesFromFile() {
    vector<Income> result;
    ifstream file(IncomeFilePath);

    if (!file.is_open()) {
        return result; 
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        int id;
        double amount;
        string source;
        time_t date;
        int isDeleted;

        string temp;

        getline(ss, temp, ',');
        id = stoi(temp);

        getline(ss, temp, ',');
        amount = stod(temp);

        getline(ss, source, ',');

        getline(ss, temp, ',');
        date = static_cast<time_t>(stoll(temp));

        getline(ss, temp, ',');
        isDeleted = stoi(temp);

        Income inc(id, amount, source, date);
        inc.isDeleted = isDeleted;

        result.push_back(inc);
    }

    file.close();
    return result;
}


vector<Expanse> loadExpensesFromFile() {
    vector<Expanse> result;
    ifstream file(ExpanseFilePath);

    if (!file.is_open()) {
        return result; 
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        int id;
        double amount;
        string category;
        time_t date;
        int isDeleted;

        string temp;

        getline(ss, temp, ',');
        id = stoi(temp);

        getline(ss, temp, ',');
        amount = stod(temp);

        getline(ss, category, ',');

        getline(ss, temp, ',');
        date = static_cast<time_t>(stoll(temp));

        getline(ss, temp, ',');
        isDeleted = stoi(temp);

        Expanse exp(id, amount, category, date);
        exp.isDeleted = isDeleted;

        result.push_back(exp);
    }

    file.close();
    return result;
}

map<string, Category> loadBudgetsFromFile() {
    map<string, Category> result;
    ifstream file(BudgetFilePath);

    if (!file.is_open()) {
        return result; 
    }
    
    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        string category;
        double budget;

        string temp;

        getline(ss, category, ',');

        getline(ss, temp, ',');
        budget = stod(temp);

        Category cat(category, budget);

        result.insert({category, cat});
    }

    file.close();
    return result;
}

void calcTotals(Manager& manager) {
    for(auto& income : manager.incomes)
        if(!income.isDeleted)
            manager.totalIncomes += income.amount;
    for(auto& expanse : manager.expanses)
        if(!expanse.isDeleted)
            manager.totalExpenses += expanse.amount;

}

void saveIncomesToFile(const vector<Income>& incomes) {
    ofstream file(IncomeFilePath);

    for (const auto& income : incomes) {
        file << income.processId << "," << income.amount << "," << income.source << "," << income.date << "," << income.isDeleted << "\n";
    }
    file.close();
}

void saveExpensesToFile(const vector<Expanse>& expenses) {
    ofstream file(ExpanseFilePath);

    for (const auto& expense : expenses) {
        file << expense.processId << "," << expense.amount << "," << expense.category << "," << expense.date << "," << expense.isDeleted << "\n";
    }
    file.close();
}

void saveBudgetsToFile(const map<string, Category>& budgets) {
    ofstream file(BudgetFilePath);

    for (const auto& budget : budgets) {
        file << budget.first << "," << budget.second.budget << "\n";
    }
    file.close();
}

void FileManager::loadAll(Manager& manager) {
    manager.incomes = loadIncomesFromFile();
    manager.expanses = loadExpensesFromFile();
    manager.budgets  = loadBudgetsFromFile();

    calcTotals(manager);

    cout << "\nData Loaded Successfully!\n";
}

void FileManager::saveAll(Manager& manager) {
    saveIncomesToFile(manager.incomes);
    saveExpensesToFile(manager.expanses);
    saveBudgetsToFile(manager.budgets);

    cout << "\nData Saved Successfully!\n";
}