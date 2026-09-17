#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalclatorScreen :protected clsScreen
{

private:

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		float Amount = 0;

		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;
		cout << Message;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCoed(CurrencyCode);
		return Currency;

	}

	static void _PrintCurrancyCard(clsCurrency Currency, string Title = "")
	{
		cout << "\nCurrency Card:\n";
		cout << "---------------------------\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCoed       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n---------------------------\n";
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrancyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUsd(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrancyCard(Currency2, "To:");

		float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
	}

public:

	static void ShowCurrencyCalcatorScreen()
	{

		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");

			_DrawScreenHeader("Currency Calclator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;

		}
	}

};

