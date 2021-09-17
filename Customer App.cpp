#include<iostream>
#include<string>
#include<fstream>
using namespace std;
void slip(float BILL)
{
	system("color 0e");
	cout<<"\a";
	float paid;
	string c_name;
	string id_card,mob_no;
	cout<<"			Enter Your Name (Use '_' in Multiple Words): ";
	cin>>c_name;
	cout<<"			-------------------"<<endl;
	cout<<"			Enter Your ID Card: ";
	cin>>id_card;
	cout<<"			-------------------"<<endl;
	cout<<"			Enter Your Mobile Number: ";
	cin>>mob_no;
	cout<<"			-------------------"<<endl;
	cout<<"			Pay Bill: ";
	cin>>paid;
	cout<<"			-------------------"<<endl;
	float remain=paid-BILL;
	ofstream inslip;
	inslip.open("slip.txt");
	inslip<<"Name:			"<<c_name<<endl;
	inslip<<"ID Card:		"<<id_card<<endl;
	inslip<<"Mobile No:		"<<mob_no<<endl;
	inslip<<"Total Bill:		Rs."<<BILL<<endl;
	inslip<<"Costumer Paid:		Rs."<<paid<<endl;
	inslip<<"Remaining Amount:	Rs."<<remain<<endl;
	cout<<"			***************************"<<endl;
	cout<<"			*Remaining Amount: Rs."<<remain<<endl;
	cout<<"			*Thanks For Shopping..."<<endl;
	cout<<"			***************************"<<endl;
	inslip.close();
}
main()
{
	start:
	int count;
	ifstream outamu;
	outamu.open("amu.txt");
	outamu>>count;
	count++;
	outamu.close();
	system("color 01");
	ofstream indata;
	ifstream outdata;
	string item[count];
	string head1,head2;
	float price[count];
	cout<<"					---------------------"<<endl;
	cout<<"					Happy Group Resturant"<<endl;
	cout<<"					     Today's Menu"<<endl;
	cout<<"					---------------------"<<endl;
	outdata.open("menu.txt");
	outdata>>head1>>head2;
	for(int i=1;i<count;i++)
	{
		outdata>>item[i]>>price[i];
	}
	cout<<"			-----------------------------------------------------"<<endl;
	cout<<"			Dishes						Price"<<endl;
	cout<<"			-----------------------------------------------------"<<endl;
	for(int i=1;i<count;i++)
	{
		cout<<"			"<<i<<")- "<<item[i];
		cout<<"					"<<"Rs."<<price[i]<<endl;
		cout<<"			------------------------------------------------------"<<endl;
	}
	cout<<endl;
	int selection,quantity[count];
	float bill;
	for(int i=1;i<count;i++)
	{
		quantity[i]=0;
	}
	cout<<"		      **********************************************************"<<endl;
	cout<<"		      Enter The Number Of Dish You Want (Press '0' To Get Bill): ";
	cin>>selection;
	while(selection!=0)
	{
		cout<<"			---------------"<<endl;
		cout<<"			Your Selection: "<<item[selection]<<endl;
		cout<<"			Enter Quantity: ";
		cin>>quantity[selection];
		bill+=price[selection]*quantity[selection];
	cout<<"		      **********************************************************"<<endl;
	cout<<"		      Enter The Number Of Dish You Want (Press '0' To Get Bill): ";
	cin>>selection;
	}
	cout<<endl<<endl;
	cout<<"			   	**********************************"<<endl;
	cout<<"			   		Total Bill: Rs."<<bill<<endl;
	cout<<"			   	**********************************"<<endl;
	slip(bill);
	system("pause");
	system("cls");
	goto start;
}
