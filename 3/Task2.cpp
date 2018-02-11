/*
2. Двумерный массив размерностью N строк на M столбцов заполнить
случайными целыми числами от -10 до 10. 
Сформировать массив указателей наначало каждой строки двумерного массива. 
Отсортировать этот массив указателей
так, чтобы первые элементы строк оказались в порядке возрастания (сам двумерный
массив не изменяется, меняется только массив указателей). Вывести строки
двумерного массива в полученном порядке.
*/

#include <iostream>
#include <ctime>
#define ROW 10
#define COL 2
using namespace std;
void randArr(int *a, int sizeArr);
void multiRandArr(int *a, int row, int col);
void printArr(int *a, int sizeArr);
void multiPrintArr(int *a, int row, int col);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int myArr[ROW][COL] = {};
	multiRandArr(myArr[0], ROW, COL);
	multiPrintArr(myArr[0], ROW, COL);
	cout << endl << endl;

	int *a[ROW];
	int *rowPtr = myArr[0];

	int i = 0;
	while (rowPtr < myArr[0] + ROW * COL)
	{
		a[i++] = rowPtr;
		rowPtr += COL;
	}

	for (int k = ROW - 1; k > 0; k--) //Сортировка методом пузырька
		for (int i = 0; i < k; i++)
			if (*a[i] > *a[i + 1])//Здесь определяется порядок вывода
			{
				int *tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
	for (int i = 0; i<ROW; i++)
	{
		printArr(a[i], COL);
		cout << endl;
	}
	system("pause");
}



void randArr(int *a, int sizeArr) {
	for (int i = 0; i<sizeArr; i++, a++)
		*a = rand() % 21 - 10;
}
void multiRandArr(int *a, int row, int col) {
	for (int i = 0; i < row; i++, a += col) {
		randArr(a, col);
	}
}
void printArr(int *a, int sizeArr) {
	for (int i = 0; i < sizeArr; i++, a++)
		printf("%3d ", *a);
}
void multiPrintArr(int *a, int row, int col) {
	for (int i = 0; i < row; i++, a += col) {
		printArr(a, col);
		cout << endl;
	}
}
