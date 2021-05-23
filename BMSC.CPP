//***************************************************************
//                             HEADER FILES
//****************************************************************
#include<String.h>
#include<stdlib.h>
#include<dos.h>
#include<fstream.h>
#include<ctype.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>


class account
{
	int acno;
	char name[50];
	int deposit;
	char phone[12];
public:
	char choice[10];
	char type[20];
	void createacc();	//Accepts data
	void showacc(); 	//Displays data
	void mod();             //Modifies pre-existing details
	int genacno();
	void dep(int);	        //Accepts amount
	void wdraw(int);	//Withdraws from balance amount
	void database();	//Shows data in tabular format
	int retacno();	        //Return account number
	int retdeposit();	//function to return balance amount
	account()
	{
	 strcpy(choice,"ijhkj");
	}
}ac;

void account::createacc()
{

	cout<<"\n\nEnter The Name of The account Holder : ";
	gets(name);
	cout<<"\nEnter Type of The account (CURRENT/SAVINGS) : ";
	gets(type);
	cout<<"\nEnter The Initial amount(>=Rs.1000 ) : ";
	cin>>deposit;
	while(deposit<1000)
	{
	  cout<<"Please deposit at least Rs. 1000";
	  cout<<" Re-enter deposit: ";
	  cin>>deposit;
	}
	cout<<"\nEnter your phone number:";
	gets(phone);
	cout<<"\nEnter an account number:(Suggested number:"<<genacno();;
	cout<<"):";
	cin>>acno;

	cout<<"Account successfully created!";
}

void account::showacc()
{
	cout<<"\nAccount No. : "<<acno;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
	cout<<"\nPhone number:"<<phone;
}


void account::mod()
{
  while(strcmpi(choice,"NOC")!=0)
  {
   cout<<"Enter the parameter (Enter NOC if no more changes):(Name/Phone No./Address)";
   gets(choice);

    if(strcmpi(choice,"phone number")==0)
      {
	cin>>phone;
      }

    if(strcmpi(choice,"Name")==0)
      {
	gets(name);
      }

   }
}


void account::dep(int x)
{
	deposit=deposit+x;
}

void account::wdraw(int x)
{
	deposit=deposit-x;
}

void account::database()
{
 cout<<"    "<<acno<<"     "<<name<<"         "<<type<<"      "<<deposit<<"           "<<phone<<endl;
}

int account::genacno()
{
  acno=1000+random(100)+random(200)+random(1000)+random(23)+7;
  return acno;
}

int account::retacno()
{
  return acno;
}

int account::retdeposit()
{
	return deposit;
}


//***************************************************************
//    	                Function declaration
//****************************************************************
void writeacc();        	//Writes record in binary file
void dispacc(int);      	//Displays account details given by user
void mod(int);           	//Modify records in file
void deleteacc(int);	        //Deletes record from file
void dispalldata();		//Display all account details
void transact(int, int);        // For transactions
void intro();
void transition(int,int);
//***************************************************************


void transition(int j,int l)
{
      if(l==9)
	 {
		for(int i=1;i<=80;i++)
		 {
		   delay(20);gotoxy(i,j);cout<<"|";
		 }

		for(i=1;i<=80;i++)
		  {
		   delay(7);gotoxy(i,j);cout<<" ";
		  }

	 }
       else if(l==2)
       {
	delay(15);gotoxy(17,j);cout<<"   L O A D I N G  U S E R  I N T E R F A C E";

	for(int i=1;i<=80;i++)
		 {
		   delay(20);gotoxy(i,j+3);cout<<">";
		 }
		   for(i=1;i<=80;i++)
		{
		   delay(7);gotoxy(i,j+3);cout<<" ";
		}
      }
       else if(l==1||l==0)
       {

	char A[2][30]={" D A T A"," F I L E S"};

	delay(15);gotoxy(25,j);cout<<"  L O A D I N G "<<A[l];

	for(int i=1;i<=80;i++)
		 {
		   delay(20);gotoxy(i,j+3);cout<<">";
		 }
	for(i=1;i<=80;i++)
		{
		   delay(7);gotoxy(i,j+3);cout<<" ";
		}
	}

}




