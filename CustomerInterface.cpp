//Andres Suarez
//Software Engineering 1

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;



//BANK INTERFACE
class Bank{
public:
    int CardNo;
    int x;
    

    void Authorize(int);
};

//EMAIL SERVER INTERFACE
class Email{
public:
    string CustomerEmail;
    

    void EmailConfirmation(string);
};

//CUSTOMER ACCOUNT
class CustomerAccount{
public:
    int AccountID;
    int CardNo;
    string CustomerEmail;
    
    
    void ReadAccountInfo(int, int);
    void CreateAccount(int, int, string);
    void UpdateCardNo(int, int);
};
    
//DELIVERY ORDER
class DeliveryOrder{
public:
    int AccountID;
    string OrderContents;
    int AuthorizationNo;
    
    void CreateOrder(int, int, int);
};

//CUSTOMER INTERFACE
class Customer{
public:
    int AccountID;
    
    void Request(int, int);
    void CreateAccRequestOrder(int, int);
    void RequestOrderWithNewCardNo(int, int);
    void Cancel();
};

//BUSINESS LOGIC
class PurchaseOrderManager{
public:
    int AccountID;
    int Order;
    string CustomerEmail;
    
    void RequestOrder(int, int);
    void CreateAccRequestOrder(int, int);
    void RequestOrderWithNewCardNo(int, int);
};

//MAIN
int main()
{
    srand(time(NULL));
    int x = 0;
    int choice = 0;
	int CardNo = 0;
    int Order = 0;
    int AccountID = 0;
    
    PurchaseOrderManager POM;
    Customer customer;
    
    cout << "\nWelcome to the Online Shopping System!\n";
    cout << "***MAIN MENU***\n\n";
    
    cout << "Select (1) to Enter Order Information\n";
    cout << "Select (2) to Create New Order\n";
    cout << "Select (3) to Order with a New Card\n";
    cout << "Select (4) to Exit\n";
    cout << "Enter Choice: ";
    cin >> choice;
    cout << endl;
    
    do{
    	switch (choice){
        case 1:
            cout << "***ORDER INFORMATION***\n";
            customer.Request(AccountID, Order);
            exit(0);
            break;
        
        case 2:
            cout << "***NEW ORDER INFORMATION***\n";
            customer.CreateAccRequestOrder(AccountID, CardNo);
            break;
        
        case 3:
        	cout << "***ORDER WITH NEW CARD***\n";
        	customer.RequestOrderWithNewCardNo(AccountID, CardNo);
        	break;
        case 4:
            cout << "Thank you for shopping with us!\n";
            customer.Cancel();
            break;
        default:
            cout << "INVALID CHOICE!\n";
            break;
        }
    }while (choice != 4);
        return 0;
	
}


//METHOD DEFINITIONS

void Customer::Request(int CardNo, int AccountID){
	
    
    cout << "Enter 3 Digit Account ID: ";
    cin >> AccountID;
    this->AccountID = AccountID;
    
    CustomerAccount CA;
    CA.ReadAccountInfo(AccountID, CardNo);
}

void Customer::CreateAccRequestOrder(int AccountID, int CardNo){
    int OrderNo = 0;
    
    cout << "Enter 3 Digit Account ID: ";
    cin >> AccountID;
    this->AccountID = AccountID;
    
    PurchaseOrderManager POM;
    POM.CreateAccRequestOrder(AccountID, OrderNo);
}

void Customer::RequestOrderWithNewCardNo(int AccountID, int CardNo){
    
    cout << "Enter 3 Digit Account ID: ";
    cin >> AccountID;
    this->AccountID = AccountID;
    
    PurchaseOrderManager POM;
    POM.RequestOrderWithNewCardNo(AccountID, CardNo);
}

void Customer::Cancel(){
    exit(0);
}

void PurchaseOrderManager::RequestOrder(int Order, int AccountID){
    //Prompts user to enter Account ID
	cout << "Enter 3 Digit User ID to continue order: ";
	cin >> AccountID;
	this->AccountID = AccountID;
	
	cout << "Enter Order Number: ";
	cin >> Order;
	this->Order = Order;
	

}

void CustomerAccount::ReadAccountInfo(int AccountID, int CardNo){
   
   this->AccountID = AccountID;
   this->CardNo = CardNo;
   
   if(AccountID == 123){
	srand(time(NULL));
   	int Card;
   	
   	
	
	cout << "Please Enter your Credit Card Number: " << endl;
	cin >> Card;
   
	this->CardNo = Card;
	
	Bank auth;
	auth.Authorize(CardNo);
   }
   else{
   	srand(time(NULL));
   	int Card;
   	string Email;
   	
   	Card = rand() % 10000 + 9999;
   	
   	cout << "An Account with this ID does not exist\n\n";
   	
   	cout << "Please Enter your email: " << endl;
	cin >> Email;
	
	this->CardNo = Card;
	this->CustomerEmail = Email;
	
	
	
   	CustomerAccount CA;
   	CA.CreateAccount(AccountID, CardNo, CustomerEmail);
   }
	
}









