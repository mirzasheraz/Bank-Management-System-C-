#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<cstdlib>
using namespace std;
struct node{
	int no;             //acount number//
	int dd,mm,yyyy;      //dob//
	int bal;           //account balance//
	long long mobile;  //phone number//
	int pin[4];          //debit card pin//
	int r1[4],r2[4],r3[4],r4[4];  //varaibles for debit card number//
	long long id;    //cnic number//
	char name[50];      //account holder name//
	string city;      //city name//
	int status;    //atm service status { 1 = active } //
	node *pre;
	node *next;
} *start;

class Bank{
	public :
		void createacc();
		void deposit();
		void wdraw();
		void display();
		void delacc();
		void search();
		void transfer();
		void addstart();
		void addany();
		void travers();
		void update();
		void recover();
		
		Bank(){
			start = NULL;
		}
        void top(){
        	time_t now = time(0);     ////time display/////
            char* dt = ctime(&now);
        cout << "\n\t\t\t\t\t\t\t\t\t\t"<<dt;
        cout << "\t\t\t*******************************************************************************\n";
        cout << "\t\t\t                          Welcome to the National Bank\n";
        cout << "\t\t\t                           Account Management System\n";
        cout << "\t\t\t*******************************************************************************\n\n";
        }
		void intro() {
			cout<<"\n\n\n\t\t\t *************************************************************\n";
			cout<<"\t\t\t                      BANK MANAGEMENT SYSTEM\n";
			cout<<"\t\t\t *************************************************************\n\n";
			cout<<"\n\n\n\t\t\t\t   PROJECT BY : \n";
			cout<<"\t\t\t\t\t   SHERAZ ASLAM";
			cout<<"\n\n\n\t\t\t\t\t\t PRESS ENTER TO CONTINUE....";
			cin.get();
		}
};

