C++ Console Bank System
Overview: This is a Console Bank System built in C++ using Object-Oriented Programming (OOP). The application is designed as a command-line interface for managing client accounts, executing financial transactions (Deposit, Withdraw, Transfer), and managing users and login/transfer logs.
 
OOP Architecture & Classes Breakdown
The main files (headers/classes) present in the project with a brief description of each:
•	clsPerson.h
•	Base class representing a person (FirstName, LastName, Email, Phone). Used as a foundation for other objects.
•	clsBankClient.h
•	Represents a bank client account (AccountNumber, PinCode, AccountBalance).
•	Operations: Add, Update, Delete (Clients.txt file), Deposit, Withdraw, Transfer, and register Transfer Log (TransferLog.txt).
•	clsUsers.h (clsUser)
•	Represents a system user (UserName, Password, Permissions).
•	Functions: Find, Save, Delete, login management, and login/registration logging in LoginRegister.txt.
•	Contains permission definitions (enPermissions: pListClients, pAddNewClient, pDeleteclient, pUpdateClient, pFindClient, pTranactions, pManageUsers, pLoginRegister, eAll).
•	clsScreen.h
•	Base class for UI screens containing shared functions for displaying headers and verifying access permissions.
•	clsInputValidate.h
•	Input reading and validation tools (ReadIntNumber, ReadDblNumber, ReadString, range validation, etc.).
•	clsUtil.h
•	General utility functions (random key generation, EncryptText/DecryptText, swap, etc.).
•	Used for simple password encryption before storage.
•	clsString.h
•	Text manipulation tools (Split, Join, Trim, Replace, etc.).
•	clsDate.h
•	Date handling functions (GetSystemDate, DateToString, GetSystemDateTimeString).
•	clsEmployee.h
•	Represents an employee (inherits from clsPerson). Includes Title, Department, Salary.
•	Login and Application Interface:
•	clsLoginScreen.h — Login screen.
•	clsMainScreen.h — Main menu.
•	clsTransactionsScreen.h — Transactions menu.
•	Transaction and Account Operation Screens:
•	clsDepositScreen.h — Deposit operation.
•	clsWithdrawScreen.h — Withdrawal operation.
•	clsTransferScreen.h — Transfer between accounts.
•	clsTransferLogScreen.h — View transfer history.
•	clsTotalBalancesScreen.h — View total balances of all accounts.
•	Client Management Screens:
•	clsAddNewClientScreen.h, clsClientListScreen.h, clsDeleteClientScreen.h, clsUpdateClientScreen.h, clsFindClientScreen.h
•	User Management Screens:
•	clsManageUsersScreen.h, clsAddNewUserScreen.h, clsListUsersScreen.h, clsFindUserScreen.h, clsDeleteUserScreen.h, clsUpdateUserScreen.h, clsLoginRegisterScreen.h
•	Currency Exchange (Additional Modules):
•	clsCurrancyExchangeMainScreen.h, clsCurrencyCalclatorScreen.h, clsFindCurrancyScreen.h, clsListCurrancyiesScreen.h, clsUpdateCurrancyScreen.h
•	Global.h
•	Global variable: CurrentUser (tracks the logged-in user state across screens).
•	Templet.cpp
•	Entry point (main) that displays the login screen in a loop.
 
Core Features
Main features grouped by functionality:
Account Management
•	Create/Add new client accounts (AccountNumber, PinCode, Balance).
•	Update and Delete client records.
•	List / Find client(s).
•	Persistence: Clients stored in Clients.txt (plain text, separated by "#//#").
Financial Transactions
•	Deposit: Add amount to client balance (clsDepositScreen / clsBankClient::Deposit).
•	Withdraw: Withdraw amount with balance verification (clsWithdrawScreen / clsBankClient::Withdraw).
•	Transfer: Transfer amount between accounts with sequential balance updates and transfer log registration (TransferLog.txt).
•	Total Balances: Calculate total balances across all accounts.
User Permissions & Logs
•	Multi-user support with defined permissions (enPermissions) controlling who can view or perform specific operations.
•	Authentication: Login screen and user verification via Users.txt.
•	Passwords: Stored with simple encryption using clsUtil::EncryptText (reversible via DecryptText).
•	Login/Register log: Recording login/registration operations in LoginRegister.txt (DateTime, UserName, Permissions).
•	Transfer logs: Every transfer is recorded in TransferLog.txt with DateTime, Source Account, Destination Account, Amount, Balances After Operation, and UserName who performed the transfer.
 
Tech Stack & Tools
•	Language: C++
•	Programming Paradigm: Object-Oriented Programming (OOP)
•	IDE / Build: Microsoft Visual Studio (project file: Templet\Templet.vcxproj). Solution typically opens as Templet.sln.
•	Data Persistence: Plain text files (Files / fstream)
•	Clients.txt, Users.txt, TransferLog.txt, LoginRegister.txt
•	Standard: Code written using traditional C++ features (headers contain complete definitions and function implementations).
 
How to Run
1. Requirements:
•	Visual Studio (Windows) or any C++ compiler supporting C++11 or later.
•	Project files in the same directory (Templet.cpp and header files).
2. Running via Visual Studio:
•	Open Visual Studio → File → Open → Project/Solution → Select Templet.sln (or Templet.vcxproj inside the Templet folder).
•	Build → Build Solution.
•	Debug → Start Without Debugging or Run the executable (Console application will run).
•	Note: The program starts with a login screen, then displays the Main Menu after successful login.
3. Running via CLI (g++ / MinGW / clang++)
Open Terminal / Command Prompt in the project folder containing Templet.cpp and header files.
