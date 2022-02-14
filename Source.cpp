#define NOMINMAX

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>

#include "Time.h"

void CheckInput(int &input_buff, const int &count)
{

	while (!std::cin.good() || std::cin.peek() != '\n')		//Проверка на то, что int
	{

		std::cerr << "Некорректный ввод данных!!!" << std::endl;
		std::cout << "Вводимое поле должно быть целым положительным числом!!!" << std::endl;
		std::cout << "Повторите ввод!!!" << std::endl;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cin >> input_buff;
		std::cout << std::endl;

	}

	if (count == 0)		//Проверка на попадание в промежуток для поле часы
	{

		if (input_buff < 0 || input_buff > 23)
		{

			std::cerr << "Некорректный ввод данных!!!" << std::endl;
			std::cout << "Вводимое поле должно быть в диапазоне от 00 до 23!!!" << std::endl;
			std::cout << "Повторите ввод!!!" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> input_buff;
			std::cout << std::endl;

			CheckInput(input_buff, count);

		}

	}

	if (count == 1)		//Проверка на попадание в промежуток для полей секунды и минуты
	{

		if (input_buff < 0 || input_buff > 59)
		{

			std::cerr << "Некорректный ввод данных!!!" << std::endl;
			std::cout << "Вводимое поле должно быть в диапазоне от 00 до 59!!!" << std::endl;
			std::cout << "Повторите ввод!!!" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> input_buff;
			std::cout << std::endl;

			CheckInput(input_buff, count);

		}

	}

	if (count == 2)
	{

		if (input_buff < 1 || input_buff > 5)
		{

			std::cerr << "Некорректный ввод данных!!!" << std::endl;
			std::cout << "Вводимое поле должно быть в диапазоне от 1 до 5!!!" << std::endl;
			std::cout << "Повторите ввод!!!" << std::endl;

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> input_buff;
			std::cout << std::endl;

			CheckInput(input_buff, count);

		}

	}

}

void SetTime(int &hours, int &minutes, int &seconds, const int &flag)
{

	if (flag == 0)
	{

		std::cout << "Введите первое время: " << std::endl;

	}

	if (flag == 1)
	{

		std::cout << "Введите второе время: " << std::endl;

	}

	std::cout << std::endl;

	std::cout	<< "Часы: ";
	std::cin	>> hours;

	std::cout << std::endl;
	

	CheckInput(hours, 0);
	
	std::cout << std::endl;
	

	std::cout	<< "Минуты: ";
	std::cin	>> minutes;

	std::cout << std::endl;
	

	CheckInput(minutes, 1);

	std::cout << std::endl;
	

	std::cout	<< "Секунды: ";
	std::cin	>> seconds;

	std::cout << std::endl;
	

	CheckInput(seconds, 1);

	std::cout << std::endl;

}

void ShowTime(Time &time, const int &flag)
{

	if (flag == 0)
	{

		std::cout << "Время один: " << std::endl;

	}

	if (flag == 1)
	{

		std::cout << "Время два: " << std::endl;

	}

	if (flag == 2)
	{

		std::cout << "Полученное время: " << std::endl;

	}
	
	std::cout	<< std::setw(2) << std::setfill('0') << time.getHourse() << ":" 
				<< std::setw(2) << std::setfill('0') << time.getMinutes() << ":"
				<< std::setw(2) << std::setfill('0') << time.getSeconds() << std::endl;

	std::cout	<< std::endl;

}

void AddMinutes(Time &time)
{

	int minutes{};

	std::cout << "Введите количество минут, которое нужно добавить: ";
	std::cin  >> minutes;
	CheckInput(minutes, 4);

	std::cout << std::endl;

	ShowTime(time, 0);

	time += minutes;

	ShowTime(time, 2);

}

void Substraction(Time &timeOne, Time &timeTwo)
{

	Time res{};

	res = timeOne - timeTwo;

	ShowTime(res, 2);

}

void main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Задание" << std::endl;
	std::cout << " Разработать класс «Время». Определить в нем конструкторы и деструктор," << std::endl;
	std::cout << "перегрузить операцию добавления к времени заданного количества минут, операцию" << std::endl;
	std::cout << "вычитания двух моментов времени, операцию сравнения двух дат на совпадение(несовпадение)." << std::endl;

	int hours{};
	int minutes{};
	int seconds{};
	int choice{};

	SetTime(hours, minutes, seconds, 0);
	Time timeOne{ hours, minutes, seconds };

	SetTime(hours, minutes, seconds, 1);
	Time timeTwo{ hours, minutes, seconds };

	ShowTime(timeOne, 0);
	ShowTime(timeTwo, 1);

	while (choice != 5)
	{

		std::cout << "Введите номер действия, которое необходимо выполнить: " << std::endl;
		std::cout << "1 - Добавить минуты к первому времени" << std::endl;
		std::cout << "2 - Добавить минуты к второму времени" << std::endl;
		std::cout << "3 - Сравнить два времени" << std::endl;
		std::cout << "4 - Вычесть второе вермя из первого" << std::endl;
		std::cout << "5 - Выйти из программы" << std::endl;

		std::cout << "Введите число: ";
		std::cin  >> choice;
		std::cout << std::endl;

		CheckInput(choice, 2);

		std::cout << std::endl;

		switch (choice)
		{

		case 1:

			AddMinutes(timeOne);

			break;

		case 2:

			AddMinutes(timeTwo);

			break;

		case 3:

			if (timeOne == timeTwo)
			{

				std::cout << "Время один равно времени два и имеют значение: " << std::endl;
				ShowTime(timeOne, 4);

				std::cout << std::endl;

			}

			else
			{

				std::cout << "Время один неравно времени два." << std::endl;
				ShowTime(timeOne, 0);
				std::cout << std::endl;
				ShowTime(timeTwo, 1);
				std::cout << std::endl;

			}

			break;

		case 4:

			Substraction(timeOne, timeTwo);

			break;

		default:
			break;
		}

	}

}