#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <iomanip>


class clsTotalBalancesScreen : protected clsScreen
{

private:

   static void PrintClientRecordBalancLine(clsBankClient Client)
    {
       cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << left << setw(40) << left << Client.FullName();
        cout << "| " << left << setw(12) << left << Client.AccountBalance;
    }

public:

   static void ShowTotalBalance()
    {
        vector<clsBankClient>vClients = clsBankClient::GetClientsList();


        string Title = "\t Balances List Screen";
        string SubTitle = "\t   (" + to_string(vClients.size()) + ") Clients";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "\n\t\t-----------------------------------------------------------";
        cout << "--------------------------\n" << endl;

        cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance";
        cout << setw(25) << left << "" << "\n\t\t-----------------------------------------------------------";
        cout << "--------------------------\n" << endl;

        double TotlalBalances = clsBankClient::GetTotalBalances();

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Client Available In the System!";
        else

            for (clsBankClient Client : vClients)
            {
                PrintClientRecordBalancLine(Client);
                cout << endl;
            }

        cout << setw(25) << left << "" << "\n\t\t-----------------------------------------------------------";
        cout << "-------------------------\n" << endl;
        cout << setw(8) << left << "" << "\t\t\t\t\t\t\t   Total Balances = " << TotlalBalances << endl;
        cout << setw(8) << left << "" << "\t\t\t   ( " << clsUtil::NumberToText(TotlalBalances) << ")" << endl;
   }
};

