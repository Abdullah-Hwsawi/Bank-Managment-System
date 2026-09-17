#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>

class clsListCurrancyiesScreen :protected clsScreen
{

private:

    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << left << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << left << Currency.CurrencyName();
		cout << "| " << left << setw(10) << left << Currency.Rate();
    }

public:

	static void ShowCurrancyiesListScreen()
	{

		vector<clsCurrency>vCurrancy = clsCurrency::GetCurrenciesList();
		string Title = "\t Currancy List Screen";
		string SubTitle = "\t   (" + to_string(vCurrancy.size()) + ") Currancyies";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t---------------------------------------------------------";
		cout << "---------------------------------------------\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t---------------------------------------------------------";
		cout << "---------------------------------------------\n" << endl;

		if (vCurrancy.size() == 0)
			cout << "\t\t\t\tNo Currancy Available In the System!";
		else

			for (clsCurrency Currancy : vCurrancy)
			{
				_PrintCurrencyRecordLine(Currancy);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t---------------------------------------------------------";
		cout << "---------------------------------------------\n" << endl;
	}

};