///////////////////////////////////BANK'S   FUCTIONS   BODY///////////////////////////////////
void Bank::createacc(){
	int atmpin[4],ran1[4],ran2[4],ran3[4],ran4[4];
	char c;
	node *temp = new node();
	cout<<"\t\t\t  ACCOUNT NUMBER             : ";
    cin>>temp->no; 
    cout<<"\t\t\t  ACCOUNT HOLDER NAME        : ";
    cin.ignore();
    cin.getline(temp->name,50);
    cout<<"\t\t\t  DATE OF BITH [dd/mm/yyyy]  : ";
    cin>>temp->dd>>c>>temp->mm>>c>>temp->yyyy;
    cout<<"\t\t\t  13-DIGIT CNIC NUMBER       : ";
    cin>>temp->id;
    cout<<"\t\t\t  CITY                       : ";
    cin>>temp->city;
    cout<<"\t\t\t  PHONE NUMBER [+92]         : ";
    cin>>temp->mobile;
	cout<<"\t\t\t  OPENING BALANCE            : Rs ";
    cin>>temp->bal;
    cout<<"\t\t\t  YOUR DEBIT CARD NUMBERS IS : ";
    	srand((int)time(0));
	for (int i=0 ; i<4 ; i++) {
		 ran1[i] = (rand() % 9) + 1;
		 ran2[i] = (rand() % 9) + 1;                 /////for issue debit card number////
		 ran3[i] = (rand() % 9) + 1;
		 ran4[i] = (rand() % 9) + 1;
		 cout<<ran1[i]<<ran2[i]<<ran3[i]<<ran4[i]<<" ";
	}
	cout<<"\n\t\t\t  SET 4-DIGIT ATM CARD PIN   : ";
   for(int i=0;i<4;i++)
    {
        atmpin[i]=getch();
        printf("*");
        atmpin[i]=(atmpin[i]-49)+1;       //////for print staric instead of numbers/////
        temp->pin[i]=atmpin[i];
    }
    temp->status=1;
	for (int i=0 ; i<4 ; i++) {
		 temp->r1[i]=ran1[i];
		 temp->r2[i]=ran2[i];
		 temp->r3[i]=ran3[i];
		 temp->r4[i]=ran4[i];
	}
	temp->next = NULL;
	if(start == NULL){
		temp->pre = NULL;
		start = temp;
	}
	else
	{
		node *temp2 = new node();
		temp2 = start;
		while (temp2->next != NULL){
			temp2 = temp2->next;
	    }
		temp2->next = temp;
		temp->pre = temp2;
	}
	cout<<"\n\n\t\t\t  Bank Account Successfully Added !!!! \n";
}
void Bank::addstart(){
	int atmpin[4],ran1[4],ran2[4],ran3[4],ran4[4];
	char c;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	node *temp = new node();
	cout<<"\t\t\t  ACCOUNT NUMBER             : ";
    cin>>temp->no; 
    cout<<"\t\t\t  ACCOUNT HOLDER NAME        : ";
    cin.ignore();
    cin.getline(temp->name,50);
    cout<<"\t\t\t  DATE OF BITH [dd/mm/yyyy]  : ";
    cin>>temp->dd>>c>>temp->mm>>c>>temp->yyyy;
    cout<<"\t\t\t  13-DIGIT CNIC NUMBER       : ";
    cin>>temp->id;
    cout<<"\t\t\t  CITY                       : ";
    cin>>temp->city;
    cout<<"\t\t\t  PHONE NUMBER [+92]         : ";
    cin>>temp->mobile;
	cout<<"\t\t\t  OPENING BALANCE            : Rs ";
    cin>>temp->bal;
    cout<<"\t\t\t  YOUR DEBIT CARD NUMBERS IS : ";
    	srand((int)time(0));
	for (int i=0 ; i<4 ; i++) {
		 ran1[i] = (rand() % 9) + 1;
		 ran2[i] = (rand() % 9) + 1;
		 ran3[i] = (rand() % 9) + 1;
		 ran4[i] = (rand() % 9) + 1;
		 cout<<ran1[i]<<ran2[i]<<ran3[i]<<ran4[i]<<" ";
	}
	cout<<"\n\t\t\t  SET 4-DIGIT ATM CARD PIN   : ";
   for(int i=0;i<4;i++)
    {
        atmpin[i]=getch();
        printf("*");
        atmpin[i]=(atmpin[i]-49)+1;
        temp->pin[i]=atmpin[i];
    }
    temp->status=1;
	for (int i=0 ; i<4 ; i++) {
		 temp->r1[i]=ran1[i];
		 temp->r2[i]=ran2[i];
		 temp->r3[i]=ran3[i];
		 temp->r4[i]=ran4[i];
	}
	temp->next = start;
	start->pre = temp;
	start = temp;
	cout<<"\n\n\t\t\t  Bank Account Successfully Added !!!! \n";
}
void Bank::addany(){
	int atmpin[4],ran1[4],ran2[4],ran3[4],ran4[4],position;
	char c;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	node *temp = new node();
	node *temp2 = new node();
	cout<<"\t\t\t  ACCOUNT NUMBER             : ";
    cin>>temp->no; 
    cout<<"\t\t\t  ACCOUNT HOLDER NAME        : ";
    cin.ignore();
    cin.getline(temp->name,50);
    cout<<"\t\t\t  DATE OF BITH [dd/mm/yyyy]  : ";
    cin>>temp->dd>>c>>temp->mm>>c>>temp->yyyy;
    cout<<"\t\t\t  13-DIGIT CNIC NUMBER       : ";
    cin>>temp->id;
    cout<<"\t\t\t  CITY                       : ";
    cin>>temp->city;
    cout<<"\t\t\t  PHONE NUMBER [+92]         : ";
    cin>>temp->mobile;
	cout<<"\t\t\t  OPENING BALANCE            : Rs ";
    cin>>temp->bal;
    cout<<"\t\t\t  YOUR DEBIT CARD NUMBERS IS : ";
    	srand((int)time(0));
	for (int i=0 ; i<4 ; i++) {
		 ran1[i] = (rand() % 9) + 1;
		 ran2[i] = (rand() % 9) + 1;
		 ran3[i] = (rand() % 9) + 1;
		 ran4[i] = (rand() % 9) + 1;
		 cout<<ran1[i]<<ran2[i]<<ran3[i]<<ran4[i]<<" ";
	}
	cout<<"\n\t\t\t  SET 4-DIGIT ATM CARD PIN   : ";
   for(int i=0;i<4;i++)
    {
        atmpin[i]=getch();
        printf("*");
        atmpin[i]=(atmpin[i]-49)+1;
        temp->pin[i]=atmpin[i];
    }
    temp->status=1;
	for (int i=0 ; i<4 ; i++) {
		 temp->r1[i]=ran1[i];
		 temp->r2[i]=ran2[i];
		 temp->r3[i]=ran3[i];
		 temp->r4[i]=ran4[i];
	}
	cout<<"\t\t\t  ADD ACCOUNT AFTER POSITION ? ";
	cin>>position;
	temp2 = start;
	for (int i = 0; i<position-1; i++)
	{
		temp2 = temp2->next;
		if (temp2 == NULL)
		{
			cout<<"\a\t\t\t  THERE ARE LESS THAN ";
			cout<<position<<" ACCOUNTS\n"<<endl;
			return;
		}
	}
	if (temp2->next == NULL)
	{
		temp2->next = temp;
		temp->next = NULL;
		temp->pre = temp2;
	}
	else
	{
		temp->next = temp2->next;
		temp->next->pre = temp;
		temp2->next = temp;
		temp->pre = temp2;
	}
	cout <<"\n\n\t\t\t  Bank Account Successfully Added !!!! \n";
}
void Bank::deposit(){
    node *temp = new node;
	int acc,amount,check=0;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	cout<<"\n\t\t\t  ENTER ACCOUNT NUMBER : ";
	cin>>acc;
	temp = start;
	while (temp!= NULL){          /////loop to search depositor acc no/////
		if(temp->no == acc){
			cout<<"\n\t\t\t  ACCOUNT DETAILS\n";
			cout<<"\t\t\t  *******************************\n";
		    cout<<"\t\t\t  ACCOUNT HOLDER  : "<<temp->name<<"\n";
		    cout<<"\t\t\t  ACCOUNT NO      : "<<temp->no<<"\n";
		    cout<<"\t\t\t  DEBIT CARD NO   : ";
			    for (int i=0 ; i<4 ; i++) {
		            cout<<temp->r1[i]<<temp->r2[i]<<temp->r3[i]<<temp->r4[i]<<" ";
	            } cout<<"\n";
		    cout<<"\t\t\t  ACCOUNT BALANCE : Rs "<<temp->bal<<"\n";
		    cout<<"\t\t\t  *******************************\n\n";
			cout<<"\t\t\t  ENTER AMOUNT TO DEPOSIT : Rs ";
			cin>>amount;
			cout<<"\n\t\t\t  PREVIOUS BALANCE : Rs "<<temp->bal;
			temp->bal = temp->bal + amount;
			cout<<"\n\t\t\t  NEW      BALANCE : Rs "<<temp->bal;
			check=1;
			return;
		}
		temp = temp->next;
	}
	if(check == 0){
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
	}
}
void Bank::wdraw(){
    node *temp = new node;
	int acc,wamount,check=0;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	cout<<"\n\t\t\t  ENTER ACCOUNT NUMBER : ";
	cin>>acc;
	temp = start;
	while (temp!= NULL){             ////loop to search user acc no for withdrawl/////
		if(temp->no == acc){
			cout<<"\n\t\t\t  ACCOUNT DETAILS\n";
			cout<<"\t\t\t  *******************************\n";
		    cout<<"\t\t\t  ACCOUNT HOLDER  : "<<temp->name<<"\n";
		    cout<<"\t\t\t  ACCOUNT NO      : "<<temp->no<<"\n";
		    cout<<"\t\t\t  DEBIT CARD NO   : ";
			    for (int i=0 ; i<4 ; i++) {  //////for print staric instead of numbers/////
		            cout<<temp->r1[i]<<temp->r2[i]<<temp->r3[i]<<temp->r4[i]<<" ";
	            } cout<<"\n";
		    cout<<"\t\t\t  ACCOUNT BALANCE : Rs "<<temp->bal<<"\n";
		    cout<<"\t\t\t  *******************************\n\n";
		    while(check!=1){      ////loop to check amount till it is not correct/////
			cout<<"\t\t\t  ENTER AMOUNT TO WITHDRAW : Rs ";
			cin>>wamount;
			if(wamount <= temp->bal){
			cout<<"\n\t\t\t  PREVIOUS BALANCE : Rs "<<temp->bal;
			temp->bal = temp->bal - wamount;
			cout<<"\n\t\t\t  NEW      BALANCE : Rs "<<temp->bal;
			check=1;
		    } 
		    else{
		    	cout<<"\a\n\t\t\t  NOT SUFFICIENT AMOUNT IN YOUR ACCOUNT !!!! \n";
			}
		}
		}
		temp = temp->next;
	}
	if(check==0){
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
	}
}
void Bank::search(){
    node *temp = new node;
	int acc,check=0;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	cout<<"\n\t\t\t  ENTER ACCOUNT NUMBER : ";
	cin>>acc;
	temp = start;
	while (temp!= NULL){     
		if(temp->no == acc){
			cout<<"\n\t\t\t  ACCOUNT DETAILS\n";
			cout<<"\t\t\t  *******************************\n";
		    cout<<"\t\t\t  ACCOUNT HOLDER  : "<<temp->name<<"\n";
		    cout<<"\t\t\t  ACCOUNT NO      : "<<temp->no<<"\n";
		    cout<<"\t\t\t  DATE OF BIRTH   : "<<temp->dd<<"/"<<temp->mm<<"/"<<temp->yyyy<<"\n";
		    cout<<"\t\t\t  CITY            : "<<temp->city<<"\n";
		    cout<<"\t\t\t  CNIC    NO      : "<<temp->id<<"\n";
		    cout<<"\t\t\t  CONTACT NO      : (+92) "<<temp->mobile<<"\n";
		    cout<<"\t\t\t  DEBIT CARD NO   : ";
			    for (int i=0 ; i<4 ; i++) {
		            cout<<temp->r1[i]<<temp->r2[i]<<temp->r3[i]<<temp->r4[i]<<" ";
	            } cout<<"\n";
		    cout<<"\t\t\t  ACCOUNT BALANCE : Rs "<<temp->bal<<"\n";
		    cout<<"\t\t\t  *******************************\n\n";
		    check=1;
		    return;
		}
		temp = temp->next;
	}
	if(check==0){
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
	}	
}
void Bank::transfer(){
	node *temp = new node;
	int amount,reciever,depositor,check=0;
		if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	cout<<"\n\t\t\t  AMOUNT TRANSFER FROM [ACCOUNT NO] : ";
	cin>>depositor;
	cout<<"\t\t\t  AMOUNT TRANSFER TO   [ACCOUNT NO] : ";
	cin>>reciever;
	cout<<"\t\t\t  ENTER AMOUNT TO TRANSFER          : Rs ";
	cin>>amount;
	temp = start;
	while (temp!= NULL){      /////loop to search depositor//////
		if(temp->no == depositor){
			if(amount <= temp->bal){
				check = 1;
			}
			else{
				check = -1;
			}
		}
	   temp = temp->next;	
	}
	temp = start;
	while (temp!= NULL){        ////loop to search reciever/////
		if(temp->no == reciever){
			if(check == 1){
				temp->bal = temp->bal + amount;
				check = 2;
			}
		}
		temp = temp->next;
	}
	temp = start;   ////after adding amount to reciever,, cut amount from depositor's account////
	while (temp!= NULL){
		if(temp->no == depositor){
			if (check == 2){
				temp->bal = temp->bal - amount;
				cout<<"\n\t\t\t  TRANSACTION SUCCESSFULL !!!! \n";
				check = 3;
			}
		}
	   temp = temp->next;	
	}
	if(check != 3){
		cout<<"\a\n\t\t\t  TRANSACTION NOT SUCCESSFULL !!!! \n";
	}
	if(check == -1){
		cout<<"\n\t\t\t  DEPOSITOR HASN'T SUFFICIENT AMOUNT !!!! \n";
	}	
}
void Bank::travers(){
	struct node *p1, *p2;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	p1 = start;
	p2 = p1->next;
	p1->next = NULL;
	p1->pre = p2;
	while (p2 != NULL)
	{
		p2->pre = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->pre;
	}
	start = p1;
	cout << "\n\t\t\t  TRAVERS OPERATION SUCCESSFULL !!!! \n" << endl;
}
void Bank::delacc(){
	int accno;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	node *temp = new node();
	cout<<"\n\t\t\t  ENTER ACCOUNT NO TO CLOSE THAT ACCOUNT : ";
	cin>>accno;
	if (start->no == accno)
	{
		temp = start;
		start = start->next;
		start->pre = NULL;
		cout<<"\n\t\t\t  ACCOUNT "<<start->no<<" SUCCESSFULLY CLOSED !!!! \n";
		delete(temp);
		return;
	}
	else {
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
	}
	node *temp2 = new node();
	temp2 = start;
	while (temp2->next->next != NULL)
	{
		if (temp2->next->no == accno)
		{
			temp = temp2->next;
			temp2->next = temp->next;
			temp->next->pre = temp2;
			cout<<"\n\t\t\t  ACCOUNT "<<start->no<<" SUCCESSFULLY CLOSED !!!! \n";
			delete(temp);
			return;
		}
	else {
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
	}
		temp2 = temp2->next;
	}
	if (temp2->next->no == accno)
	{
		temp = temp2->next;
		delete(temp);
		temp2->next = NULL;
		cout<<"\n\t\t\t  ACCOUNT "<<start->no<<" SUCCESSFULLY CLOSED !!!! \n";
		return;
	}
	else {
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
	}
}
void Bank::update(){
    node *temp = new node;
	int acc,idno,ph,atmpin[4],check=0,ans;
	char in,c;
	string name;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	cout<<"\n\t\t\t  ENTER ACCOUNT NUMBER : ";
	cin>>acc;
	temp = start;
	while (temp!= NULL){
		if(temp->no == acc){
			in = 'y';
			while(in =='y' || in == 'Y'){
		    system("cls");
		    Bank::top();
		    cout<<"\t\t\t\t\t\t\t****UPDATE****\n\n";
			cout<<"\n\t\t\t  ACCOUNT DETAILS\n";
			cout<<"\t\t\t  *******************************\n";
		    cout<<"\t\t\t  1. ACCOUNT HOLDER  : "<<temp->name<<"\n";
		    cout<<"\t\t\t  2. ACCOUNT NO      : "<<temp->no<<"\n";
		    cout<<"\t\t\t  3. DATE OF BIRTH   : "<<temp->dd<<"/"<<temp->mm<<"/"<<temp->yyyy<<"\n";
		    cout<<"\t\t\t  4. CITY            : "<<temp->city<<"\n";
		    cout<<"\t\t\t  5. CNIC    NO      : "<<temp->id<<"\n";
		    cout<<"\t\t\t  6. CONTACT NO      : (+92) "<<temp->mobile<<"\n";
		    cout<<"\t\t\t  7. ACCOUNT BALANCE : Rs "<<temp->bal<<"\n";
		    cout<<"\t\t\t  8. DEBIT CARD NO   : ";
			    for (int i=0 ; i<4 ; i++) {
		            cout<<temp->r1[i]<<temp->r2[i]<<temp->r3[i]<<temp->r4[i]<<" ";
	            } cout<<"\n";
		    cout<<"\t\t\t  9. ATM CARD PIN    : ";
		       for(int j=0;j<4;j++) {
                    cout<<temp->pin[j];
                }
		    cout<<"\n\t\t\t  *******************************\n\n";
		    check=1;
		cout<<"\n\t\t\t  WHICH DETAIL DO YOU WANT TO UPDATE [1-9] ? : ";
		cin>>ans;
		switch(ans){
			case 1:
				cout<<"\n\t\t\t  ENTER NEW NAME : ";
                cin.ignore();
                cin.getline(temp->name,50);;
				cout<<"\n\t\t\t  UPDATED SUCCESFULLY !!!! \n";
				break;
			case 2:
				cout<<"\a\n\t\t\t  SORRY YOU CAN'T UPDATE THIS INFO !!!! \n ";
				break;
			case 3:
				cout<<"\n\t\t\t  ENTER DOB [dd/mm/yyyy] : ";
				cin>>temp->dd>>c>>temp->mm>>c>>temp->yyyy;
				break;
			case 4:
				cout<<"\n\t\t\t  ENTER CITY NAME : ";
				cin>>temp->city;
				cout<<"\n\t\t\t  UPDATED SUCCESFULLY !!!! \n";
			    break;
			case 5:
				cout<<"\n\t\t\t  ENTER NEW CNIC NUMBER : ";
				cin>>temp->id;
				cout<<"\n\t\t\t  UPDATED SUCCESFULLY !!!! \n";
				break;
			case 6:
				cout<<"\n\t\t\t  ENTER NEW CONTACT NUMBER [+92] : ";
				cin>>temp->mobile;
				cout<<"\n\t\t\t  UPDATED SUCCESFULLY !!!! \n";
				break;
			case 7:
				cout<<"\a\n\t\t\t  PLEASE DEPOSIT THE AMOUNT TO OFFICER !!!! \n ";
				break;
			case 8:
				cout<<"\a\n\t\t\t  SORRY YOU CAN'T UPDATE THIS INFO !!!! \n ";
				break;
			case 9:
				cout<<"\n\t\t\t  ENTER NEW PIN : ";
				   for(int i=0;i<4;i++) {
                        atmpin[i]=getch();
                        printf("*");
                        atmpin[i]=(atmpin[i]-49)+1;
                        temp->pin[i]=atmpin[i];
                    }
		                cout<<"\n\t\t\t  UPDATED SUCCESFULLY !!!! \n";
				break;
		    default : cout<<"\a\n\t\t\t WRONG INPUT !!!! \n";
		}
		cout<<"\n\t\t\t  DO YOU WANT TO UPDATE ANOTHER INFO (y/n) ? ";
		cin>>in;
	    }
    }
		temp = temp->next;
	}
	if(check==0){
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
	}
}
void Bank::recover(){
	int accno,atmpin[4],check=0;
	node *temp=new node;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
		return;
	}
	cout<<"\n\t\t\t  ENTER ACCOUNT NUMBER : "; cin>>accno;
	temp=start;
	while(temp!=NULL){
		if(temp->no==accno){
			check=1;
			cout<<"\n\t\t\t  ACCOUNT DETAILS\n";
			cout<<"\t\t\t  *******************************\n";
		    cout<<"\t\t\t  1. ACCOUNT HOLDER  : "<<temp->name<<"\n";
		    cout<<"\t\t\t  2. ACCOUNT NO      : "<<temp->no<<"\n";
		    cout<<"\t\t\t  3. ACCOUNT BALANCE : Rs "<<temp->bal<<"\n";
		    cout<<"\t\t\t  4. DEBIT CARD NO   : ";
			    for (int i=0 ; i<4 ; i++) {
		            cout<<temp->r1[i]<<temp->r2[i]<<temp->r3[i]<<temp->r4[i]<<" ";
	            } cout<<"\n";
	        cout<<"\t\t\t  5. ATM SERVICES    : ";
	        if(temp->status==1){
	        	cout<<"ACTIVE\n";
			}
	        if(temp->status==0){
	        	check=2;
	        	cout<<"TEMPORARY BLOCKED\n";
	        	cout<<"\n\t\t\t  ENTER NEW PIN TO UNBLOCK YOUR ATM SERVICES : ";
				   for(int i=0;i<4;i++) {
                        atmpin[i]=getch();
                        printf("*");
                        atmpin[i]=(atmpin[i]-49)+1;
                        temp->pin[i]=atmpin[i];
                    }
                    temp->status=1;
                    cout<<"\n\t\t\t YOUR ATM SERVICES SUCCESSFULLY UNBLOCKED...!!! ";
			} 
		} temp=temp->next;
	}
	if(check==0){
		cout<<"\a\n\t\t\t  No Account Found !!!! \n";
	}
	if(check!=2 && check==1){
		cout<<"\n\a\n\t\t\t   ATM SERVICES ARE ALREADY ACTIVE ...!!!! \n ";
	}
}
void Bank::display(){
	struct node *temp;
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!!";
		return;
	}
	temp = start;
	cout<<"\t\t\t  Bank Accounts Are \n\n";
	while (temp != NULL)
	{
		cout<<"\t\t\t  ***********************************\n";
		cout<<"\t\t\t  ACCOUNT HOLDER  : "<<temp->name<<"\n";
		cout<<"\t\t\t  ACCOUNT NO      : "<<temp->no<<"\n";
		cout<<"\t\t\t  CNIC    NO      : "<<temp->id<<"\n";
		cout<<"\t\t\t  CONTACT NO      : (+92) "<<temp->mobile<<"\n";
		cout<<"\t\t\t  DEBIT CARD NO   : ";
			for (int i=0 ; i<4 ; i++) {
		 cout<<temp->r1[i]<<temp->r2[i]<<temp->r3[i]<<temp->r4[i]<<" ";
	    } cout<<"\n";
		cout<<"\t\t\t  ACCOUNT BALANCE : Rs "<<temp->bal<<"\n";
		cout<<"\t\t\t  ***********************************\n\n";
		temp = temp->next;
	}
}

