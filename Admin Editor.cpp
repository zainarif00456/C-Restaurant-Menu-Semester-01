#include<iostream>
#include<string>
#include<fstream>
using namespace std;
string Password()
{
	system("color 0a");
	string Password,N_password,C_password,P_password;
	ifstream outpass;
	ofstream inpass;
	outpass.open("password.txt");
	outpass>>P_password;
	cout<<endl<<endl;
	cout<<"					-------------------------"<<endl;
	cout<<"					Enter Previous Password: ";
	cin>>Password;
	while(Password!=P_password)
	{
		system("color 40");
		cout<<"				-----------------------------------"<<endl;
		cout<<"				Wrong Password. Please Try Again..."<<endl;
		cout<<"				Enter Password: ";
		cin>>Password;
	}
	system("color 0a");
	cout<<"					-------------------------"<<endl;
	cout<<"					Enter New Password: ";
	cin>>N_password;
	cout<<"					Confirm Password: ";
	cin>>C_password;
	cout<<endl<<endl;
	while(N_password!=C_password)
	{
	system("color 04");
	cout<<"					_____________________________________________"<<endl;
	cout<<"					Passwords are not same. Please Enter Again..."<<endl;
	cout<<"					Enter New Password: ";
	cin>>N_password;
	cout<<"					Confirm Password: ";
	cin>>C_password;
	}
	inpass.open("password.txt");
	inpass<<N_password;
	cout<<endl;
	cout<<"					*******************************"<<endl;
	cout<<"					*Password Updated Successfully*"<<endl;
	cout<<"					*******************************"<<endl;
	inpass.close();
	return N_password;
}
main()
{
	system("color 09");
	ifstream outdata;
	ofstream indata;
	string password,p_word;
	ifstream outpass;
	outpass.open("password.txt");
	outpass>>p_word;
	cout<<"					--------------"<<endl;
	cout<<"					Resturant Menu"<<endl;
	cout<<"					--------------"<<endl;
	cout<<"Reset Password: Press '#'"<<endl;
	cout<<"--------------------------"<<endl;
	cout<<"Enter Admin Password: ";
	cin>>password;
	if(password=="#")
	{
		p_word=Password();
		system("color 09");
		cout<<"----------------------"<<endl;
		cout<<"Enter Admin Password: ";
		cin>>password;
	}
	outpass>>p_word;
	while(password!=p_word)
	{
		system("color 40");
		cout<<"-----------------------------------"<<endl;
		cout<<"Wrong Password. Please Try Again..."<<endl;
		cout<<"Enter Admin Password: ";
		cin>>password;
	}
	if(password==p_word)
	{
	system("color 0e");
	string item[21];
	int count;
	cout<<"--------------------------------------"<<endl;
	cout<<"Enter The Number of Dishes For Today: ";
	cin>>count;
	ofstream inamu;
	inamu.open("amu.txt");
	inamu<<count;
	inamu.close(); 
	int price[count];
	system("cls");
	cout<<"						 *******************"<<endl;
	cout<<"						*|Enter Items Below|*"<<endl;
	cout<<"						 *******************"<<endl;
	cout<<endl<<endl;
	for(int i=1;i<=count;i++)
	{
		cout<<"						----------------------------"<<endl;
		cout<<"						"<<i<<"- Enter The Name OF Dish: ";
		cin>>item[i];
		cout<<"						------------"<<endl;
		cout<<"						Enter Price: ";
		cin>>price[i];
	}
	indata.open("menu.txt");
	indata<<"Items\t\t\t\t"<<"Price"<<endl;
	for(int i=1;i<=count;i++)
	{
		indata<<item[i]<<"\t\t\t\t"<<price[i]<<endl;
	}
	cout<<endl;
	cout<<"\a";
	cout<<"						*************************"<<endl;
	cout<<"						*Data Saved Successfully*"<<endl;
	cout<<"						*************************"<<endl;
}
indata.close();
outdata.close();
outpass.close();
system("pause");
}
