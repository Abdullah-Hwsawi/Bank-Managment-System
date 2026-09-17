#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsUpdateCurrancyScreen : protected clsScreen
{

private:

	static float _ReadRate()
	{
		cout << "\nEnter New Rate: ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

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

public:

	static void ShowUpdateCurrancyScreen()
	{
		_DrawScreenHeader("Update Currency Screen");

		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCoed(CurrencyCode);
		_PrintCurrancyCard(Currency);

		 cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
		 char Answer = 'n';
		 cin >> Answer;

		 if (Answer == 'Y' || Answer == 'y')
		 {
			 float Rate = 0;

			 cout << "\nUpdate Currency Rate:";
			 cout << "\n-----------------------\n";

			 Currency.UpdateRate(_ReadRate());

			 cout << "\nCurrency Rate Update Successfully :-)\n";
			 _PrintCurrancyCard(Currency);

		 }
	}

};

