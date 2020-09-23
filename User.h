#pragma once
using namespace std;
#include<string> 
#include <time.h>   
#include <sstream>
#include <iostream>
#include <random>
#include <time.h>


/***********************************************
* @Author Ralph Harris
* CSC 414 Software Design
* Stubbing project - This is a class I created for use in the stubbing project. I implemented basic
* functionality and added functions that you would usually see in this class.
* Functions:
*   getFirstName - returns the error message
*   setFirstName - returns the error message
*   getlastName - returns the error message
*   setlastName - returns the error message
*   intToString - returns a string from an int - just convienient for displaying the ID.
*
* we basically have getters and setter for email, address, phoneNumber, and uniqueId.
*
*
************************************************/

class User{

private:
	//these are self explanatory and basic for this class
	string firstName,
		lastName,
		address,
		email,
		error = "Error: This function has not yet been implemented.";


public:
	//initialize to -1 to indicate unset
	int phoneNumber = -1,
		uniqueId = -1;
	User() {};//default constructor

	//usual getters and setters for this class - self explanatory
	string getFirstName() { cout << printError(); }
	void setFirstName(string firstName) { cout << printError(); }

	string getLastName() { cout << printError(); }
	void setLastName(string lastName) { cout << printError(); }

	string getAddress() { cout << printError(); }
	void setAddress(string address) { cout << printError(); }

	string getEmail() { cout << printError(); }
	void setEmail(string email) { cout << printError(); }

	int getUId() { return uniqueId; }
	void setUid(int UId) { this->uniqueId = UId; }

	int getPhoneNumber() { cout << printError(); }
	void setPhoneNumber(string PhoneNumber) { cout << printError(); }

	string printError() { return error; }
	//@return String should return a formatted string representation of the user's data
	string print() { return error; }

	void setError(string error) { this->error = error; }
	string intToString(int integer) {
		if (integer != -1) {
			string str;
			stringstream ss;
			ss << integer;
			ss >> str;
			return str;
		}
		else {
			return error;
		}
	}
};
