#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>


class clsFindClientScreen:protected clsScreen
{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n---------------------";
        cout << "\nFirstName      :" << Client.FirstName;
        cout << "\nFirstName      :" << Client.LastName;
        cout << "\nFullName       :" << Client.FullName();
        cout << "\nEmail          :" << Client.Email;
        cout << "\nPhone          :" << Client.Phone;
        cout << "\nAcc. Number    :" << Client.AccountNumber();
        cout << "\nPassword       :" << Client.PinCode;
        cout << "\nBalance        :" << Client.AccountBalance;
        cout << "\n---------------------\n";

    }

public:

    static void ShowFindClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }

        _DrawScreenHeader("\t Find Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client AccountNumber: ";
        AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        if (!Client1.IsEmpty())
        {
            cout << "\nClient Found :-)\n";
        }
        else
        {
            cout << "\nClient Was not Found :-(\n";
        }

        _PrintClient(Client1);

    }

};

