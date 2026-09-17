#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsPerson.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen
{
private:
    static void _PrintUser(clsUser User)
    {
        cout << "\nClient Card:";
        cout << "\n---------------------";
        cout << "\nFirstName          :" << User.FirstName;
        cout << "\nLastName           :" << User.LastName;
        cout << "\nFullName           :" << User.FullName();
        cout << "\nEmail              :" << User.Email;
        cout << "\nPhone              :" << User.Phone;
        cout << "\nUser Name          :" << User.UserName;
        cout << "\nPassword           :" << User.Password;
        cout << "\nPermissions        :" << User.Permissions;
        cout << "\n---------------------\n";

    }

public:

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\t Delete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser is not found, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\nAre you sure you want to delete thie User y/n ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }

    }
};

