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
    int option = 0;
    double balance_1 = 1, balance_2 = 1; // balance on accout 1 and balance on account 2;
    int real_password = 1234;
    int pin = 0;
    int flag = 1;
    int account = 0;

public:
    AtmController() {
        
        cout << "Welcome to ATM Machine!" << endl;

        do {
            switch (flag) {
                // case 1: Insert Card.
                case 1:
                    cout << "Please insert card and press enter key: " << endl;
                    cin.ignore();

                // case 2: Enter password, if all three time in wrong pasword, the program exit.
                case 2:
                    if (!enterPassword()) {
                        flag = 5;
                        break;
                    } 

                // choose account, if all three times in wrong account, the program exit     
                case 3:
                    selectAccount(); 
                    if (account != 1 && account != 2) {
                        flag = 5;
                        break;
                    } 

                // balance checking, deposit, and withdraw service
                case 4:
                    if (account == 1) {
                        balance_1 = bankService(balance_1);
                    } else if (account == 2){
                        balance_2 = bankService(balance_2);
                    } 

                    if (flag == 3) {
                        break;
                    }
                // Exit progra1m;    
                case 5:
                    cout << "ATM Program exit" << "\n"; 
                    flag = 5;
                    break;
            }

        } while (flag != 5);
    }

    bool enterPassword() {
        //  Enter password, if all three time in wrong pasword, the program exit. 
        int count = 0;
        do {
            cout << "Enter you pin and press enter key: " << endl;
            cin >> pin;
            
            if  (pin != real_password) {
                count ++;
                cout << "wrong password." << endl; 
                cout << " " << endl;
                if (count >= 3) {
                    cout << "Too many times in wrong password. ATM program exit!" << endl;
                    return false;
                }  
            } else {
                return true;
            }    
        } while (1);
    }
 
    void selectAccount() {
        // choose account, if all three times in wrong account, the program exit     
        int count = 0;      
        do {
            // show account menu
            cout << "" << endl;
            cout << "**********ACCOUNT MENU *****" << endl;
            cout << "1. Checking Account" << endl;
            cout << "2. Saving Account" << endl;
            cout << "******************************" << endl;
            cout << "Please select account and then press enter key: " << endl;
            cin >> account;
            
            if (account == 1 || account == 2) {
                break;
            } else {
                count ++; 
                cout << "account not exist." << endl;    
                if (count >= 3) {
                    cout << "Too many time choosing wrong account. ATM program exist." << endl;
                    break;
                }
            }    
        } while (1);
    }

    // show menu fuction
    void showMenu() {
        cout << " " << endl;
        cout << "******* SERVICE MENU *********" << endl;
        cout << "1. Check balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Back to last account choosing menu" << endl;
        cout << "5. Exit" << endl;
        cout << "******************************" << endl;
    }  

    // balance checking, deposit, and withdraw service
    double bankService(double balance) {
        do {
            showMenu();
            cout << "Please choose an option of service and then press enter key: ";
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
                    cout << "Please insert money into cashbin" << endl;
                    cin.ignore();
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
                        cout << "Please get money into cash bin" << endl;
                        cin.ignore();
                        cout << "Withdraw success!" << endl;
                    } else {
                        cout << "Not enough money." << endl;
                    }
                    break;
                case 4: 
                    flag = 3;    
            }
        } while (option !=5 && option != 4);

        return balance;
    }
}; 


int main() {
    AtmController atmprogram;
    return 1;
}

