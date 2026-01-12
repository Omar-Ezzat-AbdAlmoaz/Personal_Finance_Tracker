Software Requirements Specification (SRS) for Personal Finance Tracker
1. Introduction
1.1 Purpose
The purpose of this document is to outline the requirements for a Personal Finance Tracker console application. This software will help users manage their finances by tracking income, expenses, and budgets, generating reports, and offering notifications for budget limits.
1.2 Scope
The Personal Finance Tracker will allow users to add and categorize income and expenses, view summaries of their financial activity, set and track budgets, and receive notifications when budgets are exceeded. 
1.3 Definitions, Acronyms, and Abbreviations
Income: Money received by the user, categorized by source.
Expense: Money spent by the user, categorized by purpose.
Budget: A predefined spending limit set by the user for specific categories.
Report: A summary of income, expenses, and budget status.

2. Overall Description
2.1 Product Perspective
The Personal Finance Tracker is a standalone console application.
2.2 Product Functions
Income Management: Add, update, and view income entries.
Expense Management: Add, update, and view expense entries.
Budget Tracking: Set and monitor budgets for different expense categories.
Financial Reports: Generate and view financial summaries and detailed reports.
Notifications: Alert the user when they are close to or exceed their budget.
Data Persistence (Bonus) : Save and load data from a file for persistence between sessions.
2.3 User Classes and Characteristics
General User: An individual using the application to manage personal finances. No advanced technical knowledge is required.
2.4 Operating Environment
Platform: Windows, Linux, or macOS
Development Language: C++
IDE: any editor
2.5 Design and Implementation Constraints
The application will be console-based, limiting user interaction to text commands.
2.6 Assumptions and Dependencies
Users have basic knowledge of operating a console application.

3. System Features
3.1 Income Management
3.1.1 Description and Priority
Users can add, view, and update their income entries. This feature has high priority as it is a core aspect of financial tracking.
3.1.2 Functional Requirements
FR1: The system shall allow users to add income entries with details like amount, source, and date.
FR2: The system shall allow users to view a list of all income entries.
FR3: The system shall allow users to update or delete existing income entries.

3.2 Expense Management
3.2.1 Description and Priority
Users can add, view, and update their expense entries. This feature is also high priority.
3.2.2 Functional Requirements
FR4: The system shall allow users to add expense entries with details like amount, category, and date.
FR5: The system shall allow users to view a list of all expense entries.
FR6: The system shall allow users to update or delete existing expense entries.

3.3 Budget Tracking
3.3.1 Description and Priority
Users can set budgets for different expense categories and track their spending. This feature is medium priority but essential for budget-conscious users.
3.3.2 Functional Requirements
FR7: The system shall allow users to set a budget for specific expense categories.
FR8: The system shall notify users when they are close to or have exceeded their budget.

3.4 Financial Reports
3.4.1 Description and Priority
Users can generate reports to view summaries of income, expenses, and budget status. This feature has medium priority.
3.4.2 Functional Requirements
FR9: The system shall generate a summary report of total income, total expenses, and net balance.
FR10: The system shall provide detailed reports for specific categories or time periods.

3.5 Notifications
3.5.1 Description and Priority
Users will receive notifications for budget limits and other alerts. This feature has medium priority for user convenience.
3.5.2 Functional Requirements
FR11: The system shall notify the user when a budget limit is reached.

3.6 Data Persistence
3.6.1 Description and Priority
The application will save data to a file to ensure that financial information is not lost between sessions. This feature is high priority.
3.6.2 Functional Requirements
FR13: The system shall save income, expenses, and budget data to a file.
FR14: The system shall load data from the file when the application starts.

4. Non-Functional Requirements
4.1 Performance Requirements
The application shall handle up to 1,000 income and expense entries efficiently.
4.2 Reliability
The system shall ensure data integrity when saving and loading from a file.
4.3 Usability
The console interface shall be intuitive, with clear commands and instructions.
Users shall be able to easily navigate and execute commands.
4.4 Maintainability
The code shall be modular, using interfaces and generics for easy updates and scalability.

 

