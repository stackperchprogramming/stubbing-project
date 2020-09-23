/***********************************************
* @Author Ralph Harris
* CSC 414 Software Design
* Stubbing project - This is a menu used to manage users (possibly in a database). 
* Functions:
*   showMenu - shows the initial menu
************************************************/

#include <iostream>
#include <stdio.h>
#include <vector>
#include "User.h"
using namespace std;

//displays the menu within the console
void showMenu() {
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
int main()
{
    int choice;//users choice and any values to get from the user
    vector<User> users;//stores each created/selected user
    User user;//selected user
    do {//loop
        showMenu();//show menu each loop
        cin >> choice;//get choice from menu
        switch (choice) {
            case 1: {//create user
                User newUser;
                users.push_back(newUser);
                cout << "new user created: user " + newUser.intToString(newUser.getUId()) << endl;
                system("pause");
                break;
            }
            case 2: {//select user - TODO: delete the forced setting of the user ID (used to test if this works with Vector<User>).
                int count = 0,
                    userChoice;
                for (User thisUser : users) {
                    //just to make this option run as is..
                    thisUser.setUid(count + 6476);//TODO: remove before production
                    //and.. continue
                    cout << "select a user" << endl;
                    cout << count << ". user " <<thisUser.intToString(thisUser.getUId())<< endl;//show user by user ID
                    count++;//used to track user index
                }
                cout << endl;
                cin >> userChoice;//get index (user choice)
                cout << "user " << choice << " selected" << endl;//show 'selected' message
                user = users[userChoice];//set user - TODO: test this

                system("pause");
                break;
            }
            case 3://delete user
                cout << user.printError() << endl;
                system("pause");
                break;
            case 4: {//set first name
                string name;
                cout << "enter the user's first name: " << endl;
                cin >> name;
                user.setFirstName(name);
                cout << "the user's first name has been changed: " << user.printError() << endl;
                system("pause");
                break;
            }case 5: {//set last name
                string name;
                cout << "enter the user's last name: " << endl;
                cin >> name;
                user.setLastName(name);
                cout << "the user's last name has been changed: " << user.printError() << endl;
                system("pause");
                break;
            }case 6: {//set phone number
                string phone;
                cout << "enter the user's phone number: " << endl;
                cin >> phone;
                user.setPhoneNumber(phone);
                cout << "the user's phone number has been changed: " << user.printError() << endl;
                system("pause");
                break;
            }case 7: {//set Email
                string email;
                cout << "enter the user's Email: " << endl;
                cin >> email;
                user.setEmail(email);
                cout << "the user's Email has been changed: " << user.printError() << endl;
                system("pause");
                break;
            }case 8: {//show all users
                int count = 0;
                for (User thisUser : users) {
                    cout << "user " << count+1 << ": " << thisUser.printError() << endl;
                }
                system("pause");
                break;
            }case 9: {//print selected user information
                cout << user.print() << endl;
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
    return 0;
}
