#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>

class clsClientListScreen : protected clsScreen
{

private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << left << setw(20) << left << Client.FullName();
		cout << "| " << left << setw(12) << left << Client.Phone;
		cout << "| " << left << setw(20) << left << Client.Email;
		cout << "| " << left << setw(10) << left << Client.PinCode;
		cout << "| " << left << setw(12) << left << Client.AccountBalance;
	}


public:

	static void ShowClientsList()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}

		vector<clsBankClient>vClients = clsBankClient::GetClientsList();
		string Title = "\t Client List Screen";
		string SubTitle = "\t   (" + to_string(vClients.size()) + ") Clients";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t---------------------------------------------------------";
		cout << "---------------------------------------------\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Emali";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t---------------------------------------------------------";
		cout << "---------------------------------------------\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Client Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t---------------------------------------------------------";
		cout << "---------------------------------------------\n" << endl;
	}

};



