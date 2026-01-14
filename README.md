💰 Personal Finance Tracker (Console Application)
📌 Overview

Personal Finance Tracker is a C++ console-based application designed to help users manage their personal finances efficiently.
The application allows users to track incomes and expenses, manage budgets, generate financial reports, and persist data between sessions using file storage.

🎯 Purpose

The goal of this project is to provide a simple yet powerful console application for:

Monitoring income and expenses

Controlling spending through budgets

Generating financial summaries and reports

Preserving financial data between application runs

🔍 Features
✅ Income Management

Add income entries (amount, source, date)

View all income records

Update or delete existing income entries

✅ Expense Management

Add expense entries (amount, category, date)

View all expense records

Update or delete existing expense entries

✅ Budget Tracking

Set budgets for expense categories

Monitor spending against budgets

Receive alerts when budget limits are reached or exceeded

✅ Financial Reports

View total income, total expenses, and net balance

Generate detailed reports by:

Category

Date range

✅ Notifications

Budget limit warnings

Overspending alerts

✅ Data Persistence (Bonus Feature)

Save all financial data to files

Automatically load data when the application starts

Ensures no data loss between sessions

🧑‍💻 User Type

General User

No advanced technical knowledge required

Basic familiarity with console applications is sufficient

🛠️ Technical Details
Item	Description
Programming Language	C++
Application Type	Console-based
Platform	Windows / Linux / macOS
IDE	Any C++ compatible editor
Data Storage	Text files
Date Handling	time_t
⚙️ Functional Requirements
Income & Expense

Add, view, update, and delete entries

Each entry contains amount, category/source, and date

Budget

Assign budgets per category

Track spending in real time

Notify users when limits are reached

Reports

Summary reports (income, expenses, balance)

Detailed reports by category or time period

Persistence

Save all data before program exit

Load all saved data at program startup

📈 Non-Functional Requirements

Performance: Efficient handling of up to 1,000 records

Reliability: Safe file read/write operations

Usability: Clear menu-driven console interface

Maintainability: Modular, clean, and well-structured codebase

▶️ How to Run

Clone the repository:

git clone https://github.com/Omar-Ezzat-AbdAlmoaz/Personal_Finance_Tracker


Compile the project:

g++ *.cpp -o finance_tracker


Run the application:

./finance_tracker