//////////////////////////////////////////ATM CLASS///////////////////////////////////////////////
class atm {
	private:
		int accno,clear;
	public:
	void top(){
		time_t now = time(0);
        char* dt = ctime(&now);
        cout << "\n\t\t\t\t\t\t\t\t\t\t"<<dt;
    cout<<"\n\t\t\t                            NATIONAL BANK ATM 24/7";
	cout<<"\n\t\t\t_____________________________________________________________________________________\n\n\n";
	}
void enter(){
    system("Cls");
    top();
	int check=0;
	int atmpin[4];
	node *temp = new node();
	if (start == NULL)
	{
		cout<<"\a\n\t\t\t  No Account Found !!!!";
		return;
	}
	cout<<"\n\n\t\t\t\t     ENTER ACCOUNT NUMBER   :     ";
	cin>>accno;
	temp = start;
	while(temp!=NULL){
		if(temp->no==accno){
			check=1;
			if(temp->status==1){
			check=2;
			int x=0;
			while(x!=3){
				temp=start;
					cout<<"\t\t\t\t     ENTER PIN              :     ";
					for(int i=0;i<4;i++) {
                        atmpin[i]=getch();
                        printf("*");
                        atmpin[i]=(atmpin[i]-49)+1;
                        atmpin[i]; 
	                } check=3;
				    while(temp!=NULL){
				    	if(temp->no==accno){
	                    if(temp->pin[0]==atmpin[0] && temp->pin[1]==atmpin[1] && 
		                    temp->pin[2]==atmpin[2] && temp->pin[3]==atmpin[3]  && temp->no==accno){
		                	    clear=1;
		                	    cout<<"\n\n\t\t\t  PRESS ENTER TO CONTINUE.... ";
	                            cin.ignore();
                                cin.get();
		                	    return;
				        }
				        if(check==3 && clear==0){
				    	    cout<<"\n\a\t\t\t\t INCORRECT PIN ...!!!\n";
					    }
					}temp=temp->next;
				    } x++;
				    if(x==3){
					    temp=start;
					    while(temp!=NULL){
					    	if(temp->no==accno){
					    		temp->status=0;
					    		cout<<"\n\a\t\t\t\t YOUR CARD HAS BEEN CAPTURED...!!!\n";
					    		cout<<"\t\t\t\t CONTACT TO YOUR BRANCH...!!!\n";
					    		return;
							}
						}
				}
			}
		}
	  }temp=temp->next;
	}
	if(check==1 && check!=2){
		cout<<"\n\a\t\t\t\t YOUR SERVICES ARE TEMPORARY BLOCKED...!!!\n";
		cout<<"\t\t\t\t CONTACT TO YOUR BRANCH...!!!\n";
	}
    if(check==0){
    	cout<<"\a\n\t\t\t  No Account Found !!!!";
	}

}
void cdepo(){
	node *temp=new node;
	int amount;
	temp=start;
	while(temp!=NULL){ 
		if(temp->no==accno){
			cout<<"\t\t\tACCOUNT HOLDER : "<<temp->name<<"\n";
		    cout<<"\t\t\t\t\t\t PLEASE ENTER AMOUNT : Rs "; cin>>amount;
	        temp=start;
			temp->bal+=amount;
			cout<<"\t\t\t\t\t\t AMOUNT DEPOSITED...!!!\n";
			cout<<"\t\t\t\t\t\t NEW BALANCE IS      : Rs "<<temp->bal;
			return;	
		}
		temp=temp->next;
	}
}
void enquiry(){
	node *temp=new node;
	temp=start;
	while(temp!=NULL){ 
		if(temp->no==accno){
			cout<<"\t\t\tACCOUNT HOLDER : "<<temp->name<<"\n";
			cout<<"\t\t\t\t\t\t  ACCOUNT NO                : "<<temp->no;
            cout<<"\n\t\t\t\t\t\t  YOUR AVAILABLE BALANCE IS : Rs "<<temp->bal;
			return;	
		}
		temp=temp->next;
	}
}
void cashwith(){
	node *temp=new node;
	temp=start;
	int amount;
	while(temp!=NULL){ 
		if(temp->no==accno){
			cout<<"\t\t\tACCOUNT HOLDER : "<<temp->name<<"\n";
            cout<<"\t\t\t\t\t\t  YOUR AVAILABLE BALANCE IS        : Rs "<<temp->bal;
            cout<<"\n\t\t\t\t\t\t  PLEASE ENTER AMOUNT TO WITHDRAWl : Rs "; cin>>amount;
            if(temp->bal>=amount){
            	temp->bal-=amount;
            	cout<<"\n\t\t\t\t\t\t  PLEASE RECIEVE YOUR CASH ....\n";
			}
			else{
				cout<<"\a\n\t\t\t\t\t\t  NOT SUFFICIENT AMOUNT ....\n";
			}
			return;	
		}
		temp=temp->next;
	}
}
void pinchange(){
	node *temp=new node;
	int atmpin1[4],atmpin2[4],check=0;
	temp=start;
	while(temp!=NULL){ 
		if(temp->no==accno){
			cout<<"\t\t\tACCOUNT HOLDER : "<<temp->name<<"\n";
			do{
            cout<<"\n\t\t\t\t\t\t  ENTER NEW PIN      : ";
			for(int i=0;i<4;i++) {
                atmpin1[i]=getch();
                printf("*");
                atmpin1[i]=(atmpin1[i]-49)+1;
                atmpin1[i]; 
	        }
            cout<<"\n\n\t\t\t\t\t\t  CONFIRM NEW PIN    : ";
			for(int j=0;j<4;j++) {
                atmpin2[j]=getch();
                printf("*");
                atmpin2[j]=(atmpin2[j]-49)+1;
                atmpin2[j]; 
	        }
	        if(atmpin1[0]==atmpin2[0] && atmpin1[1]==atmpin2[1] &&
			        atmpin1[2]==atmpin2[2] && atmpin1[3]==atmpin2[3]){
			        	cout<<"\n\t\t\t\t\t\t  PIN UPDATED SUCCESSFULLY....!!!!\n";
			        	temp->pin[0]=atmpin1[0];	  temp->pin[1]=atmpin1[1];
			            temp->pin[2]=atmpin1[2];	  temp->pin[3]=atmpin1[3];
			            check=1;
			        	return;
					}
			else{
				cout<<"\a\n\n\t\t\t\t\t\t  PIN NOT MATCHED....!!!! \n";
			}
		}while(check!=1); 
	  }
		temp=temp->next;
	}
}
void funds(){
	node *temp=new node();
	int acc,amnt,check=0;
	temp=start;
	while(temp!=NULL){
		if(temp->no==accno){
			check=1;
		}temp=temp->next;
	}
    cout<<"\n\n\t\t\t\t\t\t  ENTER RECIPIENT'S ACCOUNT NO : "; 
    cin>>acc;
	temp=start;
	while(temp!=NULL){
		if(temp->no==acc){
			check=2;
		}temp=temp->next;
	}
	if(check==2){
		cout<<"\n\n\t\t\t\t\t\t  ENTER AMOUNT TO TRANSFER : ";
	    cin>>amnt;
	} 
	else{
		cout<<"\a\n\n\t\t\t\t\t\t  RECIPIENT NOT FOUND....!!!! \n";
		return;
	}
	temp=start;
	while(temp!=NULL){
		if(temp->no==accno){
			if(temp->bal>=amnt){
				temp->bal=temp->bal-amnt;
				check=3;
			}
		}temp=temp->next;
	}
	if(check==2 && check !=3){
		cout<<"\a\n\t\t\t\t\t\t  NOT SUFFICIENT AMOUNT ....\n";
		return;
	}
	temp=start;
	while(temp!=NULL){
		if(temp->no==acc){
			temp->bal=temp->bal+amnt;
			check=4;
		}temp=temp->next;
	}
	if(check==4){
		cout<<"\n\n\t\t\t\t\t\t  TRANSACTION SUCCESSFULL....!!!! \n";
	}
}
void fastcash(){
	node *temp=new node();
	int op,amount,check=0;
    	cout<<"\t\t\t  1.  500           \t\t\t\t\t\t2. 1000\n\n\n\n";
    	cout<<"\t\t\t  3.  4000          \t\t\t\t\t\t4. 5000\n\n\n\n";
    	cout<<"\t\t\t  5.  10000    \t\t\t\t\t\t     6. OTHER AMOUNT\n\n";
    	cout<<"\t\t\t ->"; cin>>op;
	temp=start;
	while(temp!=NULL){
		if(temp->no==accno){
			switch(op){
				case 1:
					if(temp->bal>=500){
					    temp->bal=temp->bal-500;
					    check=1;
				    }
					break;
				case 2:
					if(temp->bal>=1000){
					    temp->bal=temp->bal-1000;
					    check=1;
				    }
					break;
				case 3:
					if(temp->bal>=4000){
					    temp->bal=temp->bal-4000;
					    check=1;
				    }
					break;
				case 4:
					if(temp->bal>=5000){
					    temp->bal=temp->bal-5000;
					    check=1;
				    }
					break;
				case 5:
					if(temp->bal>=10000){
					    temp->bal=temp->bal-10000;
					    check=1;
				    }
					break;
				case 6:
					cout<<"\n\t\t\t\t\t\t  PLEASE ENTER AMOUNT : Rs "; cin>>amount;
					if(temp->bal>=amount){
					    temp->bal=temp->bal-amount;
					    check=1;
				    }
			}
		}temp=temp->next;
	}
	if(check==1){
		cout<<"\n\t\t\t\t\t\t  PLEASE RECIEVE YOUR CASH ....\n";
	}
	else{
		cout<<"\a\n\t\t\t\t\t\t  NOT SUFFICIENT AMOUNT ....\n";
	}
}
void function(){
	int c;
	node *temp=new node();
	    enter();
    	if(clear==1){
    		clear=0;
    	do{
    	system("Cls");
    	top();
    	cout<<"\t\t\t\t\t\t SELECT YOUR TRANSACTION\n\n";
    	cout<<"\t\t\t  1.  CASH DEPOSIT  \t\t\t\t\t\t2. FAST CASH\n\n";
    	cout<<"\t\t\t  3.  FUNDS TRANSFER\t\t\t\t\t\t4. CASH WITHDRAWL\n\n";
    	cout<<"\t\t\t  5.  PIN CHANGE    \t\t\t\t\t\t6. BALANCE ENQUIRY\n\n";
    	cout<<"\n\t\t\t_____________________________________________________________________________________\n\n";
    	cout<<"\t\t\t\t\t"; cin>>c;
    	switch(c){
    		case 1:
    			system("Cls");
    	        top();
    			atm::cdepo();
    			break;
    		case 2:
    			system("Cls");
    	        top();
    	        atm::fastcash();
    			break;
    		case 3:
    			system("Cls");
    			top();
    			atm::funds();
    			break;
    		case 4:
    			system("Cls");
    	        top();
    			atm::cashwith();
    			break;
    		case 5:
    			system("Cls");
    	        top();
    			atm::pinchange();
    			break;
    		case 6:
    			system("Cls");
    	        top();
    			atm::enquiry();
    			break;
    		case 7:
    			break;
    		default : cout<<"\a\n\t\t\t WRONG INPUT !!!! \n";
		}
	cout<<"\n\n\t\t\t  PRESS ENTER TO CONTINUE.... ";
	cin.ignore();
    cin.get();
    }while(c!=7);
  }
}
};

