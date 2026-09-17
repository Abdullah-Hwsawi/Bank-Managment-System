#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace MyLibry

{
	struct sClient
	{
		string Name;
		string AccountNum;
		string PinCode;
		string Phone;
		double Balance;
		bool MarkForDelet = true;
	};

	int ReadNumber()
	{
		int Number;
		cout << "Please enter a number?" << endl;
		cin >> Number;

		while (cin.fail())
		{

			cin.clear();
			cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

			cout << "Invalid Number, Enter a valid one:" << endl;
			cin >> Number;
		}
		return Number;
	}

	char OpType()
	{
		char Op;

		cout << "Enter Opreation Type ? ";
		cin >> Op;

		return Op;
	}

	char Calcoletar(float Num1, float Num2, char OpType)
	{
		switch (OpType)
		{
		case '+':
			return (float)Num1 + Num2;
		case '-':
			return (float)Num1 - Num2;
		case '*':
			return (float)Num1 * Num2;
		case '/':
			return (float)Num1 / Num2;
		default:
			return (float)Num1 + Num2;
		}
	}

	int ReadVaildNumber()
	{
		int Number = 0;
		cout << "Please enter a number?" << endl;
		cin >> Number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Invalid Number, Enter a vaild One:" << endl;

			cin >> Number;
		}
		return Number;
	}

	string ReadTheString()
	{
		string S1 = "";

		cout << "Please Enter Your String?\n";
		getline(cin, S1);

		return S1;
	}

	string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
	{
		short pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
			pos = S1.find(StringToReplace);//find next
		}
		return S1;
	}

	string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
	{

		string FormattedDateString = "";
		FormattedDateString = ReplaceWordInString(DateFormat, "dd", to_string(Date.Day));
		FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", to_string(Date.Month));
		FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", to_string(Date.Year));

		return FormattedDateString;
	}

	char InvertLetterCase(char Char1)
	{
		return isupper(Char1) ? tolower(Char1) : toupper(Char1);
	}

	string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}
		return S1;
	}

	string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}

	sClient ConvertLineToRecord(string Line, string Seperator = "#//#")
	{
		sClient Client;
		vector<string>vClientData;
		vClientData = SplitString(Line, Seperator);

		Client.AccountNum = vClientData[0];
		Client.PinCode = vClientData[1];
		Client.Name = vClientData[2];
		Client.Phone = vClientData[3];
		Client.Balance = stod(vClientData[4]);

		return Client;
	}

	string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";

		stClientRecord += Client.AccountNum + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += Client.Name + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += to_string(Client.Balance);

		return stClientRecord;
	}

	vector<string> SplitString(string S1, string Delim)
	{
		vector <string> vString;

		short Pos = 0;
		string sWord;

		while ((Pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, Pos);

			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			S1.erase(0, Pos + Delim.length());
		}

		if (S1 != "")
		{
			vString.push_back(S1);
		}

		return vString;
	}

	string DateToString(sDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	sDate StringToDate(string DateString)
	{
		sDate Date;
		vector<string>vDate;

		vDate = SplitString(DateString, "/");
		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;
	}

	string ReadDateString(string Messeag)
	{
		string DateString;

		cout << Messeag;
		getline(cin >> ws, DateString);

		return DateString;
	}

	vector<sClient> LoadClientRecord(string FileName)
	{
		vector<sClient>vClient;

		fstream MyFile;
		MyFile.open(FileName, ios::in); //read Mode

		if (MyFile.is_open())
		{

			string Line;
			sClient Client;

			while (getline(MyFile, Line))
			{

				Client = ConvertLineToRecord(Line);

				vClient.push_back(Client);
			}

			MyFile.close();
		}

		return vClient;
	}

	sClient ChaneClientRecord(string AccountNumber)
	{
		sClient Client;

		Client.AccountNum = AccountNumber;

		cout << "\n\nEnter PicCode? ";
		getline(cin >> ws, Client.PinCode);

		cout << "Enter Name? ";
		getline(cin, Client.Name);

		cout << "Enter Phone? ";
		getline(cin, Client.Phone);

		cout << "Enter Acconut Balance? ";
		cin >> Client.Balance;

		return Client;
	}

	bool FindClientByAccountNumber(string AccountNumber, vector< sClient> vClients, sClient& Client)
	{
		for (sClient C : vClients)
		{
			if (C.AccountNum == AccountNumber)
			{
				Client = C;
				return true;
			}
		}
		return false;
	}

	vector<sClient>SaveClientsDataToFile(string FileName, vector<sClient>vClients)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (sClient C : vClients)
			{

				if (C.MarkForDelet == false)
				{

					//we only write records that are not marked for delete.
					DataLine = ConvertRecordToLine(C);
					MyFile << DataLine << endl;
				}
			}

			MyFile.close();
		}

		return vClients;
	}

	bool UpdateClientByAccountNumber(string AccountNumber, vector <sClient>& vClients)
	{
		sClient Client;
		char Answer = 'n';

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		{

			PrintClientCard(Client);


			cout << "\n\nAre you sure you want Update thiss client y/n ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
			{


				for (sClient& C : vClients)
				{
					if (C.AccountNum == AccountNumber)
					{
						C = ChaneClientRecord(AccountNumber);
						break;
					}
				}

				SaveClientsDataToFile(ClientsFileName, vClients);


				cout << "\n\nClient Updated Successfully.";
				return true;

			}
		}
		else
		{
			cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found\n";
			return false;
		}
	}

	string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
				"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
				"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return arr[Number] + " ";
		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "" ,"","Twnty","Thirty","Fouty","Fifty","Sixty","Seventy","Eihty","Ninty" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return "One hnudred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return +"One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}

	short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;

		short NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYears(Year) ? 29 : 28) : NumberOfDays[Month - 1];
	}

	int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDys = false)
	{
		int Days = 0;
		while (IsDate1BeforeDeat2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDys ? ++Days : Days;
	}

	string DayShortName(short DayOfWeekOrder)
	{
		string arrDayName[7] = { "Sun" ,"Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayName[DayOfWeekOrder];
	}

	short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;

		a = (17 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return 	(Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan" ,"Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return Months[MonthNumber - 1];
	}

	void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;

		int Current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = NumberOfDaysInMonth(Month, Year);

		// Print the current month name
		printf("\n ------------------%s----------------\n\n", MonthShortName(Month).c_str());


		// Print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < Current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);


			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  ----------------------------------\n");
	}

	void PrintYearCalendar(int Year)
	{
		printf("\n  --------------------------------\n\n");
		printf("          Calendar - %d\n", Year);
		printf("  --------------------------------\n");

		for (int i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
		return;
	}

	void SwapDates(sDate& Date1, sDate& Date2)
	{

		sDate TempDate;

		TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;

		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;

		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;
	}

	int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDys = false)
	{

		int Days = 0;
		short SawpFlagValue = 1;

		if (!IsDate1BeforeDeat2(Date1, Date2))
		{
			//Swap Dates
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;

		}

		while (IsDate1BeforeDeat2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}

		return IncludeEndDys ? ++Days * SawpFlagValue : Days * SawpFlagValue;
	}

	bool IsDate1BeforeDeat2(sDate Date1, sDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	sDate GetSystemDate()
	{
		sDate Date;

		time_t t = time(0);
		tm* now = localtime(&t);

		Date.Year = now->tm_year + 1900;
		Date.Month = now->tm_mon + 1;
		Date.Day = now->tm_mday;

		return Date;
	}

	sDate DecreaseDateByOneDay(sDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{

				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}

	sDate IncreaseDateByXDate(short Days, sDate Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate IncreaseDateByOneDay(sDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{

				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}

	sDate IncreaseDateByOneWeek(sDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;
	}

	sDate IncreaseDateByXWeek(short Week, sDate Date)
	{
		for (short i = 1; i <= Week; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}

		return Date;
	}

	sDate IncreaseDateByOneMonth(sDate Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		//last check day in date should not exceed max days in the current month 
		//example if date is 31/12/2022 increaseing one month should not be 31/2/2022, it should
		//be 28/2/2022

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	sDate IncreaseDateByXMonth(short Month, sDate Date)
	{
		for (short i = 1; i <= Month; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}

	sDate IncreaseDateByOneYear(sDate Date)
	{
		Date.Year++;
		return Date;
	}

	sDate IncreaseDateByXYear(short Years, sDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}

	sDate IncreaseDateByXYearFaster(short Years, sDate Date)
	{
		Date.Year += Years;
		return Date;
	}

	sDate IncreaseDateByOneDecade(sDate Date)
	{
		//Period of 10 years
		Date.Year += 10;
		return Date;
	}

	sDate IncreaseDateByXDecades(short Decade, sDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}

		return Date;
	}

	sDate IncreaseDateByXDecadesFaster(short Decade, sDate Date)
	{
		Date.Year += Decade * 10;
		return Date;
	}

	sDate IncreaseDateByOneCentury(sDate Date)
	{
		//period of 100 years
		Date.Year += 100;
		return Date;
	}

	sDate IncreaseDateByOneMillennium(sDate Date)
	{
		//period of 1000 years
		Date.Year += 1000;
		return Date;
	}

	sDate DecreaseDateByOneDay(sDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{

				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}

		return Date;
	}

	sDate DecreaseDateByXDays(short Days, sDate Date)
	{

		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	sDate DecreaseDateByOneWeek(sDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	sDate DecreaseDateByXWeek(short Week, sDate Date)
	{
		for (short i = 1; i <= Week; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}

		return Date;
	}

	sDate DecreaseDateByOneMonth(sDate Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}

		//last check day in date should not exceed max days in the current month 
		//example if date is 31/3/2022 increaseing one month should not be 31/2/2022, it should
		//be 28/2/2022

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	sDate DecreaseDateByXMonth(short Month, sDate Date)
	{
		for (short i = 1; i <= Month; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}

	sDate DecreaseDateByOneYear(sDate Date)
	{
		Date.Year--;
		return Date;
	}

	sDate DecreaseDateByXYear(short Years, sDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	sDate DecreaseDateByXYearFaster(short Years, sDate Date)
	{
		Date.Year -= Years;
		return Date;
	}

	sDate DecreaseDateByOneDecade(sDate Date)
	{
		//Period of 10 years
		Date.Year -= 10;
		return Date;
	}

	sDate DecreaseDateByXDecades(short Decade, sDate Date)
	{
		for (short i = 1; i <= Decade * 10; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}

		return Date;
	}

	sDate DecreaseDateByXDecadesFaster(short Decade, sDate Date)
	{
		Date.Year -= Decade * 10;
		return Date;
	}

	sDate DecreaseDateByOneCentury(sDate Date)
	{
		//period of 100 years
		Date.Year -= 100;
		return Date;
	}

	sDate DecreaseDateByOneMillennium(sDate Date)

	sDate CalculateVacationReturDate(sDate DateFrom, short VacationDays)
	{
		short WeekEndCounter = 0;

		//in case the date is weekend keep adding one day util you reach busines day
		//we get rid of all weekends before the first business day
		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it.

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach business day

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
    }

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	enDateCompare CompareDates(sDate Date1, sDate Date2)
	{
		if (IsDate1BeforeDeat2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		/*if (IsDate1AfterDeat2(Date1, Date2))
			return enDateCompare::After;*/

			//this is faster
		return enDateCompare::After;
	}

	short ReadVacationDays()
	{
		short Days;
		cout << "\nPlease enter vacation days? ";
		cin >> Days;
		return Days;
	}

	bool IsLeapYears(short Year)
	{

		return (Year % 400 == 0 && Year % 100 != 0 || (Year % 4 == 0));
	}

	bool IsEndOfWeek(sDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}

	bool IsWeekEnd(sDate Date)
	{
		//Weekends are Fri and sat
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsBusinessDay(sDate Date)
	{
		//Weekends are Sun,Mon,Tue,Wed And Thur

		/*
		 short DayIndex = DayOfWeekOrder(Date);
		 return (DayIndex >= 5 && DayIndex <= 4);
		*/

		//shoter method is to invert the IsWeekEnd: this will save updating code.
		return !IsEndOfWeek(Date);
	}

	bool IsLastDayInMonth(sDate Date)
	{
		return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
	}

	bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	bool IsDate1BeforeDeat2(sDate Date1, sDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}

	bool IsDate1EqualDate2(sDate Date1, sDate Date2)
	{
		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}

	bool IsDate1AfterDeat2(sDate Date1, sDate Date2)
	{
		return (!IsDate1BeforeDeat2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	bool IsOverlapPeriods(stPeriods period1, stPeriods Period2)
	{

		if (CompareDates(Period2.EndDate, period1.StartDate) == enDateCompare::Before || CompareDates(Period2.StartDate, period1.EndDate) == enDateCompare::After)
			return false;
		else return true;
	}

	bool IsPeriodInDate(sDate CheckDate, stPeriods Period)
	{
		return !(CompareDates(CheckDate, Period.StartDate) == enDateCompare::Before || CompareDates(CheckDate, Period.EndDate) == enDateCompare::After);
	}

	bool IsPeriodInDate(sDate CheckDate, stPeriods Period)
	{
		return !(CompareDates(CheckDate, Period.StartDate) == enDateCompare::Before || CompareDates(CheckDate, Period.EndDate) == enDateCompare::After);
	}

	bool IsValidDate(sDate Date)
	{
		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;

		if (Date.Month == 2)
		{
			if (IsLeapYears(Date.Year))
			{
				if (Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			return false;

		return true;
	}

	short DaysUntilTheEndOfWeek(sDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}

	int CountoverlapDays(stPeriods Period1, stPeriods Period2)
	{
		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int OverlapDays = 0;

		if (!IsOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length)
		{
			while (IsDate1BeforeDeat2(Period1.StartDate, Period1.EndDate))
			{

				if (IsPeriodInDate(Period1.StartDate, Period2))
					OverlapDays++;

				Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (IsDate1BeforeDeat2(Period2.StartDate, Period2.EndDate))
			{

				if (IsPeriodInDate(Period2.StartDate, Period1))
					OverlapDays++;

				Period2.StartDate = IncreaseDateByOneDay(Period2.EndDate);
			}
		}

		return OverlapDays;
	}

	short DaysUntilTheEndOfMonth(sDate Date1)
	{
		sDate EndOfMonthDate;
		EndOfMonthDate.Day = NumberOfDaysInMonth(Date1.Month, Date1.Year);
		EndOfMonthDate.Month = Date1.Month;
		EndOfMonthDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfMonthDate, true);
	}

	short DaysUntilTheEndOfYear(sDate Date1)
	{
		sDate EndOfYearhDate;
		EndOfYearhDate.Day = 31;
		EndOfYearhDate.Month = 12;
		EndOfYearhDate.Year = Date1.Year;

		return GetDifferenceInDays(Date1, EndOfYearhDate, true);
	}

	short CalculateVacationDays(sDate DateFrom, sDate DateTo)
	{

		short DaysCount = 0;
		while (IsDate1BeforeDeat2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom));
			DaysCount++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DaysCount;
	}

}


