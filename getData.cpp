//********************************************************************************
//
//  Author:           Chris Solakian
//  Date Created:     11/26/2010
//  Revisions:        1/8/2015
//
//  Purpose:          This is the implementation file for the getData object.
//                    The getData object is used to input data from the console.
//                    ITCS 2530; D.S. Malik
//
//  Input:            None.
//  Output:           None.
//
//********************************************************************************

#include <iostream>
#include <string>
#include "getData.h"

using namespace std;

//********************************************************************************
//* getChar
//********************************************************************************
void getData::getChar(char& charInput)
{
	string strInput;

	while (true)
	{
		getline(cin, strInput);
		pruneString(strInput, " \t");      // Remove whitespace from strInput
		if (strInput.length() == static_cast<string::size_type>(1))
		{
			charInput = strInput[0];
			return;
		}
		cout << "Please enter a valid character as your response ==> ";
	}
}

//********************************************************************************
//* getInt
//********************************************************************************
void getData::getInt(int& intInput)
{
	string trash;

	while (true)
	{
		cin >> intInput;
		while (!cin)
		{
			cin.clear();
			getline(cin, trash);
			cout << "Please enter a valid number as your response ==> ";
			cin >> intInput;
		}

		getline(cin, trash);
		pruneString(trash, " \t");      // Remove whitespace from trash
		if (trash.length() == static_cast<string::size_type>(0))
			return;
		cout << "Please enter a valid number as your response ==> ";
	}
}

//********************************************************************************
//* getIntChar
//********************************************************************************
void getData::getIntChar(int& intInput, char& charInput)
{
	string trash;
	string strInput;

	while (true)
	{
		cin >> intInput;
		while (!cin)
		{
			cin.clear();
			getline(cin, trash);
			cout << "A valid response is a number followed by a character ==> ";
			cin >> intInput;
		}

		getline(cin, strInput);
		pruneString(strInput, " \t");      // Remove whitespace from strInput
		if (strInput.length() == static_cast<string::size_type>(1))
		{
			charInput = strInput[0];
			return;
		}
		cout << "A valid response is a number followed by a character ==> ";
	}
}

//********************************************************************************
//* pruneString
//********************************************************************************
void getData::pruneString(string& strInput, char prunedChar)
{
	for (string::iterator i = strInput.begin(); i != strInput.end(); )
	{
		if (*i == prunedChar)
			i = strInput.erase(i);
		else
			i++;
	}
}

//********************************************************************************
//* pruneString
//********************************************************************************
void getData::pruneString(string& strInput, string prunedStr)
{
	for (int i = 0; i < static_cast<int>(prunedStr.length()); i++)
		pruneString(strInput, prunedStr[i]);
}