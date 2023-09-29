﻿#include <iostream>
#include <windows.h>


using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int h, m; //, h - количество часов, m - количество минут
	string d, x, y; //  d - часть дня (утро, день, вечер, ночь), x - падежное окончание часов, y - падежное окончание минут

	cout << "Введите время в следующем формате - ЧАС(от 0 до 24) и МИНУТЫ(от 0 до 59) : " << endl;
	cin >> h >> m;
	if (!(h >= 0 && h <= 25 && m >= 0 && m <= 60))
	{
		cout << "Данные введены неверно, попробуйте снова!" << endl;
		return 0;
	}

	if (h < 0 || h > 24 || m < 0 || m > 59)
	{
		cout << "Введённые данные некорректы! Попробуйте ещё раз";
	}
	else
	{
		if (h == 12 && m == 0)
		{
			cout << "полдень\n";
		}
		else if ((h == 24 || h == 0) && m == 0)
		{
			cout << "полночь\n";
		}
		else
		{
			/* Часть дня
			* 0 <= h < 5 - ночь
			* 5 <= h < 12 - утро
			* 12 <= h < 18 - день
			* 18 <= h <= 23 - вечер
			*/
			if (h >= 5 && h < 12)
			{
				d = "утра";
			}
			else if (h >= 12 && h < 18)
			{
				d = "дня";
			}
			else if (h >= 18 && h <= 23)
			{
				d = "вечера";
			}
			else
			{
				d = "ночи";
			}
			/* Падежное окончание часов
			*
			* 1 - Час
			*
			* 2, 3, 4  - Часа
			*
			* 5, 6, 7, 8, 9, 10, 11, 12 - Часов
			*
			*/
			if (h == 1 || h == 13)
			{
				x = "час";
			}
			else if (h > 1 && h < 5 || h > 13 && h < 17)
			{
				x = "часа";
			}
			else
			{
				x = "часов";
			}
			/* Падежное окончание минут
			*
			* 1, 21, 32, 41, 51 - Минута
			*
			* 2, 22, 32, 42, 52
			* 3, 23, 33, 43, 53 - Минуты
			* 4, 24, 34, 44, 54
			*
			* 10, 20, 30, 40, 50
			* 11
			* 12
			* 13
			* 14					- Минут
			* 5, 15, 25, 35, 45, 55
			* 6, 16, 26, 36, 46, 56
			* 7, 17, 27, 37, 47, 57
			* 8, 18, 28, 38, 48, 58
			* 9, 19, 29, 39, 49, 59
			*/
			if (m == 0)
			{
				y = "";
			}
			else if (m % 10 == 1 && m != 11)
			{
				y = "минута";
			}
			else if ((m % 10 == 2 || m % 10 == 3 || m % 10 == 4) && !(m >= 12 && m <= 14))
			{
				y = "минуты";
			}
			else
			{
				y = "минут";
			}
			if (m == 0) // Учёт случая, когда m = 0, т.е. необходимо использовать слово "ровно"
			{
				if (h > 0 && h < 13)
				{
					cout << h << " " << x << " " << d << " " << "ровно\n";
				}
				else
				{
					cout << h % 12 << " " << x << " " << d << " " << "ровно\n";
				}
			}
			else
			{
				if (h >= 0 && h < 13)
				{
					cout << h << " " << x << " " << m << " " << y << " " << d << "\n";
				}
				else
				{
					cout << h % 12 << " " << x << " " << m << " " << y << " " << d << "\n";
				}
			}

		}
	}
	return 0;
}