#include <iostream>

using namespace std;

struct Employee
{
	 char surname[10];
	 char name[10];
	 char pathronym[15];
	 char faculty[20];
	 char chair[15];
	 char appointment[10];
	 int KeyNumOfHours; //key 
};

void createEmployee(Employee(&obj));
void printEmployees(Employee(&obj));
void deleteArray(Employee* obj);

int main()
{
	setlocale(LC_ALL, "RUS");

	int arrayLength;

	Employee* employees;

	cout << "Введите количество работников (небольшое, до 5): ";
	cin >> arrayLength;
	
	employees = new Employee[arrayLength];

	for (int i = 0; i < arrayLength; i++)
	{
		createEmployee(employees[i]);
	}

	cout << "--------------Original Struct----------------" << endl;
	for(int i = 0; i < arrayLength; i++)
		printEmployees(employees[i]);

	//Sort
	int tempNum;
	char tempChar[128];


	for (int i = 0; i < arrayLength; i++)
	{
		for (int j = 0; j < arrayLength; j++)
		{
			if (employees[i].KeyNumOfHours > employees[j].KeyNumOfHours)
			{
				tempNum = employees[i].KeyNumOfHours;
				employees[i].KeyNumOfHours = employees[j].KeyNumOfHours;

				employees[j].KeyNumOfHours = tempNum;
			}
		}
	}

	cout << "--------------Sorted Struct----------------" << endl;
	for (int i = 0; i < arrayLength; i++)
		printEmployees(employees[i]);
}

void createEmployee(Employee(&obj))
{
	cout << "Введите фамилию" << endl;
	cin >> obj.surname;

	cout << "Введите имя" << endl;
	cin >> obj.name;

	cout << "Введите отчество" << endl;
	cin >> obj.pathronym;

	cout << "Введите факультет" << endl;
	cin >> obj.faculty;

	cout << "Введите кафедру" << endl;
	cin >> obj.chair;

	cout << "Введите должность" << endl;
	cin >> obj.appointment;

	obj.KeyNumOfHours = rand() % 500;
	cout << "Количество часов задано автоматически: " << obj.KeyNumOfHours << endl;
}

void printEmployees(Employee(&obj))
{
	cout << "Фамилия - " << obj.surname << endl;
	cout << "Имя - " << obj.name << endl;
	cout << "Отчество - " << obj.pathronym << endl;
	cout << "Факультет - " << obj.faculty << endl;
	cout << "Кафедра - " << obj.chair << endl;
	cout << "Должность - " << obj.appointment << endl;
	cout << "Количество часов - " << obj.KeyNumOfHours << endl;
	cout << endl;
}

void deleteArray(Employee* obj)
{
	delete[] obj;
	cout << "Массив удалён" << endl;
}