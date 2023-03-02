#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

const char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
const char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char numbers[] = "0123456789";
const char special_case[] = "~!@#$%^&*()_+-=[]{}'\\|/:;<>,.?";

/* �������, ��� ������ ���������� ������ � ��������� ����������� ��������� */
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
		set_result = string(lower_case) + upper_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 52 + 0];
		return password;
	}
	else if (flag_uppercase == 'y' && flag_numbers == 'y' && flag_specialcase ==
		'n')
	{
		set_result = string(lower_case) + upper_case + numbers;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 62 + 0];
		return password;
	}
	else if (flag_uppercase == 'y' && flag_numbers == 'y' && flag_specialcase ==
		'y')
	{
		set_result = string(lower_case) + upper_case + numbers + special_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 92 + 0];
		return password;
	}
	else if (flag_uppercase == 'n' && flag_numbers == 'y' && flag_specialcase ==
		'y')
	{
		set_result = string(lower_case) + numbers + special_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 66 + 0];
		return password;
	}
	else if (flag_uppercase == 'n' && flag_numbers == 'n' && flag_specialcase ==
		'y')
	{
		set_result = string(lower_case) + special_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 56 + 0];
		return password;
	}
	else if (flag_uppercase == 'y' && flag_numbers == 'n' && flag_specialcase ==
		'y')
	{
		set_result = string(lower_case) + upper_case + special_case;
		for (int i = 0; i < length; i++)
			password += set_result[rand() % 82 + 0];
		return password;
	}
	else
	{
		set_result = string(lower_case) + numbers;
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

	cout << " <----> ��������� ������ <---->\n\n";

	/* �������� �� ����������� ����� ������� ������ �� 3 �� 30 �������. */
	do
	{
		cout << "������ ������� ������ ������ (�� 3 �� 30 �������): ";
		cin >> length_password;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (length_password <= 2 || length_password >= 31);

	/* �������� �� ����������� ����� ������ �� ����������� */
	do
	{
		cout << "\t�� ��������������� ����� �����? (y - ���; n - �): ";
		cin >> isUppercase;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (isUppercase != 'y' && isUppercase != 'n');

	/* �������� �� ����������� ����� ������ �� ����������� */
	do
	{
		cout << "\t�� ��������������� �����? (y - ���; n - �): ";
		cin >> isNumbers;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (isNumbers != 'y' && isNumbers != 'n');

	/* �������� �� ����������� ����� ������ �� ����������� */
	do
	{
		cout << "\t�� ��������������� ��������� �������? (y - ���; n - �): ";
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

	cout << "������������ ������: " << password << endl;

	/* �������� � ���� Passwords.txt ������, ���� �� ����������� */
	ofstream fout("D:\\Passwords.txt", ios_base::app);
	if (!fout.is_open())
		cout << "Cannot open file!" << endl;
	fout << password << '\n';
	fout.close();
	cout << endl;

	/* �������� � ������� ������������ ������ �� ���� �������� �����. �����
	������ ���������� � ����� �����, ����� �������! */
	ifstream fin("D:\\Passwords.txt", ios_base::in);
	if (!fin.is_open())
		cout << "Cannot open file!" << endl;
	cout << "<---- ������ ��������� ������������ ������ ---->" << endl;

	/* ����� � ������ � �������� � ������ �� � ���������� �������� */
	int index = 1;
	while (!fin.eof())
	{
		fin >> password;

		if (password.empty())
		{
			break;
		}

		cout << index++ << ". " << password << endl;
	}

	fin.close();

	return 0;
}