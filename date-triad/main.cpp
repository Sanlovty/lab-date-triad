#include <iostream>

#include "Date.h"
using namespace std;

int main()
{
	try
	{
		Date date(10, 15, 2001);

		cout << "Initial date: " << date.toString();
		date.increaseDateByN(10);
		cout << endl << "Date after 10 days: " << date.toString();
		date.increaseFirst();
		cout << endl << "Date after applying method increaseFirst(): " << date.toString();
		date.increaseSecond();
		cout << endl << "Date after applying method increaseSecond(): " << date.toString();
		date.increaseThird();
		cout << endl << "Date after applying method increaseThird(): " << date.toString();
		date.increaseTuple();
		cout << endl << "Date after applying method increaseTuple(): " << date.toString();
	}
	catch (const exception& ex)
	{
		cout << "Error: " << ex.what();
	}
	return 0;
}
