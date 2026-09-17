#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrancyiesScreen.h"
#include "clsFindCurrancyScreen.h"
#include "clsUpdateCurrancyScreen.h"
#include "clsCurrencyCalclatorScreen.h"


class clsCurrancyExchangeMainScreen :protected clsScreen
{
private:
	enum enCurrencyMainMenueOptionScreens {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
		eCurrencyCalclator = 4, eMainMenue = 5
	};

	static short _ReadCurrencyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number Between 1 and 5 ");
		return Choice;
	}

	static void _GoBackToCurrencies()
	{
		cout << setw(37) << left << "" << "\nPress any key to go back to Currencyies...\n";
		system("pause>0");
		ShowCurrancyiesMenue();
	}

	static void showListCurrenciesScreen()
	{
		clsListCurrancyiesScreen::ShowCurrancyiesListScreen();
	}

	static void showFindCurrencyScreen()
	{
		clsFindCurrancyScreen::ShowFindCurrancyScreen();
	}

	static void showUpdateCurrencyScreen()
	{
		clsUpdateCurrancyScreen::ShowUpdateCurrancyScreen();
	}

	static void showCurrencyCalcuatorScreen()
	{
		clsCurrencyCalclatorScreen::ShowCurrencyCalcatorScreen();
	}

	static void _PerformCurrancyiesMenueOptions(enCurrencyMainMenueOptionScreens CurrencyMenueOptionScreens)
	{
		switch (CurrencyMenueOptionScreens)
		{
		case enCurrencyMainMenueOptionScreens::eListCurrencies:
			system("cls");
			showListCurrenciesScreen();
			_GoBackToCurrencies();
			break;
		case enCurrencyMainMenueOptionScreens::eFindCurrency:
			system("cls");
			showFindCurrencyScreen();
			_GoBackToCurrencies();
			break;
		case enCurrencyMainMenueOptionScreens::eUpdateRate:
			system("cls");
			showUpdateCurrencyScreen();
			_GoBackToCurrencies();
			break;
		case enCurrencyMainMenueOptionScreens::eCurrencyCalclator:
			system("cls");
			showCurrencyCalcuatorScreen();
			_GoBackToCurrencies();
			break;
		case enCurrencyMainMenueOptionScreens::eMainMenue:
		{

		}
		}
	}

public:

	static void ShowCurrancyiesMenue()
	{
		//if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		//{
		//	return;
		//}

		system("cls");
		_DrawScreenHeader("\tCurrencies Screen");

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrencu Exchange Menue\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calclator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "=====================================\n";

		_PerformCurrancyiesMenueOptions((enCurrencyMainMenueOptionScreens)_ReadCurrencyMenueOption());
	}

};

