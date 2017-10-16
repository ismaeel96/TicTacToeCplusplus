//********************************************************************************
//
//  Author:           Chris Solakian
//  Date Created:     11/26/2010
//  Revisions:        1/8/2015
//
//  Purpose:          This is the header file for the getData object.
//                    The getData object is used to input data from the console.
//                    This file contains the class definition; including the
//                    object's function prototypes (see below for a description of
//                    each function).
//                    ITCS 2530; D.S. Malik
//
//  Input:            None.
//  Output:           None.
//
//********************************************************************************

using namespace std;

class getData
{
public:
	static void getChar(char& charInput);
	// Function to get one char from the console.
	// Function ensures that only one char is provided.
	// Whitespace is ignored.

	static void getInt(int& intInput);
	// Function to get one int from the console.
	// Function ensures that only one int is provided.
	// Whitespace is ignored.

	static void getIntChar(int& intInput, char& charInput);
	// Function to get one int followed by one char from the console.
	// Function ensures that no additional input is provided.
	// Whitespace is ignored.

	static void pruneString(string& strInput, char prunedChar);
	// Function will prune a string of one character.
	// strInput will be pruned of all instances of prunedChar.

	static void pruneString(string& strInput, string prunedStr);
	// Function will prune a string of all characters contained in a second string.
	// strInput will be pruned of all instances of all characters contained in
	// prunedStr.
};