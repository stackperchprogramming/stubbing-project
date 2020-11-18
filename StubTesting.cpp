/***********************************************
* @Author Ralph Harris
* CSC 414 Software Design
* Stubbing project - This is a menu used to manage users (possibly in a database). 
* Functions:
*   showAdminMenu - shows admin menu options
************************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
#include "User.h"
#include "Storage.h"
#include <cstdlib>

using namespace std;

void showAdminMenu() {
    cout << endl << endl;
    cout << "************ User management menu ************" << endl;
    cout << "Choose from the options below: " << endl;
    cout << "1. Create a new user." << endl;
    cout << "2. Select a user" << endl;
    cout << "3. Delete a user" << endl;
    cout << "4. Create or update user's first name" << endl;
    cout << "5. Create or update user's last name" << endl;
    cout << "6. Create or update user's phone number" << endl;
    cout << "7. Create or update user's Email address" << endl;
    cout << "8. Show all users" << endl;
    cout << "9. Show all of the selected user's information" << endl;
    cout << "10. Exit" << endl;
}

int showEmployeeMenu() {
    int choice;
    cout << endl << endl;
    cout << "************ Employee menu ************" << endl;
    cout << "Choose from the options below: " << endl;
    cout << "1. Clock-in." << endl;
    cout << "2. Clock-out" << endl;
    cout << "10. Exit" << endl;
    cin >> choice;
    return choice;
}
void saveInfo(vector<User>users) {
    Storage connection;
    string userInfo = "";
    for (int i = 0; i < users.size(); i++) {
        userInfo += users.at(i).print();
        connection.write(userInfo);
    }
}
User getEmployeeMenu(vector<User> users, User loggedInUser) {
    int choice;
    do {
        choice = showEmployeeMenu();
        if (choice == 1) {
            loggedInUser.in();
            cout << "You are clocked in." << endl;
        }
        else if (choice == 2) {
            loggedInUser.out();
            cout << "You have clocked out." << endl;
            for (int i = 0; i < users.size(); i++)
                if (users.at(i).getUId() == loggedInUser.getUId())
                    users.at(i) = loggedInUser;
            saveInfo(users);
            break;
        }
        else {
            cout << "Incorrect action." << endl;
            system("pause");
        }
    } while (choice != 10);
    return loggedInUser;
}
User showLoginMenu(vector<User> users) {
    string userId, password;
    User user;
    cout << endl << endl;
    cout << "************ Login menu ************" << endl;
    cout << "please login below: " << endl;
    cout << "Enter username: ";
    cin >> userId;

    for (int i = 0; i < users.size(); i++) {
        if (userId == users.at(i).getUId())
            user = users.at(i);
    }
    if (user.getUId() == userId) {
        cout << endl << "Enter password: ";
        cin >> password;
        if (user.getPassword() == password) {
            cout << "Success! You are logged in." << endl;
            return user;
        }
        else {
            cout << "incorect password!";
            showLoginMenu(users);
        }
    }
    else {
        cout << "incorrect username!";
        showLoginMenu(users);
    }
}
vector<User> getAdminMenu(vector<User> users,User selectedUser) {
    int choice;//users choice and any values to get from the user
    User user = selectedUser;//selected user
    do {
        showAdminMenu();
        cin >> choice;
        switch (choice) {
        case 1: {
            User newUser;
            string userId,
                firstName,
                lastName,
                address,
                email,
                role,
                phoneNumber,
                password;
            users.push_back(newUser);
            cout << "enter the new user's ID." << endl;
            cin >> (userId);
            newUser.setUid(userId);
            cout <<endl<< "enter the new user's first name.\n";
            cin >> firstName;
            newUser.setFirstName(firstName);
            cout << endl << "enter the new user's last name.\n";
            cin >> lastName;
            newUser.setLastName(lastName);
            cout << endl << "enter the new user's address.\n";
            cin.get();
            getline(cin, address);
            newUser.setAddress(address);
            cin.sync();
            cout << endl << "enter the new user's phone number.\n";
            cin >> phoneNumber;
            if (phoneNumber.length() < 5) {
                cout << "Error: Phone number must be greater that 6 characters";
                break;
            }
            newUser.setPhoneNumber(phoneNumber);
            cout << endl << "enter the new user's role in the company (0 for employee, 1 for manager).\n";
            cin >> role;
            if(role == "1" || role == "0")
                newUser.setRole(stoi(role));
            else
            {
                cout << "Error: role must be numerical 1 for manager or 0 for employee.";
                system("pause");
                break;
            }
            cout << endl << "enter the new user's email address.\n";
            cin >> email;
            newUser.setEmail(email);
            cout << endl << "enter the new user's login password.\n";
            cin >> (password);
            newUser.setPassword(password);
            cout << "new user created: user " + newUser.getUId() << endl;
            users.push_back(newUser);
            saveInfo(users);
            system("pause");
            user = newUser;
            break;
        }
        case 2: {
            int count = 0,
                userChoice;
            cout << "\n\nselect a user:" << endl << endl;
            for (count = 0; count < users.size();count++) {
                User thisUser = users.at(count);
                cout << count << ". user " << (thisUser.getUId()) << ": " << thisUser.getFirstName() << " " << thisUser.getLastName() << endl;
            }
            cout << endl;
            cin >> userChoice;//get index (user choice)
            cout << "user " << userChoice << " selected" << endl;
            user = users[userChoice];//set user - TODO: test this

            system("pause");
            break;
        }
        case 3: {
            int count = 0,
            userChoice = 0;
            cout << "\n\nselect a user to delete:" << endl << endl;
            for (count = 0; count < users.size(); count++) {
                User thisUser = users.at(count);
                cout << count << ". user " << (thisUser.getUId()) << ": " << thisUser.getFirstName() << " " << thisUser.getLastName() << endl;
            }
            cout << endl;
            cin >> userChoice;//get index (user choice)
            cout << "user " << userChoice << " deleted" << endl;
            users.erase(users.begin() + userChoice);
            system("pause");
            break;
        }case 4: {
            string name;
            cout << "enter the user's first name: " << endl;
            cin >> name;
            user.setFirstName(name);
            cout << "the user's first name has been changed: " << user.getFirstName() << endl;
            for (int i = 0; i < users.size();i++) {
                User thisUser = users.at(i);
                if (thisUser.getUId() == user.getUId())
                    users.at(i) = user;
            }
            saveInfo(users);
            system("pause");
            break;
        }case 5: {
            string name;
            cout << "enter the user's last name: " << endl;
            cin >> name;
            user.setLastName(name);
            cout << "the user's last name has been changed: " << user.printError() << endl;
            for (int i = 0; i < users.size(); i++) {
                User thisUser = users.at(i);
                if (thisUser.getUId() == user.getUId())
                    users.at(i) = user;
            }
            saveInfo(users);
            system("pause");
            break;
        }case 6: {
            string phone;
            cout << "enter the user's phone number: " << endl;
            cin >> phone;
            user.setPhoneNumber((phone));
            cout << "the user's phone number has been changed: " << user.printError() << endl;
            for (int i = 0; i < users.size(); i++) {
                User thisUser = users.at(i);
                if (thisUser.getUId() == user.getUId())
                    users.at(i) = user;
            }
            system("pause");
            break;
        }case 7: {
            string email;
            cout << "enter the user's Email: " << endl;
            cin >> email;
            user.setEmail(email);
            cout << "the user's Email has been changed: " << user.getEmail() << endl;
            for (int i = 0; i < users.size(); i++) {
                User thisUser = users.at(i);
                if (thisUser.getUId() == user.getUId())
                    users.at(i) = user;
            }
            saveInfo(users);
            system("pause");
            break;
        }case 8: {
            int count = 0;
            for (User thisUser : users) {
                cout << "user " << count + 1 << ":\n" << thisUser.printPretty() << endl;
                count++;
            }
            system("pause");
            break;
        }case 9: {
            cout << user.printPretty() << endl;
            system("pause");
            break;
        }case 10://prevent default and exit
            break;
        default:
            cout << "Invalid entry. Try again.";
            system("pause");
            break;
        }
    } while (choice != 10);

    system("pause");
    return users;
}
int main()
{
    Storage storage;//initialize db
    vector<User> users = storage.getUsers();//pull users as vector type array
    User loggedInUser;
    do {//show menu, while...
        loggedInUser = showLoginMenu(users);
        if (loggedInUser.getRole() == 0) {//employee
            getEmployeeMenu(users, loggedInUser);
        }
        else if(loggedInUser.getRole() == 1) {//manager
            getAdminMenu(users, loggedInUser);
        }
    } while ( loggedInUser.getUId().length() > 0);//...while loggedInUser is a defined user
   
    return 0;
}
