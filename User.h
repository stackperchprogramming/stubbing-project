#pragma once
using namespace std;
#include <string> 
#include <time.h>   
#include <sstream>
#include <iostream>
#include <ctime>
#include <vector>

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
		uniqueId,
		password,
		phoneNumber,
		error = "Error: This function has not yet been implemented.";
public:
	//initialize to -1 to indicate unset
	int role = 1;// 1 = employee, 2 = manager
	double seconds = 0;
	clock_t clockin, clockout;
	User() {};//default constructor

	//usual getters and setters for this class - self explanatory
	string getFirstName() { return firstName; }
	void setFirstName(string firstName) { this->firstName = firstName; }

	string getLastName() { return lastName; }
	void setLastName(string lastName) { this->lastName = lastName; }

	string getAddress() { return address; }
	void setAddress(string address) { this->address = address; }

	string getEmail() { return email; }
	void setEmail(string email) { this->email = email; }

	int getRole() { return role; }
	void setRole(int role) { this->role = role; }

	string getUId() { return uniqueId; }
	void setUid(string uniqueId) { this->uniqueId = uniqueId; }

	string getPhoneNumber() { return phoneNumber; }
	void setPhoneNumber(string PhoneNumber) { this->phoneNumber = phoneNumber; }

	string getPassword() { return password; }
	void setPassword(string password) { this->password = password; }

	int getClockIn() {
		return clockin / CLOCKS_PER_SEC;
	}
	void in() {
		clockin = clock();
	}
	void out() {
		clockout = clock();
		incSeconds((clockout - clockin) / CLOCKS_PER_SEC);

		std::cout << "You worked " << (clockout - clockin) / CLOCKS_PER_SEC << "[s]" << std::endl;
	}

	float getSeconds() {
		return seconds;
	}
	void incSeconds(long seconds) {
		this->seconds += seconds;
	}
	void incHoursinSeconds(double hours) {
		this->seconds += hours * 3600;
	}

	string printError() { return error; }
	//@return String should return a formatted string representation of the user's data
	string print() {
		float hours = seconds / 3600;
		string info = "[";
		info += "uniqueId:" + getUId();
		info += ",firstName:" + getFirstName();
		info += ",lastName:" + getLastName();
		info += ",email:" + getEmail();
		info += ",address:" + getAddress();
		info += ",phoneNumber:" + (getPhoneNumber());
		info += ",role:" + intToString(getRole());
		info += ",hours:" + doubleToString(hours);
		info += ",password:" + getPassword();
		info += "]";
		return info;
	}
	string printPretty() {
		string info = "";
		info += "uniqueId: " + getUId();
		info += "\nFirstName: " + getFirstName();
		info += "\nlastName: " + getLastName();
		info += "\nemail: " + getEmail();
		info += "\naddress: " + getAddress();
		info += "\nphoneNumber: " + (getPhoneNumber());
		info += "\nrole: " + intToString(getRole());
		info += "\npassword: " + getPassword();
		info += "\n";
		return info;
	}
	bool isEmpty() {
		if (uniqueId.length() < 1)return true;
		else return false;
	}
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
	string doubleToString(double num) {
		if (num != -1) {
			string str;
			stringstream ss;
			ss.precision(15);
			ss << num;
			ss >> str;
			return str;
		}
		else {
			return error;
		}
	}
};