/////////////////////////////////////////MAIN  FUCTION////////////////////////////////////////////

int main(){
    int c1,c2;
	char ans;
	Bank b;
	system("color 07");
	b.intro();
	atm a;
	system("Cls");
	b.top();
	do{    	system("Cls");
	        system("color 07");
            b.top();
			cout<<"\t\t\t\t  1. BANK SERVICE              2. ATM SERVICE  \n\n";
	        cout<<"\t\t\t\t  CHOICE > "; cin>>c1;
	switch(c1){
	case 1:
        do{
	system("Cls");
    b.top();
    cout<<"\t\t\t            ****ACCOUNT REGISTRATION AND OTHER SERVICES****\n\n";
	cout<<"\t\t\t  [1]  CREATE AT-END/NEW ACCOUNT          [2]  CREATE ACCOUNT AT-FIRST \n";
	cout<<"\t\t\t  [3]  CREATE ACCOUNT AT-ANY POSITION     [4]  CLOSE AN ACCOUNT \n"; 
	cout<<"\t\t\t  [5]  DEPOSIT                            [6]  WITHDRAW \n";
	cout<<"\t\t\t  [7]  SEARCH                             [8]  TRANSFER\n";
	cout<<"\t\t\t  [9]  TRAVERS                            [10] DISPLAY \n";
	cout<<"\t\t\t  [11] UPDATE                             [12] RECOVER ATM SERVICE\n";
	cout<<"\t\t\t  [13] EXIT\n";
	cout<<"\n"; 
	cout<<"\t\t\t  MAKE DECISION  1-13 ";
	cin>>c2;
	switch(c2)
	{
		
		case 1:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t********APPLICATION FORM********\n\n";
			b.createacc();
			break;
		case 2:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t   ****CREATE AN ACCOUNT****\n\n";
			b.addstart();
			break;
		case 3:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t   ****CREATE AN ACCOUNT****\n\n";
			b.addany();
			break;
		case 4:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t   ****DELETE AN ACCOUNT****\n\n";
			b.delacc();
			break;
		case 5:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t\t****DEPOSIT****\n\n";
			b.deposit();
			break;
	    case 6:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t\t****WITHDRAW****\n\n";
			b.wdraw();
			break;	
		case 7:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t   ****SEARCH AN ACCOUNT****\n\n";
			b.search();
			break;
		case 8:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t\t****MONEY TRANSFER****\n\n";
			b.transfer();	
			break;
		case 9:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t\t****TRAVERS****\n\n";
			b.travers();
			break;
		case 10:
			system("Cls");
			b.top();
			cout<<"\t\t\t\t\t\t\t****DISPLAY****\n\n";
			b.display();	
			break;
		case 11:
			system("Cls");
			b.top();
			b.update();
			break;
		case 12:
			system("Cls");
			b.top();
			b.recover();
			break;
		case 13:
			break;
		default : cout<<"\a\n\t\t\t WRONG INPUT !!!! \n";
	}
	cout<<"\n\n\t\t\t  PRESS ENTER TO CONTINUE.... ";
	cin.ignore();
    cin.get();
    }while(c2!=13);
    break;
    
    case 2:
    	system("color 17");
    	a.function();
	cout<<"\n\n\t\t\t  PRESS ENTER TO CONTINUE.... ";
	cin.ignore();
    cin.get();
        break;
}
}while(c1!=3);
system("Cls");
cout<<"\n\n\n\n\n\n\t\t\t\t\t  THANK YOU FOR CHOOSING NATIONAL BANK...... \n\n\n\n\n\n ";
}
