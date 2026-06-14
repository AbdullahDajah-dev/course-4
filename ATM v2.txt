#include <iostream>
#include <cmath>
#include <string>
using namespace std;

enum enButtons { Withdraw = 1, Deposite, Exit };


int ReadPositiveNumber(string msg)
{
	int number;
	cout << msg;
	cin >> number;

	return number;
}
int ReadPIN(string msg)
{
	int pin;
	cout << msg;
	cin >> pin;
	cout << endl;

	return pin;
}
bool CheckPIN(int pin)
{
	int attempts = 3;
	while (pin != 1234 && attempts > 1)
	{
		attempts--;
		pin = ReadPIN("Wrong PIN try again, " + to_string(attempts) + " left:\n");


	}
	return (pin == 1234);
}
bool UserAccess(int pin)
{

	if (!CheckPIN(pin))
	{
		system("color 4f");
		cout << "Card locked, visit your branch\n" << endl;
		return false;
	}
	else {

		cout << "Balance: 7500$\n" << endl;
		return true;
	}
	
}
int ReadButtonID(string msg)
{
	int button_id;
	cout << msg << endl;
	cin >> button_id;

	return button_id;
}
enButtons ButtonList()
{
	int button;
	do
	{
		button = ReadButtonID("Please select from the following\n(1) withdraw   (2)Deposite   (3)Exit");

	} while (button > 3 || button < 1);
	return (enButtons)button;
}
string UserOptions(enButtons select)
{
	switch (select)
	{
	case enButtons::Withdraw:
		return "How much to withdraw? ";
	case enButtons::Deposite:
		return "How much to deposite? ";
	case enButtons::Exit:
		return "Bye!";
	default:
		return "Invalid input";
	}

}
string WithdrawalProcess(int current_balance, int withdrawal)
{
	if (withdrawal > current_balance || withdrawal < 1)
	{
		system("color 4f");
		return "\nInvalid amount.";
	}
	else {
		current_balance = current_balance - withdrawal;
		system("color 2f");
		return "\nSuccess! Your balance is " + to_string(current_balance);
	}

}
string DepositeProcess(int current_balance, int deposite)
{
	if (deposite < 1)
	{
		system("color 4f");
		return "\nInvalid amount.";
	}
	else {
		system("color 2f");
		current_balance = current_balance + deposite;
		return "\nSuccess! Your balance is " + to_string(current_balance);
	}

}
void Transactions(enButtons button_id)
{

	if (button_id == enButtons::Withdraw)
	{
		int amount = ReadPositiveNumber("Enter amount: ");
		string withdrawl_process = WithdrawalProcess(7500, amount);
		cout << withdrawl_process << endl;
	}
	else {
		int amount = ReadPositiveNumber("Enter amount: ");
		string deposite_process = DepositeProcess(7500, amount);
		cout << deposite_process << endl;
	}
}


int main()
{
	int pin = ReadPIN("Enter PIN: ");
	if (!UserAccess(pin))
		return 0;


	enButtons button_list = ButtonList();
	string user_options = UserOptions(button_list);
	cout << user_options << endl;
	if (button_list == Exit)
		return 0;

	Transactions(button_list);



	return 0;
}