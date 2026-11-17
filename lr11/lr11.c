#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

// дата
struct date {
	int day;
	int month;
	int year;
};
typedef struct date Date;

// запись грузовик
struct truck {
	char brand[50];     // марка
	char maker[50];     // производитель
	double capacity;    // грузоподъемность в тоннах
	int year;           // год выпуска
	Date reg;           // дата регистрации
};
typedef struct truck Truck;

int moreThanYear(Date reg, Date today);
void printTruck(Truck t);

int main() {
	Truck trucks[6] = {
		{ "ГАЗон Next",  "ГАЗ",   4.5,  2021,{ 5,  4, 2022 } },
		{ "ГАЗель NN",   "ГАЗ",   1.5,  2018,{ 12, 9, 2018 } },
		{ "КАМАЗ-65115", "КАМАЗ", 15.0, 2024,{ 20, 11, 2025 } },
		{ "МАЗ-4371",    "МАЗ",   5.0,  2023,{ 17, 11, 2025 } },
		{ "Урал-4320",   "Урал",  10.0, 2017,{ 1,  3, 2018 } },
		{ "Isuzu NQR",   "Isuzu", 3.0,  2020,{ 10, 10, 2020 } }
	};
	Date today;
	int i, count = 0;

	setlocale(LC_ALL, "Russian");

	// вводим сегодняшнюю дату
	printf("Введите сегодняшнюю дату (день месяц год): ");
	scanf("%d %d %d", &today.day, &today.month, &today.year);

	for (i = 0; i < 6; i++) {
		// грузоподъемность больше 3 и с регистрации прошло больше года
		if (trucks[i].capacity > 3 && moreThanYear(trucks[i].reg, today)) {
			printTruck(trucks[i]);
			count++;
		}
	}

	if (count == 0)
		printf("Таких машин нет\n");

	return 0;
}

// проверяет прошло ли больше года с даты регистрации
int moreThanYear(Date reg, Date today) {
	if (today.year - reg.year > 1)
		return 1;
	if (today.year - reg.year == 1) {
		if (today.month > reg.month)
			return 1;
		if (today.month == reg.month && today.day > reg.day)
			return 1;
	}
	return 0;
}


void printTruck(Truck t) {
	printf("Марка: %s\n", t.brand);
	printf("Производитель: %s\n", t.maker);
	printf("Грузоподъемность: %.1f т\n", t.capacity);
	printf("Год выпуска: %d\n", t.year);
	printf("Дата регистрации: %02d.%02d.%d\n\n", t.reg.day, t.reg.month, t.reg.year);
}
