#include "Income_Management/IncomeManager.h"
#include "Expanse_Management/ExpanseManager.h"
#include "Budget_Management/BudgetManager.h"
#include "Report_Management/ReportManager.h"
#include "Utilies/InputValidator.h"
#include "Utilies/FileManager.h"

#include <iostream>
#include <limits>

using namespace std;

void showMainMenu()
{
    cout << "\n====================================\n";
    cout << "   Personal Finance Tracker System  \n";
    cout << "====================================\n";

    cout << "\n[ Income ]\n";
    cout << " 1) Add Income\n";
    cout << " 2) Update Income\n";
    cout << " 3) Delete Income\n";

    cout << "\n[ Expenses ]\n";
    cout << " 4) Add Expense\n";
    cout << " 5) Update Expense\n";
    cout << " 6) Delete Expense\n";

    cout << "\n[ Budget ]\n";
    cout << " 7) Set Budget\n";

    cout << "\n[ Reports ]\n";
    cout << " 8) View Incomes\n";
    cout << " 9) View Expenses\n";
    cout << "10) View Budgets\n";
    cout << "11) Net Balance\n";
    cout << "12) Search By Category\n";
    cout << "13) Search By Date\n";

    cout << "\n 0) Exit\n";
    cout << "------------------------------------\n";
}

string askForDate(Manager& manager)
{
    char ch = InputValidator::readYesNo("Use current date? (Y/N): ");
    if (ch == 'Y' || ch == 'y')
    {
        string d = manager.getCurrentDate();
        cout << "Date set to: " << d << "\n";
        return d;
    }
    return InputValidator::readString("Enter Date (YYYY-MM-DD): ");
}

void pause()
{
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}


int main()
{
    Manager manager = Manager();  
    FileManager::loadAll(manager);

    IncomeManager incomeMgr = IncomeManager(manager);
    ExpanseManager expanseMgr = ExpanseManager(manager);
    BudgetManager budgetMgr = BudgetManager(manager);
    ReportManager reportMgr = ReportManager(manager);

    int choice = -1;
    char ch;

    int processId;
    double amount;
    string source, date, category;
    pair<string, string> datePeriod;

    while (choice != 0)
    {
        showMainMenu();
        choice = InputValidator::readInt("Enter Your Choice: ");

        switch (choice)
        {
        case 1:
        {
            amount = InputValidator::readDouble("Enter Income Amount: ");
            source = InputValidator::readString("Enter Income Source: ");           
            date = askForDate(manager);

            incomeMgr.addIncome(amount, source, date);

            pause();
            break;
        }

        case 2:
        {
            processId = InputValidator::readInt("Enter Income Process ID To Update: ");
            if (!manager.validateID(processId - 1))
            {
                pause();
                break;
            }
            cout << "\nWhat do you want to update?\n";
            cout << "1) Amount\n";
            cout << "2) Source\n";
            cout << "3) Date\n";
            cout << "0) Finish\n";

            int opt;
            do {
                opt = InputValidator::readInt("Choice: ");
                switch(opt) {
                    case 1:
                        amount = InputValidator::readDouble("New Amount: ");
                        incomeMgr.UpdateAmount(processId, amount);
                        break;
                    case 2:
                        source = InputValidator::readString("New Source: ");
                        incomeMgr.UpdateSource(processId, source);
                        break;
                    case 3:
                        date = askForDate(manager);
                        incomeMgr.UpdateDate(processId, date);
                        break;
                }
                if(opt != 0){
                    cout << "\nChoice do you another update or finish?\n";
                    cout << "1) Amount\n";
                    cout << "2) Source\n";
                    cout << "3) Date\n";
                    cout << "0) Finish\n";
                }
            } while(opt != 0);

            pause();
            break;
        }
        case 3:
        {
            processId = InputValidator::readInt("Enter Income Process ID To Delete: ");
            incomeMgr.deleteIncome(processId);

            pause();
            break;
        }

        case 4:
        {
            amount = InputValidator::readDouble("Enter Expanse Amount: ");
            category = InputValidator::readString("Enter Expanse Category: ");
            date =askForDate(manager);

            expanseMgr.addExpanse(amount, category, date);

            pause();
            break;
        }
        case 5:
        {
            processId = InputValidator::readInt("Enter Expanse Process ID To Update: ");
            if (!manager.validateID(processId - 1))
            {
                pause();
                break;
            }
            cout << "\nWhat do you want to update?\n";
            cout << "1) Amount\n";
            cout << "2) Category\n";
            cout << "3) Date\n";
            cout << "0) Finish\n";

            int opt;
            do {
                opt = InputValidator::readInt("Choice: ");
                switch(opt) {
                    case 1:
                        amount = InputValidator::readDouble("New Amount: ");
                        expanseMgr.UpdateAmount(processId, amount);
                        break;
                    case 2:
                        category = InputValidator::readString("New Category: ");
                        expanseMgr.UpdateCategory(processId, category);
                        break;
                    case 3:
                        date = askForDate(manager);
                        expanseMgr.UpdateDate(processId, date);
                        break;
                    default:
                        cout << "Please Enter Valid Choice From 1 To 3!\n";
                        break;
                }
                if(opt != 0){
                    cout << "\nChoice do you another update or finish?\n";
                    cout << "1) Amount\n";
                    cout << "2) Category\n";
                    cout << "3) Date\n";
                    cout << "0) Finish\n";
                }
            } while(opt != 0);

            pause();
            break;
        }
        case 6:
        {
            processId = InputValidator::readInt("Enter Expanse Process ID To Delete: ");
            expanseMgr.deleteExpanse(processId);

            pause();
            break;
        }

        case 7:
        {
            category = InputValidator::readString("Enter Budget Category: ");
            amount = InputValidator::readDouble("Enter Budget Amount: ");
            budgetMgr.setBudget(amount, category);

            pause();
            break;
        }
        case 8:
            reportMgr.viewIncomes();

            pause();
            break;
        case 9:
            reportMgr.viewExpanses();

            pause();
            break;
        case 10:
            reportMgr.viewBudgets();

            pause();
            break;
        case 11:
            reportMgr.getNetBalance();

            pause();
            break;
        case 12:
        {
            category = InputValidator::readString("Enter Category To Search: ");
            reportMgr.searchByCategory(category);

            pause();
            break;
        }
        case 13:
        {
            datePeriod.first = InputValidator::readString("Enter Start Date To Search (YYYY-MM-DD): ");
            datePeriod.second = askForDate(manager);
            reportMgr.searchByDatePeriod(datePeriod);

            pause();
            break;
        }
        case 0:
            break;
        default:
            cout << "Please Enter Valid Choice From 1 To 13!\n";
        }
    }
    FileManager::saveAll(manager);

    return 0;
}