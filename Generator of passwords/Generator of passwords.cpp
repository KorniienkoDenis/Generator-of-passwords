#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

const char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
const char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char numbers[] = "0123456789";
const char special_case[] = "~!@#$%^&*()_+-=[]{}'\\|/:;<>,.?";

/* Функція, яка генерує випадковий пароль з вибраними параметрами генерації */
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

	cout << " <----> Генератор паролів <---->\n\n";

	/* Перевірка на правильність вводу довжини паролю від 3 до 30 включно. */
	do
	{
		cout << "Введіть довжину вашого паролю (від 3 до 30 включно): ";
		cin >> length_password;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (length_password <= 2 || length_password >= 31);

	/* Перевірка на правильність вводу відповіді від користувача */
	do
	{
		cout << "\tЧи використовувати великі літери? (y - так; n - ні): ";
		cin >> isUppercase;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (isUppercase != 'y' && isUppercase != 'n');

	/* Перевірка на правильність вводу відповіді від користувача */
	do
	{
		cout << "\tЧи використовувати цифри? (y - так; n - ні): ";
		cin >> isNumbers;
		cin.ignore(32767, '\n');
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (isNumbers != 'y' && isNumbers != 'n');

	/* Перевірка на правильність вводу відповіді від користувача */
	do
	{
		cout << "\tЧи використовувати спеціальні символи? (y - так; n - ні): ";
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

	cout << "Сгенерований пароль: " << password << endl;

	/* Записуємо в файл Passwords.txt пароль, який ви згенерували */
	ofstream fout("D:\\Passwords.txt", ios_base::app);
	if (!fout.is_open())
		cout << "Cannot open file!" << endl;
	fout << password << '\n';
	fout.close();
	cout << endl;

	/* Виводимо в консоль згенерований пароль та ваші попередні паролі. Новий
	пароль записується в кінець файлу, тобто останнім! */
	ifstream fin("D:\\Passwords.txt", ios_base::in);
	if (!fin.is_open())
		cout << "Cannot open file!" << endl;
	cout << "<---- Список попередніх згенерованих паролів ---->" << endl;

	/* Номер в списку в виведенні в консолі та в текстовому документі */
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