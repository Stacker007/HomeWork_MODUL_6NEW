/*
1. Создать массив из 10 целых чисел. Заполнить массив случайным образом в
диапазоне от -45 до 45. Пользуясь указателем(и) на массив целых чисел, посчитать
процент положительных и отрицательных элементов массива
*/

#include <iostream>
#define SIZE 10
void randArr(int *a, int sizeArr);
void printArr(int *a, int sizeArr);
using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus");
	int myArr[SIZE];
	randArr(myArr, SIZE);
	printArr(myArr, SIZE);
	cout << endl;
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
