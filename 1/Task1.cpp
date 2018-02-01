/*
1. Создать массив из 10 целых чисел. Заполнить массив случайным образом в
диапазоне от -45 до 45. Пользуясь указателем(и) на массив целых чисел, посчитать
процент положительных и отрицательных элементов массива
*/

#include <iostream>
#include <ctime>
#define SIZE 111
void randArr(int *a, int sizeArr);
void printArr(int *a, int sizeArr);
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int myArr[SIZE];
	srand(time(0));
	randArr(myArr, SIZE);
	printArr(myArr, SIZE);
	int *ptrMy = myArr;
	int countOfNegative = 0;
	int countOfPositive = 0;
	while (ptrMy < (myArr + SIZE))
	{
		if (*ptrMy > 0) countOfPositive++;
		if (*ptrMy < 0) countOfNegative++;
		ptrMy++;
	}
	double percentPos, percentNeg;
	percentNeg = double(countOfNegative * 100) / SIZE;
	cout << countOfNegative;
	percentPos = double(countOfPositive * 100) / SIZE;
	printf("\nПоложительных элементов %3.2f %%, Отрицательных элементов %3.2f %%\n", percentPos, percentNeg);
	system("pause");
	return 0;
}

void randArr(int *a, int sizeArr) {
	for (int i = 0; i<sizeArr; i++, a++)
		*a = rand() % 91 - 45;
}

void printArr(int *a, int sizeArr) {
	for (int i = 0; i < sizeArr; i++, a++)
		printf("%3d ", *a);
}
