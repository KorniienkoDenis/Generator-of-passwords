#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

const char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
const char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char numbers[] = "0123456789";
const char special_case[] = "~!@#$%^&*()_+-=[]{}'\\|/:;<>,.?";

/* A function that generates a random password with selected generation parameters */
string Generate(int length, char flag_uppercase, char flag_numbers, char
	flag_specialcase)
{
	string set_result, password;

	if (flag_uppercase == 'n' && flag_numbers == 'n' && flag_specialcase == 'n')
	{
		for (int i = 0; i < length; i++)
			password += lower_case[rand() % 26 + 0];
		return password;
	}
	else if (flag_uppercase == 'y' && flag_numbers == 'n' && flag_specialcase ==
		'n')
	{
		set_result = static_cast<string>(lower_case) + upper_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 52 + 0];
		return password;
	}
	else if (flag_uppercase == 'y' && flag_numbers == 'y' && flag_specialcase ==
		'n')
	{
		set_result = static_cast<string>(lower_case) + upper_case + numbers;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 62 + 0];
		return password;
	}
	else if (flag_uppercase == 'y' && flag_numbers == 'y' && flag_specialcase ==
		'y')
	{
		set_result = static_cast<string>(lower_case) + upper_case + numbers + special_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 92 + 0];
		return password;
	}
	else if (flag_uppercase == 'n' && flag_numbers == 'y' && flag_specialcase ==
		'y')
	{
		set_result = static_cast<string>(lower_case) + numbers + special_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 66 + 0];
		return password;
	}
	else if (flag_uppercase == 'n' && flag_numbers == 'n' && flag_specialcase ==
		'y')
	{
		set_result = static_cast<string>(lower_case) + special_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 56 + 0];
		return password;
	}
	else if (flag_uppercase == 'y' && flag_numbers == 'n' && flag_specialcase ==
		'y')
	{
		set_result = static_cast<string>(lower_case) + upper_case + special_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 82 + 0];
		return password;
	}
	else
	{
		set_result = static_cast<string>(lower_case) + numbers;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 36 + 0];
		return password;
	}
}

int main()
{
	setlocale(0, "ukr");
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int length_password;
	char isUppercase;
	char isNumbers;
	char isSpecial;

	cout << " <----> Generator of password <---->\n\n";

	/* Check for the correctness of entering the length of the password from 3 to 30 inclusive. */
	do
	{
		cout << "Input the length of your password (3 to 30 inclusive): ";
		cin >> length_password;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (length_password <= 2 || length_password >= 31);

	/* Checking the correctness of the input of the answer from the user. */
	do
	{
		cout << "\tUse capital letters? (y - yes; n - no): ";
		cin >> isUppercase;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (isUppercase != 'y' && isUppercase != 'n');

	/* Checking the correctness of the input of the answer from the user. */
	do
	{
		cout << "\tUse numbers? (y - yes; n - no): ";
		cin >> isNumbers;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (isNumbers != 'y' && isNumbers != 'n');

	/* Checking the correctness of the input of the answer from the user. */
	do
	{
		cout << "\tUse special symbols? (y - yes; n - no): ";
		cin >> isSpecial;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (isSpecial != 'y' && isSpecial != 'n');

	string password = Generate(length_password, isUppercase, isNumbers, isSpecial);

	cout << endl;

	cout << "Generated password: " << password << endl;

	/* Write the password you generated in the Passwords.txt file. */
	ofstream fout("D:\\Passwords.txt", ios_base::app);
	if (!fout.is_open())
		cout << "Cannot open file!" << endl;

	if(fout.is_open())
		fout << password << "\n";

	fout.close();

	cout << endl;

	/* 
	Output the generated password and your previous passwords to the console.
	The new password is written at the end of the file, i.e. the last one!
	*/
	ifstream fin("D:\\Passwords.txt", ios_base::in);
	if (!fin.is_open())
		cout << "Cannot open file!" << endl;

	cout << "<---- List of previous generated passwords ---->" << endl;

	/* The number in the list in the output in the console and in the text document */
	int index = 1;
	while (!fin.eof())
	{

		password = "";
		fin >> password;

		if (password.empty())
			continue;

		cout << index++ << ". " << password << endl;

	}

	fin.close();

	return 0;
}