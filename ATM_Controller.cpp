/* **********************************************************************************************
 * Simple ATM Controller
 * Author: Luxi Huang 
 * 
 * Introduction: 
 *      This program is a simple ATM controller to interact with user。 
 * 
 * It has 4 process: 
 *     insert card -> enter password -> service(cheking balance, withdraw, and widraw) -> Exit 
 * 
 * The correct password of your card is : 1234. 
 * Please use as the commands on window, and enjoy!
 * 
 * More infomation please view at: https://github.com/luxi-huang/ATM-Controller 
 ***********************************************************************************************/

#include <iostream>
using namespace std;

class AtmController {
private:
    int option;
    double balance = 100;
    int real_password = 1234;
    int pin;
    int count = 0;

public:
    AtmController() {
        cout << "Welcome to ATM Machine!" << endl;
        cout << "Please insert card and press enter key: " << endl;
        cin.ignore();

        // Enter passward
        do{
            cout << "Enter you pin and press enter key: " << endl;
            cin >> pin;
            // when pin is correct, then ATM will start balance checking, deposit, and withdraw service.
            if (pin == real_password) {
                cout << "password correct!" <<  endl; 
                bankService();
            } else {
                // if password is not correct
                count ++;
                cout << "wrong password." << endl; 
                cout << " " << endl;
                // if wrong password time greater than 3
                if (count >= 3) {
                    cout << "Too many times in wrong password. ATM program exit!" << endl;
                    count = 0;
                    break;
                }   
            }      
        } while (option!=4);     
    }

    // show menu fuction
    void showMenu() {
        cout << " " << endl;
        cout << "********** MENU **************" <<endl;
        cout << "1. Check balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "******************************" << endl;
    }   

    // balance checking, deposit, and withdraw service
    void bankService() {
        do {
            showMenu();
            cout << "Please choose an option of service and press enter key: ";
            cin >> option;

            switch(option) {
                //case 1: Balance case 
                case 1:
                    cout << "Balance: $ " << balance << endl;
                    break;
                // case2: Deposit
                case 2:
                    cout << "Please enter deposit amount and press enter key: ";
                    double depositAmount;
                    cin >> depositAmount;
                    balance += depositAmount;
                    cout << "Deposit Success!" << endl;
                    break;
                // case3: Withdraw     
                case 3:
                    cout << "Please enter withdraw amount and press enter key: ";
                    double withdrawAmount;
                    cin >> withdrawAmount;
                    if (withdrawAmount <= balance) {
                        cout << "Please insert money and press enter key: ";
                        balance -= withdrawAmount;
                        cout << "Withdraw success!" << endl;
                    } else {
                        cout << "Not enough money." << endl;
                    }
                    break;
            }
        }while (option!=4);
    }
}; 


int main(){
    AtmController atmprogram;
    return 1;
}

