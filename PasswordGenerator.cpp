// PasswordGenerator.cpp : Defines the entry point for the console application.
//Forrest Bennett

#include "stdafx.h"
#include "iostream"
#include "ctime"
#include "cstring"
#include <string>
#include <fstream>
using namespace std;


string convertToString(char* a, int size)
{
	string s = a;
	return s;
}

int main()
{
	char c, s, spec;
	char x = ' '; //Unused character to help comparison
	int r, j, k, l;
	ofstream txtOut;

	char symbol[9] = {'?', '!', '#', '*', '_', '-', '&', '%', '$'}; //Generally accepted special characters

	cout << "Generate a password. \n";
	cout << "Enter the length of your password: ";

	//Error checking
	while (!(cin >> r)) 
	{
		cout << "Enter the length of your password (a number this time): ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout << "Do you want special characters? (ex: : # $ etc.) (y/n): ";
	cin >> spec;

	//Error checking
	while ((spec != 'y') && (spec != 'n'))
	{
		cout << "Please enter only 'y' or 'n': ";
		cin >> spec;
	}

	cout << "Save to an external file? (y/n): ";
	cin >> s;

	//Error checking
	while ((s != 'y') && (s != 'n'))
	{
		cout << "Please enter only 'y' or 'n': ";
		cin >> s;
	}

	if (s == 'y')
		txtOut.open("GeneratedPass.txt");

	srand(time(NULL));

	for  (int i = 0;  i < r; i++)
	{
		j = rand() % 26;
		k = rand() % 25;
		l = rand() % 9;

		//Randomizer picks capital, lowercase, number or special characters
		if ((spec == 'y') && ((k % 11) == 0))
			c = symbol[l];
		else if ((k % 4) == 0)
			c = 'A' + j;
		else if ((k % 3) == 0)
			c = 'a' + j;
		else
			c = '0' + (x % 9);

		while (c == x) //Ensures no repeating characters
			c = '0' + (x % 9);

		x = c; //resets comparison variable to ensure no repeating characters

		cout << c;

		if (s == 'y')
			txtOut << c; //Add to external file

	}
	cout << "\n";

	if (s == 'y')
	{
		txtOut << "\n"; 
		txtOut.close(); 
	}

	system("pause");

    return 0;
}

