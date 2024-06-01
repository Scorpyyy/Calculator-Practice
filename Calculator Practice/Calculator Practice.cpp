// Calculator Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Calculator.h"
#include <iostream>
#include <sstream>
#include <limits>

using namespace std;




bool isValidNumber(const string& str) {
	std::istringstream iss(str);
	double num;
	iss >> num;
	return iss.eof() && !iss.fail();
}



int main()
{
	double x = 0.0;
	double y = 0.0;
	double result = 0.0;
	char oper = '+';


	cout << "Calculator Console Application" << endl << endl;
	cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b"
		<< endl;

	Calculator c;
	while (true)
	{
		string input;
		cout << "Enter Your Expression: ";
		cin >> input;

		if (input == "help") {
			cout << "Need Help? STFU" << endl;
			continue;
		}

		size_t operPos = input.find_first_of("+-*/");


		if (operPos == string::npos) {
			cout << "Please enter the operation to perform. Format: a+b | a-b | a*b | a/b" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;

		}
		string xStr = input.substr(0, operPos);
		string yStr = input.substr(operPos + 1);
		oper = input[operPos];





		if (!isValidNumber(xStr) || !isValidNumber(yStr)) {
			cout << "Pls Enter just numbers." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;

		}

		x = stod(xStr);
		y = stod(yStr);

		if (oper == '/' && y == 0) {
			cout << "Attempted to Devide by zero!" << endl;
			continue;
		}

		else {
			result = c.Calculate(x, oper, y);
		}

		cout << "Result " << "Of " << x << oper << y << " is: " << result << endl;
	}


	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
