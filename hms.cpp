#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>

using namespace std;

class hotel{
	int roomno;
	char name[30];
	char addr[50];
	char phone[10];
	
	public:
		void main_menu();
		void add();
		void disp();
		void rooms();
		void edit();
		int check(int);
		void modify(int);
		void del(int);
		void bill(int);
};

void hotel::main_menu(){
	int choice;
	while(choice !=5){
		system("cls");
		cout<<"\n\n\t\t\t\t\t********************";
		cout<<"\n\n\t\t\t\t\t     WELCOME TO     ";
		cout<<"\n\n\t\t\t\t\t  HOTEL MANAGEMENT  ";
		cout<<"\n\n\t\t\t\t\t       SYSTEM       ";
		cout<<"\n\n\t\t\t\t\t     *MAIN MENU*    ";
		cout<<"\n\n\t\t\t\t\t     BY HRITHIK     ";
		cout<<"\n\n\t\t\t\t\t********************";
		cout<<endl;
		cout<<"\n\n\t\t\t\t\t 1. Reserve a Room";
		cout<<"\n\n\t\t\t\t\t 2. Customer Records";
		cout<<"\n\n\t\t\t\t\t 3. Rooms Alloted Record";
		cout<<"\n\n\t\t\t\t\t 4. Edit A Record";
		cout<<"\n\n\t\t\t\t\t 5. EXIT";
		cout<<"\n\n\t\t\t\t\t Enter your choice - ";
		cin>>choice;
		
		switch(choice){
			
			case 1: add();
			break;
			case 2: disp();
			break;
			case 3: rooms();
			break;
			case 4: edit();
			break;
			case 5: break;
			
			default:{
				cout<<"\n\n\t\t\t\t\t Wrong Choice !!!!!";
				cout<<"\n\n\t\t\t\t\t Press any key to continue !!!!";
				getch();
			}
		}
		
	}
}

void hotel::add(){
	system("cls");
	int r;
	int flag;
	ofstream fout("Record.dat",ios::app);
	
	cout<<"\n Enter Customer Details";
    cout<<"\n ----------------------";
    cout<<"\n\n Room no: ";
    cout<<"\n Total no. of Rooms - 50";
    cout<<"\n Ordinary Rooms from 1 - 30";
    cout<<"\n Luxuary Rooms from 31 - 45";
    cout<<"\n Royal Rooms from 46 - 50";
    cout <<"\n Enter The Room no. you want to stay in :- "<<endl;
    cin>>r; 	
	
	flag = check(r);
	if(flag)
	cout<<"\n Room is already booked";
	
	else{
		roomno=r;
		cout<<" Name: ";
		cin>>name;
		cout<<" Address: ";
		cin>>addr;
		cout<<" Phone No: ";
		cin>>phone; 
		
		fout.write((char*)this,sizeof(hotel));
		cout<<"\n Room is booked..!!!";
	}
	cout<<"\n Press any key to continue !!!!";
	
	getch();
	fout.close();
}

void hotel::disp(){
	system("cls");
	ifstream fin("Record.dat",ios::in);
	int r,flag;
	
	cout<<"\n Enter Room no. for a particular customer's details :- "<<endl;
	cin>>r;
	
	while(!fin.eof()){
		fin.read((char*)this,sizeof(hotel));
		if(roomno == r){
			system("cls");
			cout<<"\n Customer Details";
			cout<<"\n -----------------";
			cout<<"\n\n Room no. : "<<roomno;
			cout<<"\n Name : "<<name;
			cout<<"\n Address : "<<addr;
			cout<<"\n Phone no. : "<<phone;
			flag =1;
			break;
		}
	}
	if(flag ==0)
	cout<<"\n Room number not found or vacant !!!!";
	cout<<"\n\n Press any key to continue.....!!";
	getch();
	fin.close();
}

