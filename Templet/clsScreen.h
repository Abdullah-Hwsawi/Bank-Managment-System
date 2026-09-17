#pragma once
#include <iostream>
#include "clsUsers.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t-------------------------------------";
		cout << "\n\n\t\t\t\t\t  " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t-------------------------------------\n\n";

		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
		cout << "\t\t\t\t\tDate:" << clsDate::DateToString(clsDate()) << "\n\n";
	}

	static bool CheckAccessRights(clsUser::enPermissions Permissions)
	{

		if (!CurrentUser.CheckAccessPermtission(Permissions))
		{
			cout << "\t\t\t\t\t--------------------------------------------";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact Your Admin.";
			cout << "\n\t\t\t\t\t--------------------------------------------";
			return false;
		}
		else
		{
			return true;
		}
	}

};