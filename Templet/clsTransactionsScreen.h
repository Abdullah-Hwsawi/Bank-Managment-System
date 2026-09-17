#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include <iomanip>

using namespace std;

class clsTransactionsScreen :protected clsScreen
{

private:
	enum enTransactionsMenueOptions {
		eDeposti = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eShowTransfer = 4,
		eTransferLog = 5, eShowMainMenue = 6
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 and 5 ");
		return Choice;
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithDrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalance();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _GoBackToTransactions()
	{
		cout << setw(37) << left << "" << "\nPress any key to go back to Transactions...\n";
		system("pause>0");
		ShowTransactionsMenue();
	}
	 
	static void _PerformTransactionsMenueOptions(enTransactionsMenueOptions TransactionsMenueOptions)
	{
		switch (TransactionsMenueOptions)
		{
		case enTransactionsMenueOptions::eDeposti:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactions();
			break;
		case enTransactionsMenueOptions::eWithdraw:
			system("cls");
			_ShowWithDrawScreen();
			_GoBackToTransactions();
			break;
		case enTransactionsMenueOptions::eShowTotalBalance:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactions();
			break;
		case enTransactionsMenueOptions::eShowTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactions();
			break;
		case enTransactionsMenueOptions::eTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactions();
			break;
		case enTransactionsMenueOptions::eShowMainMenue:
		{

		}
			//do nothing here the main screen 
		}
	}

public:

	static void ShowTransactionsMenue()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\tTransactions Screen");

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\tTransactions Menue\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] WithDraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=====================================\n";

		_PerformTransactionsMenueOptions((enTransactionsMenueOptions)_ReadTransactionsMenueOption());
	}

};