//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
	char ch;
	int num;
	clrscr();
	intro();
	do
	{       clrscr();
		cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
		cout<<"\n\t\t\t\tMAIN MENU";
		cout<<"\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
		cout<<"\n\n\t\t\t   1) NEW ACCOUNT";
		cout<<"\n\n\t\t\t   2) DEPOSIT AMOUNT";
		cout<<"\n\n\t\t\t   3) WITHDRAW AMOUNT";
		cout<<"\n\n\t\t\t   4) USER PROFILE";
		cout<<"\n\n\t\t\t   5) USER DATABASE";
		cout<<"\n\n\t\t\t   6) CLOSE ACCOUNT";
		cout<<"\n\n\t\t\t   7) MODIFY ACCOUNT";
		cout<<"\n\n\t\t\t   8) EXIT";
		cout<<"\n\n\t  ENTER YOUR CHOICE: ";
		cin>>ch;
		clrscr();
		switch(ch)
		{
		case '1':
			transition(20,9);
			clrscr();
			writeacc();
			break;
		case '2':
			cout<<"\n\n\tEnter your account number:";
			cin>>num;
			transition(20,9);
			clrscr();
			transact(num,1);

			break;
		case '3':
			cout<<"\n\n\tEnter the account number:";
			cin>>num;
			transition(20,9);
			clrscr();
			transact(num,2);
			break;
		case '4':
			transition(20,9);
			clrscr();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			dispacc(num);
			break;
		case '5':
			transition(20,9);
			clrscr();
			dispalldata();
			break;
		case '6':
			transition(20,9);
			clrscr();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			deleteacc(num);
			break;
		 case '7':
			transition(20,9);
			clrscr();
			cout<<"\n\n\tEnter The account No. : "; cin>>num;
			mod(num);
			break;
		 case '8':
			 cout<<"\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
			 cout<<"\n\n\t\t\t         CREDITS:";
			 cout<<"\n\t\t\t         ~~~~~~~";
			 cout<<"\n\n\t                        Project By:  \n\t";
			 cout<<"\n\n\t                      \tAkash: 4";
			 cout<<"\n\n\t                      \tIshaan: 16";
			 cout<<"\n\n\t                      \tKaustubh: 21";
			 cout<<"\n\n\n\n\n\n\n\n\n\n\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
			break;
		 default :cout<<"\a";
		}
		getch();
	}while(ch!='8');
	return 0;
}


//***************************************************************
//    	To write in file
//****************************************************************

void writeacc()
{

	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.createacc();
	outFile.write((char *) &ac, sizeof(account));
	outFile.close();
}

//***************************************************************
//    	To read a specific record from file
//****************************************************************

void dispacc(int n)
{

	int flag=0;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened !! Press any key to return to menu";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()==n)
		{
			ac.showacc();
			flag=1;
		}
	}
	inFile.close();
	if(flag==0)
		cout<<"\n\nAccount number does not exist!";
}


//***************************************************************
//    	To modify record of file
//****************************************************************

void mod(int n)
{
	int found=0;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be opened !! Press any key to return to menu.";
		return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.showacc();
			cout<<"\n\nEnter the new details of account"<<endl;
			ac.mod();
			int pos=(-1)*sizeof(account);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated!!";
			found=1;
		}
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found! ";
}



//***************************************************************
//    	To delete record from file
//****************************************************************


void deleteacc(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write((char *) &ac, sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
}

//***************************************************************
//    	To display a list of all accounts
//****************************************************************

void dispalldata()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";

	}
	clrscr();
	cout<<"\n\n\t\t\t  ACCOUNT HOLDERS' LIST\n\n";
	cout<<"  =========================================================================";
	cout<<"        A/c no.   Name          Type       Balance        Phone Number\n";
	cout<<"  =========================================================================\n";
	while(inFile.read((char *) &ac, sizeof(account)))
	{
		ac.database();
	}
	inFile.close();
}

//***************************************************************
//    	To deposit and withdraw amounts
//****************************************************************

void transact(int n, int option)
{
	int amt;
	int found=0;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(File.read((char *) &ac, sizeof(account)) && found==0)
	{
		if(ac.retacno()==n)
		{
			ac.showacc();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int deposit=ac.retdeposit()-amt;
				if((deposit<1000 && strcmpi("SAVINGS",ac.type)==0) || (deposit<1000 && strcmpi("CURRENT",ac.type)==0))
					cout<<"Insufficient balance";
				else
					ac.wdraw(amt);
			}
			int pos=(-1)* sizeof(ac);
			File.seekp(pos,ios::cur);
			File.write((char *) &ac, sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=1;
	       }
	}
	File.close();
	if(found==0)
		cout<<"\n\n Record Not Found ";
}


//***************************************************************
//                       	INTRO
//****************************************************************


void intro()
{
	transition(7,2);
	transition(12,1);
	transition(17,0);
	clrscr();
	cout<<"\n\n\n\n\n\nZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
	cout<<"\n\n\t\t\t       Welcome to AIK Bank! \n\t\t\t Press any key to continue......";
	cout<<"\n\nZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";

	getch();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************