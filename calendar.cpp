//
//	Name:		Hernandez, Alex
//	Homework:	2
//	Due:		2/20/23
//	Course:		cs-2560-01-sp23
//	Description:
//				A program that outputs a calendar month into a file
//				based on user input. Assumes user input is correct,
//				also there are checks to see if file already exists.
//				If not it creates a new file.
//

#include <iostream>
#include <fstream>
using namespace std;

enum day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

int main() {
	int month;
	int year;
	int date = 1; //start at 1

	cout << "Calendar by A. Hernandez" << endl;
	cout << endl;
	cout << "Enter month year? ";
	cin >> month >> year;
	cout << endl;

	string monthName;
	int daysOfTheMonth = 31;
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12.0*a - 2;
	int dow = (date + y + y/4 - y/100 + y/400 + 31*m/12) % 7;

	bool leapYear = false; 
	if(year % 4 == 0) {
		if(year % 100 != 0)
			leapYear = true;
		else {
			if(year % 400 == 0)
				leapYear = true;
		}
	}

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
	cout << fileName << " file generated." << endl;
	ofstream calendarFile;
	calendarFile.open(fileName);

	if(!calendarFile) //if file doesn't exist create a new one
		return 1;

	calendarFile << monthName<< " " << year << endl;
	calendarFile << "Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
	calendarFile << "---------------------------------" << endl;
	for(int i = 0; i < dow; i++) { /*if first week and Sunday isn't the first day 
										continue until we reach first day*/
		if(i == 0) //identation for sunday
			calendarFile << " ";
		calendarFile << "     ";
	}
	while (date <= daysOfTheMonth) {
		if(dow == Sunday)
			calendarFile << " ";
		calendarFile << setw(2) << date;
		if(dow == Saturday)
			calendarFile << endl;
		else 
			calendarFile << "   ";
		date++;
		dow = static_cast<int>((date + y + y/4 - y/100 + y/400 + 31*m/12)) % 7;
	}
	calendarFile << endl;

	calendarFile.close();

	return 0;
}
