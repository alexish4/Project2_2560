#include <iostream>
#include <fstream>
using namespace std;

enum day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
	int month;
	int year;
	int dayOfTheWeek;

	cout << Sunday << " is sunday" << endl;

	cout << "Calendar by A. Hernandez" << endl;
	cout << endl;
	cout << "Enter month year? ";
	cin >> month >> year;

	string monthName;
	int daysOfTheMonth = 31;

	bool leapYear = false;
	if(year % 4 == 0)
		leapYear = true;

	if(month == 1)
		monthName = "January";
	else if(month == 2) {
		monthName = "February";
		if(leapYear)
			daysOfTheMonth = 29;
		else
			daysOfTheMonth = 28;
	}
	else if(month == 3)
		monthName = "March";
	else if(month == 4) {
		monthName = "April";
		daysOfTheMonth = 30;
	}
	else if(month == 5)
		monthName = "May";
	else if(month == 6) {
		monthName = "June";
		daysOfTheMonth = 30;
	}
	else if(month == 7)
		monthName = "July";
	else if(month == 8)
		monthName = "August";
	else if(month == 9) {
		monthName = "September";
		daysOfTheMonth = 30;
	}
	else if(month == 10)
		monthName = "October";
	else if(month == 11) {
		monthName = "November";
		daysOfTheMonth = 30;
	}
	else if(month == 12)
		monthName = "December";

	string fileName = to_string(month) + "-" + to_string(year) + ".txt";
	ofstream calendarFile;
	calendarFile.open(fileName);

	if(!calendarFile) //if file doesn't exist creat a new one
		return 1;

	calendarFile << monthName<< "•" << year << endl;
	calendarFile << "Sun••Mon••Tue••Wed••Thu••Fri••Sat" << endl;
	calendarFile << "---------------------------------" << endl;

	calendarFile.close();

	return 0;
}
