//Name : Syed Ali Ahmed
//Roll No : 4308
// 
// OOP AirTime Project, It  Set,diplay the time taken from the Syestem,
//  And show the time taken to complete the flight according to the arrvial And Departure 
//time

#include <iostream>
#include<cctype>
#include<windows.h>
using namespace std;
class AirTime {
	unsigned int hrs, min, sec;              //declearing data members privately
public:
	AirTime(int hrs, int min, int sec) {
		this->hrs = hrs;
		this->min = min;
		this->sec = sec;
	}
	AirTime() {
		hrs = 0, min = 0, sec = 0;             //creating constructors
	}

	void setTime();
	void displTime();					    ///public member function
	AirTime operator-(AirTime);
	bool operator>(AirTime);
};

//declearing the function
void menu();        //shows the main menu
void submenu1();    //shows the initializatons menu
void submenu2();   //shows the arrival menu
void submenu3();   //shows the departure menu
void initProcess(int option, AirTime& arrival, AirTime& depart);  // all cases and process of initilaization
void arrivProcess(int option, AirTime& arrival);                  //all cases and process of arrival 
void departProcess(int option, AirTime& depart);                  //all cases and process of departure
void difference(AirTime arrival,AirTime depart,AirTime differ);  //Time taken to complete the flight
/// Either arrival or departure is greater
bool AirTime::operator>(AirTime t) {
	if (hrs > t.hrs) {
		return true;
	}
	else {
		if (hrs == t.hrs && min > t.min) {
			return true;
		}
		else {
			if (hrs == t.hrs && min == t.min && sec > t.sec) {
				return true;
			}
			else {
				return false;
			}

		}
	}
}
/// finding difference between arrival and departure time
AirTime AirTime:: operator-(AirTime t2) {
	AirTime temp;
	temp.hrs = (hrs - t2.hrs);
	temp.min = min - t2.min;
	temp.sec = sec - t2.sec;
	return temp;
}

// setting or approaching to the current computer time and set the value to that time
void AirTime::setTime() {
	SYSTEMTIME currTime;
	GetSystemTime(&currTime);

	hrs = (currTime.wHour + 5) % 12;
	if (hrs == 0) {
		hrs = 12;
	}

	min = (currTime.wMinute);

	sec = currTime.wSecond;
	cout << endl;
}
/// displaying the setted time
void AirTime::displTime() {
	cout << hrs << " / " << min << " / " << sec;
}




int main()
{
	AirTime arrival, depart, differ;           //creating three objects 
	do {
		menu();
		char option;
		cout << "                               Chose your option         " << endl;
		cin >> option;
		switch (option) {
		case '1':
			submenu1();
			char option1;
			cout << "                            Chose your option         " << endl;
			cin >> option1;
			initProcess(option1, arrival, depart);
			break;

		case '2':
			submenu2();
			char option2;
			cout << "                         Chose Your Option                 " << endl;
			cin >> option2;
			arrivProcess(option2, arrival);
			break;

		case '3':
			submenu3();
			char option3;
			cout << "                   Chose Your Option                      " << endl;
			cin >> option3;
			departProcess(option3, depart);
			break;

		case '4':
		 difference(arrival, depart, differ);
			cout << endl;
		default:
			cout << "              Chose The Correct Option                    " << endl;
		}
	} while (true);
}



void menu() {
	cout << "                           1.        Initialization       " << endl;
	cout << "                           2.Set or display arrivalTime   " << endl;
	cout << "                           3.Set or display departure Time" << endl;
	cout << "                           4.Time Taken To Complete The Flight" << endl;
	cout << "                           5.           to exit           " << endl;
	cout << endl;
}
void submenu1() {
	cout << "                           1.        Set Arrival Time      " << endl;
	cout << "                           2.       Set Departure Time     " << endl;
	cout << "                           3.Set Both Arrival and departure Time" << endl;
	cout << "                           4.   to Go Back To Main Menu     " << endl;
}
void submenu2() {
	cout << "                           1.        Set Arrival Time       " << endl;
	cout << "                           2.      Display Arrival Time     " << endl;
	cout << "                           3.      Go Back To Main Menu     " << endl;
}
void submenu3() {
	cout << "                           1.      Set Departure Time       " << endl;
	cout << "                           2.     Display Departure Time    " << endl;
	cout << "                           3.     Go Back To Main Menu      " << endl;
}

void initProcess(int option, AirTime& arrival, AirTime& depart) {
	switch (option) {
	case '1':
		arrival.setTime();
		cout << "              Current Time Is Set As Arrival Time  " << endl;
		cout << endl;
		break;
	case '2':
		depart.setTime();
		cout << "              Current Time Is Set As Departure Time " << endl;
		cout << endl;
		break;
	case '3':
		arrival.setTime();
		depart.setTime();
		cout << "              Current Time Is Set As Arrival And Departure Time" << endl;
		cout << endl;
		break;
	case '4':
		break;
	default:
		cout << "                    enter the valid option            " << endl;
	}
}

void arrivProcess(int option, AirTime& arrival) {
	switch (option) {
	case '1':
		arrival.setTime();
		cout << "              Current Time Is Set As Arrival Time     " << endl;
		break;
	case '2':
		arrival.displTime();
		cout << endl;
		break;
	case '3':
		break;
	default:
		cout << "             enter the correct option                 " << endl;
	}
}

void departProcess(int option, AirTime& depart) {
	switch (option) {
	case '1':
		depart.setTime();
		cout << "            Current Time Is Set As Departure Time     " << endl;
		cout << endl;
		break;
	case '2':
		depart.displTime();
		cout << endl;
		break;
	case '3':
		break;
	default:
		cout << "           Chose The Correct Option                   " << endl;
	}
}

void difference(AirTime arrival, AirTime depart, AirTime differ) {
	if (depart > arrival)
		differ = depart - arrival;
	else
		differ = arrival - depart;
	cout << "Arrival Time was " << endl;
	arrival.displTime();
	cout << endl;
	cout << "Departure Time was " << endl;
	depart.displTime();
	cout << endl;
	cout << "Total Time Taken To Complete the flight was " << endl;
	differ.displTime();
}