void hotel::rooms(){
	
	system("cls");
	ifstream fin("Record.dat",ios::in);
	cout<<"\n\t\t\t    List of Rooms Alloted";
	cout<<"\n\t\t\t    ---------------------";
	cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";
	
	while(!fin.eof()){
		fin.read((char*)this,sizeof(hotel));
		cout<<"\n\n "<<roomno<<"\t\t"<<name;
		cout<<"\t\t"<<addr<<"\t\t"<<phone;
	}
	
	cout<<"\n\n\n\t\t\tPress any key to continue.....!!";
	getch();
	fin.close();

	
}

void hotel::edit(){
	system("cls");
	int choice,r;
	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1.Modify Customer Record";
	cout<<"\n 2.Delete Customer Record";
	cout<<"\n 3. Bill Of Customer";
	cout<<"\n Enter your choice: ";
	cin>>choice;
	system("cls");
	cout<<"\n Enter Room Number : ";
	cin>>r;
	
	switch(choice){
		case 1: modify(r);
		break;
		
		case 2: del(r);
		break;
		
		case 3: bill(r);
		break;
		
		default: cout<<"\n Wrong choice.....!!";
		
	}
	cout<<"\n Press any key to continue....!!!";

	getch();
	
}

int hotel::check(int r){
	int flag = 0;
	ifstream fin("Record.dat",ios::in);
	while(!fin.eof()){
		fin.read((char*)this,sizeof(hotel));
		if(roomno == r){
			flag =1;
			break;
		}
	}
	fin.close();
	return(flag);
	
}

void hotel::modify(int r){
	
	long pos,flag=0;

	fstream file("Record.dat",ios::in|ios::out|ios::binary);

	while(!file.eof()){

		pos=file.tellg();
		file.read((char*)this,sizeof(hotel));

		if(roomno==r){

			cout<<"\n Enter New Details";
			cout<<"\n -----------------";
			cout<<"\n Name: ";
			cin>>name;
			cout<<" Address: ";
			cin>>addr;
			cout<<" Phone no: ";
			cin>>phone;
			file.seekg(pos);
			file.write((char*)this,sizeof(hotel));
			cout<<"\n Record is modified....!!";
			flag=1;
	break;
}

}

if(flag==0)
cout<<"\n Sorry Room no. not found or vacant...!!";
file.close();

}

void hotel::del(int r){
	int flag=0;
char ch;
ifstream fin("Record.dat",ios::in);
ofstream fout("temp.dat",ios::out);

while(!fin.eof())
{

fin.read((char*)this,sizeof(hotel));
if(roomno==r)

{

cout<<"\n Name: "<<name;
cout<<"\n Address: "<<addr;
cout<<"\n Pone No: "<<phone;
cout<<"\n\n Do you want to delete this record(y/n): ";
cin>>ch;

if(ch=='n')
fout.write((char*)this,sizeof(hotel));
flag=1;

}

else
fout.write((char*)this,sizeof(hotel));

}

fin.close();
fout.close();

if(flag==0)
cout<<"\n Sorry room no. not found or vacant...!!";

else
{

remove("Record.dat");
rename("temp.dat","Record.dat");

}
}

void hotel::bill(int r)
{

hotel h1;
ifstream f1;
 f1.open("record.dat",ios::in|ios::binary);

if(!f1)
 cout<<"cannot open";

 else
 {

  f1.read((char*)&h1,sizeof (hotel));
  while(f1)

  {

  f1.read((char*)&h1,sizeof(hotel));

  }

  if (h1.roomno == r)
  {

  if(h1.roomno>=1&&h1.roomno<=30)
  cout<<"your bill = 2000";

  else if (h1.roomno>=35&&h1.roomno<=45)
  cout<<"your bill = 5000" ;

  else
  cout<<"your bill = 7000";

  }

  else
  { cout<<"room no. not found";}

  }

  f1.close();
  getch();

}

int main(){
	hotel h;

  system("cls");

//cout<<"\n\t\t\t****************************";
//cout<<"\n\t\t\t* HOTEL MANAGEMENT PROJECT *";
//cout<<"\n\t\t\t****************************";
//cout<<"\n\n\t\tDeveloped By:";
//cout<<"\t Hrithik Agarwal";
//cout<<"\n\n\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";
//
//getch();

h.main_menu();
	
	return 0;
}
