#include <iostream>
#include <cmath>
#include <string>
using namespace std;

enum enOpType {Add = '+', subtract = '-', multiply = '*' , divide = '/' };
float ReadNumber(string msg)
{
	int n;
	cout << msg;
	cin >> n;
	
	return n;
}
enOpType ReadOpType(string msg)
{
	char OT = '+';
	cout << msg;
	cin >> OT;

	return (enOpType)OT;

}
float Calculate(float num1, float num2, enOpType ot)
{
	switch (ot)
	{
	case enOpType::Add:
		return num1 + num2;
	case enOpType::subtract:
		return num1 - num2;
	case enOpType::multiply:
		return num1 * num2;
	case enOpType::divide:
		return num1 / num2;
	default: 
		return num1 + num2;
	}

}





int main()
{
	
	
	float number1 = ReadNumber("Enter number A? ");
	float number2 = ReadNumber("Enter number B? ");
	enOpType optype = ReadOpType("Enter OP type? ");

	cout << "Result = " << Calculate(number1, number2, optype);
	



	return 0;
}