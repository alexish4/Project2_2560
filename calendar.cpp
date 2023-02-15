#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int month;
	int year;
	cout << "Calendar by A. Hernandez" << endl;
	cout << endl;
	cout << "Enter month year? ";
	cin >> month >> year;

	string monthName;

	if(month == 1)
		monthName = "January";
	else if(month == 2)
		monthName = "February";
	else if(month == 3)
		monthName = "March";
	else if(month == 4)
		monthName = "April";
	else if(month == 5)
		monthName = "May";
	else if(month == 6)
		monthName = "June";
	else if(month == 7)
		monthName = "July";
	else if(month == 8)
		monthName = "August";
	else if(month == 9)
		monthName = "September";
	else if(month == 10)
		monthName = "October";
	else if(month == 11)
		monthName = "November";
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
