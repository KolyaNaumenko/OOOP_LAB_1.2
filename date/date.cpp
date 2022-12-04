#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>

using namespace std;

class Date {

public:

	void checkTime() {

		SYSTEMTIME st;
		string date;
		string time;

		cout << "Enter date (00.00.0000): ";
		cin >> date;
		cout << "Enter time (00:00:00): ";
		cin >> time;

		system("cls");

		strToInt(date, time, 0);

		CTrue(0);

		if (check2 == 1) {

			GetLocalTime(&st);

			secondday = st.wDay;
			secondmonth = st.wMonth;
			secondyear = st.wYear;
			secondhour = st.wHour;
			secondminute = st.wMinute;
			secondsecond = st.wSecond;

			toSec();
			diference();

			cout << "Given date: " << date << " " << time << "\n"
				<< "Current date: " << st.wDay << "." << st.wMonth << "." << st.wYear << " " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << "\n"
				<< "Difference: " << ressecond << " seconds, " << resminute << " minutes, " << reshour << " hours, " << resday << " days\n";

		}
		else {
			cout << "Date entered incorrectly\n";
		}
	}

	void TwoTimes() {

		SYSTEMTIME st;
		string date1;
		string time1;
		string date2;
		string time2;

		cout << "Enter first date (00.00.0000): ";
		cin >> date1;
		cout << "Enter time (00:00:00): ";
		cin >> time1;

		cout << "Enter second date (00.00.0000): ";
		cin >> date2;
		cout << "Enter time (00:00:00): ";
		cin >> time2;

		system("cls");

		strToInt(date1, time1, 0);
		strToInt(date2, time2, 1);

		CTrue(0);

		if (check2 == 1) {

			CTrue(1);

			if (check2 == 1) {

				int Dday;

				GetLocalTime(&st);

				toSec();
				diference();

				cout << "Given date 1: " << date1 << " " << time1 << "\n"
					<< "Given date 2: " << date2 << " " << time2 << "\n"
					<< "Difference: " << ressecond << " seconds, " << resminute << " minutes, " << reshour << " hours, " << resday << " days\n";

				secondhour = reshour;
				secondminute = resminute;
				secondsecond = ressecond;
				secondday = resday;
				secondmonth = resmonth;
				secondyear = resyear;
				Dday = resday;

				iday = st.wDay;
				imonth = st.wMonth;
				iyear = st.wYear;
				ihour = st.wHour;
				iminute = st.wMinute;
				isecond = st.wSecond;

				toSec();
				sum();

				cout << "Sum of current date with difference: " << resday << "." << resmonth << "." << resyear << " " << reshour << ":" << resminute << ":" << ressecond << "\n";

			}
			else {
				cout << "Date entered incorrectly\n";
			}
		}
		else {
			cout << "Date entered incorrectly\n";
		}
	}

	void WeekDay() {

		string date;
		string time;

		cout << "Enter date (00.00.0000): ";
		cin >> date;
		time = "00:00:00";

		system("cls");

		strToInt(date, time, 0);

		CTrue(0);

		if (check2 == 1) {
			secondday = 3;
			secondmonth = 10;
			secondyear = 2022;
			secondhour = 0;
			secondminute = 0;
			secondsecond = 0;

			toSec();
			diference();
			Get_Day();

			cout << "Given date: " << date << "\n"
				<< "The day of the week: " << TDay << "\n";

		}
		else {
			cout << "Date entered incorrectly\n";
		}
	}

	void WeekDay1() {

		SYSTEMTIME st;

		GetLocalTime(&st);

		iday = st.wDay;
		imonth = st.wMonth;
		iyear = st.wYear;
		ihour = 0;
		iminute = 0;
		isecond = 0;

		secondday = 3;
		secondmonth = 10;
		secondyear = 2022;
		secondhour = 0;
		secondminute = 0;
		secondsecond = 0;

		toSec();
		diference();
		Get_Day();

		cout << "Given date: " << st.wDay << "." << st.wMonth << "." << st.wYear << "\n"
			<< "The day of the week: " << TDay << "\n";
	}

private:
	bool check2;
	bool check;
	string TDay;

