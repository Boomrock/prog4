#pragma once
#include <iostream>
using namespace std;
class Buyer
{

public:
	string LastName;
	short YearOfBirth;
	long long TelephoneNumber;
	string Address;
	int AccountNumber;
	enum ValueName
	{
		LastNameEnum = 1,
		YearOfBirthEnum = 2,
		TelephoneNumberEnum = 3,
		AddressEnum = 4,
		AccountNumberEnum = 5

	};

	Buyer(string lastName, short yearOfBirth, long long telephoneNumber, string address, int accountNumber) {


		LastName = lastName;
		YearOfBirth = yearOfBirth;
		TelephoneNumber = telephoneNumber;
		Address = address;
		AccountNumber = accountNumber;
	}
	Buyer(string lastName, short yearOfBirth, long long telephoneNumber, string address) {


		LastName = lastName;
		YearOfBirth = yearOfBirth;
		TelephoneNumber = telephoneNumber;
		Address = address;
		AccountNumber = 0;

	}
	Buyer(string lastName, short yearOfBirth, long long telephoneNumber) {


		LastName = lastName;
		YearOfBirth = yearOfBirth;
		TelephoneNumber = telephoneNumber;
		Address = "";
		AccountNumber = 0;
	}
	Buyer(string lastName, short yearOfBirth) {


		LastName = lastName;
		YearOfBirth = yearOfBirth;
		TelephoneNumber = 0;
		Address = "";
		AccountNumber = 0;
	}
	Buyer(string lastName) {


		LastName = lastName;
		YearOfBirth = 0;
		TelephoneNumber = 0;
		Address = "";
		AccountNumber = 0;
		cout << LastName;

	}
	Buyer() {
		LastName = "0";
		YearOfBirth = 0;
		TelephoneNumber = 0;
		Address = "0";
		AccountNumber = 0;
	}

	

};


