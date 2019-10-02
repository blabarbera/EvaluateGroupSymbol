//Write a program that takes as input an arithmetic expression followed by a semicolon; .
//
//The program outputs whether the expression contains matching grouping symbols.
//
//For example, the arithmetic expressions{ 25 + (3 – 6) * 8 } and 7 + 8 * 2 contains matching grouping symbols.
//
//However, the expression 5 + {(13 + 7) / 8 - 2 * 9 does not contain matching grouping symbols.

#include "myStack.h"
#include <iostream>

using namespace std;

int main()
{
	int i = 0;

	stackType<char> myStack(20); //create stackType object

	char str[100]; //declare character array

	//Prompt user for input
	cout << "Enter an arithmetic expression ending in ';': "; 
	cin.getline(str, 100, '\n');


	//Process user expression
	while (str[i] != ';')
	{
		switch (str[i])
		{
		case '{':
		case '[':
		case '(':
			myStack.push(str[i]);
			break;

		case '}':
			if (myStack.top() == '{')
				myStack.pop();
			break;

		case ')': 
			if (myStack.top() == '(')
				myStack.pop();
			break;

		case ']':
			if (myStack.top() == '[')
				myStack.pop();
			break;
		}
		i++;
	}

	//If stack is empty, matching grouping symbols were found
	if (myStack.isEmptyStack())
		cout << "Expression has matching grouping symbol";
	else
		cout << "Expression does not have matching grouping symbols";

	return 0;
}