	int iday;
	int imonth;
	int iyear;
	int ihour;
	int iminute;
	int isecond;

	int secondday;
	int secondmonth;
	int secondyear;
	int secondhour;
	int secondminute;
	int secondsecond;

	unsigned long long res1;
	unsigned long long res2;

	int resday;
	int resmonth;
	int resyear;
	int reshour;
	int resminute;
	int ressecond;

	void strToInt(string date, string time, bool check) {

		string day = "00";
		string month = "00";
		string year = "0000";
		string hour = "00";
		string minute = "00";
		string second = "00";

		for (int i = 0; i < date.size(); i++) {
			if (i < 2) {
				day[i] = date[i];
				hour[i] = time[i];
			}
			if (i > 2 && i < 5) {
				month[i - 3] = date[i];
				minute[i - 3] = time[i];
			}
			if (i > 5) {
				if (i == 6) {
					second[0] = time[i];
					second[1] = time[i + 1];
				}
				year[i - 6] = date[i];
			}
		}
		if (check == 0) {
			iday = atoi(day.c_str());
			imonth = atoi(month.c_str());
			iyear = atoi(year.c_str());
			ihour = atoi(hour.c_str());
			iminute = atoi(minute.c_str());
			isecond = atoi(second.c_str());
		}
		else {
			secondday = atoi(day.c_str());
			secondmonth = atoi(month.c_str());
			secondyear = atoi(year.c_str());
			secondhour = atoi(hour.c_str());
			secondminute = atoi(minute.c_str());
			secondsecond = atoi(second.c_str());
		}
	}

	void toSec() {

		res1 = 0;
		res2 = 0;
		int dop = 0;

		int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (secondyear != 0) {
			dop = secondyear - 1;
			while (dop % 4 != 0) {
				dop--;
			}
			res1 = ((dop) / 4) * 366;
			res1 += ((secondyear - 1) - (dop / 4)) * 365;
			for (int i = 0; i < secondmonth - 1; i++) {
				if (secondyear % 4 == 0 && i == 1) {
					res1 += arr[i] + 1;
				}
				else {
					res1 += arr[i];
				}
			}
			res1 += secondday - 1;
			res1 = res1 * 24;
		}

		res1 += secondhour;
		res1 = res1 * 60;
		res1 += secondminute;
		res1 = res1 * 60;
		res1 += secondsecond;

		if (secondyear != 0) {
			dop = iyear - 1;
			while (dop % 4 != 0) {
				dop--;
			}
			res2 = ((dop) / 4) * 366;
			res2 += ((iyear - 1) - (dop / 4)) * 365;
			for (int i = 0; i < imonth - 1; i++) {
				if (iyear % 4 == 0 && i == 1) {
					res2 += arr[i] + 1;
				}
				else {
					res2 += arr[i];
				}
			}
			res2 += iday - 1;
			res2 = res2 * 24;
		}

		res2 += ihour;
		res2 = res2 * 60;
		res2 += iminute;
		res2 = res2 * 60;
		res2 += isecond;
	}

	void diference() {

		unsigned long long res3;

		if (res1 > res2) {
			res3 = res1 - res2;
			check = 0;
		}
		else {
			res3 = res2 - res1;
			check = 1;
		}


		ressecond = res3 % 60;
		res3 = res3 / 60;
		resminute = res3 % 60;
		res3 = res3 / 60;
		reshour = res3 % 24;
		res3 = res3 / 24;
		resday = res3;
		resmonth = 0;
		resyear = 0;
	}

