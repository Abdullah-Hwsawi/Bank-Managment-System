#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


class clsManageUsersScreen :protected clsScreen
{

private:
	enum enManageUsersMenueOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
	};

	static short _ReadManageUsersMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number Between 1 and 6 ");
		return Choice;
	}

	static void _GoBackToManageUserMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage User Main Menue...\n";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUsersScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformTransactionsMenueOptions(enManageUsersMenueOptions ManageUsersMenueOptions)
	{
		switch (ManageUsersMenueOptions)
		{
		case enManageUsersMenueOptions::eListUsers:
		{
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUserMainMenue();
		}
		case enManageUsersMenueOptions::eAddNewUser:
		{
			system("cls");
			_ShowAddNewUsersScreen();
			_GoBackToManageUserMainMenue();
		}
		case enManageUsersMenueOptions::eDeleteUser:
		{
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUserMainMenue();
		}
		case enManageUsersMenueOptions::eUpdateUser:
		{
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUserMainMenue();
		}
		case enManageUsersMenueOptions::eFindUser:
		{
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUserMainMenue();
		}
		case enManageUsersMenueOptions::eMainMenue:
		{
			//do nothing here the main screen 
		}
		}
	}

public:

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\tManage Users Screen");

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Deletd User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=====================================\n";

		_PerformTransactionsMenueOptions((enManageUsersMenueOptions)_ReadManageUsersMenueOption());
	}

};

