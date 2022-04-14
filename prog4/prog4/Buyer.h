#pragma once
#include <iostream>
using namespace std;

class Buyer
{
	
	public:
		string LastName;
		short YearOfBirth;
		int TelephoneNumber;
		string Address;
		int AccountNumber;
		Buyer(string lastName, short yearOfBirth, int telephoneNumber, string address, int accountNumber) {


			string LastName = lastName;
			short YearOfBirth = yearOfBirth;
			int TelephoneNumber = telephoneNumber;
			string Address = address;
			int AccountNumber = accountNumber;
		}
		Buyer(string lastName, short yearOfBirth, int telephoneNumber, string address) {


			string LastName = lastName;
			short YearOfBirth = yearOfBirth;
			int TelephoneNumber = telephoneNumber;
			string Address = address;
		}
		Buyer(string lastName, short yearOfBirth, int telephoneNumber) {


			string LastName = lastName;
			short YearOfBirth = yearOfBirth;
			int TelephoneNumber = telephoneNumber;
		}
		Buyer(string lastName, short yearOfBirth) {


			string LastName = lastName;
			short YearOfBirth = yearOfBirth;
		}
		Buyer(string lastName) {


			string LastName = lastName;
			cout << LastName;

		}
	
};