	void sum() {

		unsigned long long res3 = 0;
		int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		res3 = res2 + res1;

		ressecond = res3 % 60;
		res3 = res3 / 60;
		resminute = res3 % 60;
		res3 = res3 / 60;
		reshour = res3 % 24;
		res3 = res3 / 24;
		secondday += res3;
		resday = iday;
		resmonth = imonth;
		resyear = iyear;

		while (secondday != 0) {
			if (resyear % 4 == 0 && resmonth == 2) {
				if (resday == arr[resmonth - 1] + 1 && resmonth != 12) {
					resmonth += 1;
					resday = 1;
					secondday -= 1;
				}
				else if (resday == arr[resmonth - 1] + 1 && resmonth == 12) {
					resmonth = 1;
					resday = 1;
					resyear += 1;
					secondday -= 1;
				}
				else {
					resday += 1;
					secondday -= 1;
				}
			}
			else {
				if (resday == arr[resmonth - 1] && resmonth != 12) {
					resmonth += 1;
					resday = 1;
					secondday -= 1;
				}
				else if (resday == arr[resmonth - 1] && resmonth == 12) {
					resmonth = 1;
					resday = 1;
					resyear += 1;
					secondday -= 1;
				}
				else {
					resday += 1;
					secondday -= 1;
				}
			}
		}
	}

	void CTrue(bool check1) {
		check2 = 0;
		int arr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (check1 == 0) {
			if (iyear % 4 == 0 && imonth == 2) {
				if (iday > 0 && iday <= (arr[imonth - 1] + 1)) {
					if (ihour >= 0 && ihour < 24) {
						if (iminute >= 0 && iminute < 60) {
							if (isecond >= 0 && isecond < 60) {
								check2 = 1;
							}
						}
					}
				}
			}
			else {
				if (imonth > 0 && imonth < 13) {
					if (iday > 0 && iday <= arr[imonth - 1]) {
						if (ihour >= 0 && ihour < 24) {
							if (iminute >= 0 && iminute < 60) {
								if (isecond >= 0 && isecond < 60) {
									check2 = 1;
								}
							}
						}
					}
				}
			}
		}
		else {
			if (secondyear % 4 == 0 && secondmonth == 2) {
				if (secondday > 0 && secondday <= (arr[secondmonth - 1] + 1)) {
					if (secondhour >= 0 && secondhour < 24) {
						if (secondminute >= 0 && secondminute < 60) {
							if (secondsecond >= 0 && secondsecond < 60) {
								check2 = 1;
							}
						}
					}
				}
			}
			else {
				if (secondmonth > 0 && secondmonth < 13) {
					if (secondday > 0 && secondday <= arr[secondmonth - 1]) {
						if (secondhour >= 0 && secondhour < 24) {
							if (secondminute >= 0 && secondminute < 60) {
								if (secondsecond >= 0 && secondsecond < 60) {
									check2 = 1;
								}
							}
						}
					}
				}
			}
		}
	}

	void Get_Day() {

		int key = 0;
		string arr[7] = { "Monday", "Tuesday", "Wednasday", "Thursday", "Friday", "Saturday", "Sunday" };
		if (resday == 0) {
			TDay = arr[0];
		}
		if (check == 0) {
			while (resday != 0) {

				if (key == 0) {
					resday -= 1;
					key = 6;
				}
				else {
					key -= 1;
					resday -= 1;
				}
			}
		}
		else {
			while (resday != 0) {

				if (key == 6) {
					resday -= 1;
					key = 0;
				}
				else {
					key += 1;
					resday -= 1;
				}
			}
		}
		TDay = arr[key];
	}
};

string M;
void Menu() {
	cout << "    MENU\n"
		<< "(0) Quit\n"
		<< "(1) Comparison of the given date whith the current one\n"
		<< "(2) Adding the difference to the current date\n"
		<< "(3) Finding the day of the week\n"
		<< "Your choice: ";
	cin >> M;
};

int main()
{

	Date dt;

	Menu();

	while (M != "0") {

		if (M == "1") {
			system("cls");

			dt.checkTime();

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		else if (M == "2") {
			system("cls");

			dt.TwoTimes();

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		else if (M == "3") {
			system("cls");

			string state;
			cout << "(1) For current date\n"
				<< "(2) For given day\n"
				<< "Your choice: ";
			cin >> state;

			system("cls");

			if (state == "1") {
				dt.WeekDay1();
			}
			else if (state == "2") {
				dt.WeekDay();
			}
			else {
				cout << "Error\n";

				system("pause");
				system("cls");
				Menu();
				system("cls");
			}

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
		else {
			system("cls");

			cout << "There are not such option. Choose another.\n";

			system("pause");
			system("cls");
			Menu();
			system("cls");
		}
	}
}

