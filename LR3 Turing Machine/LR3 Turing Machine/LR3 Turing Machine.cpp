// LR3 Turing Machine.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <cstring>
#include <cstdio>
#include <conio.h>
#include <iomanip>
#include <Windows.h>

using namespace std;

int q = 1; 
int pos;            
char tape[10] = "#";
char num[10];

HANDLE hConsole;

enum ConsoleColor
{
	Green = 2,
	Red = 4,
	White = 15
};

void Print(char tape[10])
{
	for (int i = 0; i < 10; i++)
	{
		if (pos == i)
		{
			cout << setw(1) << " | ";
			SetConsoleTextAttribute(hConsole, 2);
			cout << tape[i];
		}
		else
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << setw(1) << " | " << tape[i];
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout << " Введите число в двоичной системе записи: ";
	gets_s(num);

	strcat_s(tape, num);
	pos = strlen(num) + 1;
	tape[pos] = '#';
	pos = strlen(num);

	cout << " Входная лента машины Тьюринга:" << endl;
	for (int i = 0; i < 10; i++)
		cout << setw(1) << " | " << tape[i];
	cout << endl << endl;

	int count = 1;
	char a = tape[pos]; 
	string st;

	cout << " Удаление всех нолей из числа " << num << " с помощью машины Тьюринга:" << endl;
	cout << " " << count << ") ";
	Print(tape);
	count++;
	st = "";

	while (q != 0)
	{
		a = tape[pos];
		switch (q)
		{
		case 1:             //q1
			switch (a)
			{
			case ('0'):
				q = 1;
				pos--;    
				st = "q1 0 -> q1 0Л";
				break;
			case ('1'):
				q = 1;
				pos--;
				st = "q1 1 -> q1 1Л";
				break;
			case ('#'):
				q = 2;
				pos++;
				st = "q1 # -> q2 #П";
				break;
			}
			break;

		case 2:           //q2
			switch (a)
			{
			case ('0'):
				q = 3;
				pos--;
				st = "q2 0 -> q3 0Л";
				break;
			case ('1'):
				q = 2;
				pos++;
				st = "q2 1 -> q2 1П";
				break;
			case ('#'):
				q = 0;
				st = "q2 # -> q0 #";
				break;
			}
			break;

		case 3:           //q3
			switch (a)
			{
			case ('0'):
				q = 2;
				tape[pos] = '1';
				pos--;
				st = "q3 0 -> q2 1Л";
				break;
			case ('1'):
				q = 3;
				tape[pos] = '0';
				pos++;
				st = "q3 1 -> q3 0П";
				break;
			case ('#'):
				q = 4;
				pos++;
				st = "q3 # -> q4 #П";
				break;
			}
			break;

		case 4:           //q4
			switch (a)
			{
			case ('0'):
				q = 2;
				tape[pos] = '#';
				pos++;
				st = "q4 0 -> q2 #П";
				break;
			case ('1'):
				break;
			case ('#'):
				break;
			}
			break;
		}
		SetConsoleTextAttribute(hConsole, 4);
		cout << endl << "              " << st << endl << endl;
		SetConsoleTextAttribute(hConsole, 15);
		cout << " " << count << ") ";
		Print(tape);
		count++; 
		SetConsoleTextAttribute(hConsole, 15);
		st = "";
	}
	SetConsoleTextAttribute(hConsole, 4);
	cout << endl << "                        " << "q0" << endl << endl;
	SetConsoleTextAttribute(hConsole, 15);
	cout << " Работа машины завершена" << endl;
	return 0;
}






