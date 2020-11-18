/***********************************************
* @Author Ralph Harris
* CSC 414 Software Design
* Storage class - simulates functions you might see in a class that uses a real database or
* local MS access file.
* Functions:
*   write - write to storage
*   read - reads from storage 
*   getUsers - returns the users as a vector
*   encryptDecrypt - simple method to ecrypt/decrypt password
*
* we basically have getters and setter for email, address, phoneNumber, and uniqueId.
*
*
************************************************/

#include <iostream>
#include <fstream>
#include<string> 
#include "User.h"
#include <vector>

using namespace std;

class Storage {

public:
    void write(string info) {
        ofstream myfile;
        myfile.open("users.txt");
        myfile << info + "\n";
        myfile.close();
    }
    string read() {
        string line, info;
        ifstream myfile("users.txt");
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                info += line + " ";
            }
            myfile.close();
        }
        else info = "Unable to open file\n";
        return info;
    }
    //pretty basic, but it does the job for our purpose!
    //@param string - the string to encrpt
    //@return string - decypted string
    string encryptDecrypt(string toEncrypt) {
        char key = 'hgc'; //just randomness
        string output = toEncrypt;
        for (int i = 0; i < toEncrypt.size(); i++)
            output[i] = toEncrypt[i] ^ key;
        return output;
    }
    vector<User> getUsers() {
        vector<User> users;
        Storage storage1;//storage simulator class
        string file = storage1.read();//read storage
        int size = 0;//iterate final users
        size_t start, end;
        while ((end = file.find("]")) < string::npos) {
            start = file.find("[");
            if (start < string::npos)file.erase(0, start + 1);
            end = file.find("]");
            string info = file.substr(0, end);
            //run while..
            users = setUserInfo(users, info);
            //cout << info << endl;
            file.erase(0, end + 1);
        }


        return users;
    }
    vector<User> setUserInfo(vector<User> users, string info) {
        size_t pos;
        int size = users.size();
        while ((pos = info.find(":")) < string::npos) {
            string left, right;
            left = info.substr(0, pos);
            info.erase(0, pos + 1);
            right = info.substr(0, info.find(","));
            if (left == "uniqueId") {
                User newUser;
                users.push_back(newUser);
                users.at(size).setUid(right);
            }
            else if (left == "firstName") {
                users.at(size).setFirstName(right);
            }
            else if (left == "lastName") {
                users.at(size).setLastName(right);
            }
            else if (left == "email") {
                users.at(size).setEmail(right);
            }
            else if (left == "phoneNumber") {
                users.at(size).setPhoneNumber((right));
            }
            else if (left == "role") {
                users.at(size).setRole(stoi(right));
            }
            else if (left == "hours") {
                double value = stod(right);
                users.at(size).incHoursinSeconds(value);
            }
            else if (left == "password") {
                users.at(size).setPassword(right);
                size++;
            }
            if (info.find(",") > 0)
                info.erase(0, info.find(",") + 1);
            else
                info.erase(0, info.length());
        }
        return users;
    }
};
