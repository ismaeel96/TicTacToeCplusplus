//********************************************************************************
//* getChar
//********************************************************************************
void getChar(char& charInput)
{
	string            input;
	string::size_type len;

	while (true)
	{
		getline(cin, input);
		len = input.length();
		if (len != 1)
			cout << "Please enter a valid character as your response ==> ";
		else
		{
			charInput = input[0];
			return;
		}
	}

	return;
}


//********************************************************************************
//* getInt
//********************************************************************************
void getInt(int& intInput)
{
	string            trash;
	string::size_type len;

	while(true)
	{
		cin >> intInput;

		while (!cin)
		{
			cin.clear();
			getline(cin, trash);
			cout << "Please enter a valid number as your response ==> ";
			cin  >> intInput;
		}

		getline(cin, trash);
		len = trash.length();
		if (len == 0)
			return;
		else
			cout << "Please enter a valid number as your response ==> ";
	}

	return;
}	
