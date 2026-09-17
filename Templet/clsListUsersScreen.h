#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUsers.h"
#include <iomanip>

class clsListUsersScreen :protected clsScreen
{

private:

	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
		cout << "| " << left << setw(20) << left << User.FullName();
		cout << "| " << left << setw(12) << left << User.Email;
		cout << "| " << left << setw(20) << left << User.Phone;
		cout << "| " << left << setw(10) << left << User.Password;
		cout << "| " << left << setw(12) << left << User.Permissions;
	}

public:

	static void ShowUsersList()
	{
		vector<clsUser>vUsers = clsUser::GetUsersList();
		string Title = "\t User List Screen";
		string SubTitle = "\t   (" + to_string(vUsers.size()) + ") Users";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t---------------------------------------------------------";
		cout << "---------------------------------------------\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Emali";
		cout << "| " << left << setw(20) << "Phone";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t---------------------------------------------------------";
		cout << "---------------------------------------------\n" << endl;

		if (vUsers.size() == 0)
			cout << "\t\t\t\tNo Users Available In the System!";
		else

			for (clsUser User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t---------------------------------------------------------";
		cout << "---------------------------------------------\n" << endl;
	}

};

