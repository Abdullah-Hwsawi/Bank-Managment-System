#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsUtil.h"

using namespace std;

class clsUser : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;


		vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
		LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
		LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
		LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
		LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);

		return LoginRegisterRecord;

	}

	string _PrepareLogInRecord(string Seperator = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
		LoginRecord += UserName + Seperator;
		LoginRecord += clsUtil::EncryptText(Password) + Seperator;
		LoginRecord += to_string(Permissions);

		return LoginRecord;
	}

	static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
	{
		vector<string>vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
			vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]) , stoi(vUserData[6]));

	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{

		string stUserRecord = "";
		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.Phone + Seperator;
		stUserRecord += User.UserName + Seperator;
		stUserRecord += clsUtil::EncryptText(User.Password) + Seperator;
		stUserRecord += to_string(User.Permissions);

		return stUserRecord;
	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser> vUser;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{

				clsUser User = _ConvertLinetoUserObject(Line);

				vUser.push_back(User);
			}

			MyFile.close();
		}

		return vUser;
	}

	static void _SaveUserDataToFile(vector<clsUser>vUser)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsUser U : vUser)
			{
				if (U._MarkedForDelete == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}

			}

			MyFile.close();

		}
	}

	void _Update()
	{
		vector<clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}

		}

		_SaveUserDataToFile(_vUsers);

	}

	void _AddNew()
	{
		_AddDataLienToFile(_ConvertUserObjectToLine(*this));
	}

	static void _AddDataLienToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);//overwrite


		if (MyFile.is_open())
		{

			//we only write records that are not marked for delete.
			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


public:

	enum enPermissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteclient = 4,
		eUpdateClient = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pLoginRegister = 128
	};

	struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string Password,
		int Permissons) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissons;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	//bool MarkedForDelete()
	//{
	//	return _MarkedForDelete;
	//}

	void setUserName(string UserName)
	{
		_UserName = UserName;
	}

	string getUserName()
	{
		return _UserName;
	}

	__declspec(property(get = getUserName, put = setUserName))string UserName;

	void setPassword(string Password)
	{
		_Password = Password;
	}

	string getPassword()
	{
		return _Password;
	}

	__declspec(property(get = getPassword, put = setPassword))string Password;

	void setPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	int getPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = getPermissions, put = setPermissions))int Permissions;

	static clsUser Find(string UserName)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName && Password == Password)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}
		return _GetEmptyUserObject();
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserNameExists = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{

				return enSaveResults::svFaildEmptyObject;

			}
		}

		case enMode::UpdateMode:
		{

			_Update();

			return enSaveResults::svSucceeded;

			break;
		}
		case enMode::AddNewMode:
		{
			//This will add new record to file or database
			if (clsUser::IsUserExist(UserName))
			{
				return enSaveResults::svFaildUserNameExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;

			}

			break;

		}

		}

	}

	static bool IsUserExist(string UserName)
	{

		clsUser User = clsUser::Find(UserName);

		return (!User.IsEmpty());
	}

    bool Delete()
	{
		vector<clsUser>_vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				_MarkedForDelete = true;
				break;
			}
		}

		_SaveUserDataToFile(_vUsers);

		*this = _GetEmptyUserObject();

		return true;
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<clsUser>GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermtission(enPermissions Permissions)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((Permissions & this->Permissions) == Permissions)
			return true;
		else
			return false;
	}

	void RegisterLogIn()
	{

		string stDataLine = _PrepareLogInRecord();
		
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static  vector <stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector <stLoginRegisterRecord> vLoginRegisterRecord;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			stLoginRegisterRecord LoginRegisterRecord;

			while (getline(MyFile, Line))
			{

				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);

				vLoginRegisterRecord.push_back(LoginRegisterRecord);

			}

			MyFile.close();

		}

		return vLoginRegisterRecord;

	}

};

