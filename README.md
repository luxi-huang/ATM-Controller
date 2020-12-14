# ATM Controller
- Author: Luxi Huang

## Introduction: 
- This program is designed for a simple ATM controller. 
- It contains following flows: 

 <p align="middle"> <img src="https://github.com/luxi-huang/ATM-Controller/blob/main/img/flow_chart.png?raw=true" alt="drawing" /> </p>  

 ## Process:
 ### 1. Insert Card:
 - It will ask user to insert card, and press enter key after they done. 
 - Assume you have insert card, just press enter key and move to next step.
  
 ### 2. Enter PIN:
 - Correct pin number is "1234". 
 - It will ask user to enter pin number.
 - If the pin is correct, then system will move to next step.
 - If pin is not correct, the system will ask user to enter again. If user enter pin in correct for three times, the system would exit. 
 
 ### 3. Choose Account:
 - It will ask user to choose checking account or saving account.
 - The system would exit if user choose invalid account for three time. 

 ### 4. Service:
  - There are 5 options that user can choose from the service menu.
  - Option 1 -- Balance: user can check the account balance.
  - Option 2 -- Deposit: user can enter deposit values, and insert money into cash bin. 
  - Option 3 -- Withdraw: user can enter how much money they want to withdraw, which should greater than current balance. Then get money from cash bin.
  - Option 4 -- Back to account choosing menu.
  - Option 5 -- Exit system.
 
 ### 5. Exit:
  - Exit System. 

## How to run program:
- Step 1: clone github files:
   - ```git clone https://github.com/luxi-huang/ATM-Controller.git``` 
- Step 2: go to ATM-Controller files:
   - ``` cd ATM-Controller ```
- Step 3: compile files:
   - ``` g++ -std=c++11 ATM_Controller.cpp ```
- Step4 : run files:
  - ./a.out 

 






