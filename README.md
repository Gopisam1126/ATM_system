# ATM System Simulation

The repository contains a simple C++ ATM simulation.  
The core components include:  
Account Class:  
&emsp;Manages account details such as account holder name, account number, balance, and a secret PIN. The balance and PIN are private.  
Transaction Class:  
&emsp;Handles transaction operations like checking the balance and withdrawing money. Verifies the user's credentials (using the secret PIN) before authorizing transactions.  
