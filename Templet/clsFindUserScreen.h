#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUsers.h"
#include "clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
{

private:

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n---------------------";
        cout << "\nFirstName      :" << User.FirstName;
        cout << "\nFirstName      :" << User.LastName;
        cout << "\nFullName       :" << User.FullName();
        cout << "\nEmail          :" << User.Email;
        cout << "\nPhone          :" << User.Phone;
        cout << "\nAcc. Number    :" << User.UserName;
        cout << "\nPassword       :" << User.Password;
        cout << "\nBalance        :" << User.Permissions;
        cout << "\n---------------------\n";
    }

public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t Find User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        if (!User1.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User1);
    }
};