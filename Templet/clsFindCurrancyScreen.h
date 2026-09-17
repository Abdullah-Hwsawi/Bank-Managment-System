#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include <iomanip>

class clsFindCurrancyScreen :protected clsScreen
{
private:

	static void _PrintCurrancyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "---------------------------\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCoed       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n---------------------------\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrancyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}
	}

public:

	static void ShowFindCurrancyScreen()
	{

		_DrawScreenHeader("Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Answer = 1;

		cin >> Answer;

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter CurrencyCoed: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCoed(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}
	}

};