void Bank::Authorize(int CardNo){
	int x;
	
	this->x = CardNo;
	
	if(x == CardNo){
		
		cout << "Your Card was Validated!\n";
		
	
		if(x == CardNo){
		
			srand(time(NULL));
    		int BankAuth = 0;
    
    
    		BankAuth = rand() % 10000 + 9999;
    	
    		cout << "Thank you for shopping with us!\n\n";
    		cout << "Bank Authorization Number: " << BankAuth << endl;
    	
			int AccountID = 123;
			int OrderNo = 0;
		
			OrderNo = rand() % 100 + 99;
			cout << "Order Number: " << OrderNo << endl;
		
			DeliveryOrder Details;
			Details.CreateOrder(AccountID, OrderNo, BankAuth);
    	
		}
		else{
		
    		cout << "Your Card does not have enough funds, please try another card\n";
    		cout << "Going back to the Main Menu...\n\n"; 
    		main();
		}

	}
	else{
		int AccountID = 123;
		int CardNo = 0;
		
		cout << "***INCORRECT CARD NUMBER***\n\n";
		cout << "Please try again!\n";
		
		CustomerAccount CA;
		CA.ReadAccountInfo(AccountID, CardNo);
		
	}
		
}

void Email::EmailConfirmation(string CustomerEmail){
    //Prints Confirmation Email Message
	cout << "\nA confirmation Email has been sent to: " << CustomerEmail << endl;
}




void CustomerAccount::CreateAccount(int AccountID, int CardNo, string CustomerEmail){
    	//Prompts user to create a new Account ID #
	
	AccountID = 123;
	
	
	cout << "Now Creating New Account... \n\n";
	cout << "Your New Account ID is: 123\n";
	cout << "Your New Credit Card Number is: ";
	cout << CardNo << endl;
	cout << "\nConfirmation Emails will be sent to: ";
	cout << CustomerEmail << endl;
	
	cout << "Going back to the Main Menu...\n\n";
	
	CustomerAccount CA;
	CA.ReadAccountInfo(AccountID, CardNo);
	
}



void CustomerAccount::UpdateCardNo(int AccountID, int CardNo) {

}



void DeliveryOrder::CreateOrder(int AccountID, int Order, int AuthNo) {
	
	cout << "Thank you for shopping with us!\n";
	main();
}

void PurchaseOrderManager::CreateAccRequestOrder(int AccountID, int CardNo) {
	this->AccountID = AccountID;
	
	if(AccountID == 123){
		int item;
		int choice;
		int i = 0;
		int OrderNumber;
		string email;
		
		cout << "Please Enter your email: " << endl;
		cin >> email;
		
		
		while(i == 0){
			//Prompts customer to add an Item to their order
			cout << "Please Choose An Item To Order: \n";
			cout << "ITEM (1)\nITEM (2)\nITEM (3)\nITEM (4)\nITEM (5)\n\n";
			cout << "Enter item number: ";
			cin >> item;
		
			if(item > 0 && item <=5){
			
				//Allows customer to add another Item to their order if they choose to
				cout << "Would you like to add another item to your Request Order?\n";
				cout << "Select (1) for Yes and (2) for No: ";
				cin >> choice;
			
				if(choice == 2){
					i = 1;
					cout << "Order Successfully Complete!\n";
				
					OrderNumber = rand() % 10000 + 9999;
    				cout << "Your Order Number is: \n" << OrderNumber << endl;
    				Email E;
    				E.EmailConfirmation(email);
				}
			}
			else{
				cout << "Invalid Choice!\n";
			}
		}
	}	
	else{
		int CardNo;
   		string CustomerEmail;
   		cout << "An Account with this ID does not exist\n\n";
   		CustomerAccount CA;
   		CA.CreateAccount(AccountID, CardNo, CustomerEmail);	
	}
	main();
}

void PurchaseOrderManager::RequestOrderWithNewCardNo(int AccountID, int CardNo) {
	
	srand(time(NULL));
	
	CardNo = rand() % 1000 + 999;
	cout << "New Credit Card number is: " << CardNo << endl;
	
	Customer C;
	C.Request(AccountID, CardNo);
}














    
    
    
    
    
    
    
    
    