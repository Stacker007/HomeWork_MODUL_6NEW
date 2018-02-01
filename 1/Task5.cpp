/*5. Сформировать двумерный массив из 4 строк и 5 столбцов, заполнив его
случайными числами от -10 до 10. Распечатать исходный массив. Затем заполнить
все четные строки нулями и опять распечатать преобразованный массив.
Использовать указатели!*/

#include <iostream>
#include <ctime>
#define ROW 4
#define COL 5
using namespace std;
void randArr(int *a, int sizeArr);
void multiRandArr(int *a, int row, int col);
void printArr(int *a, int sizeArr);
void multiPrintArr(int *a, int row, int col);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int myArr[4][5] = {};
	multiRandArr(myArr[0], ROW, COL);
	multiPrintArr(myArr[0], ROW, COL);

	system("pause");
}


void randArr(int *a, int sizeArr) {
	for (int i = 0; i<sizeArr; i++, a++)
		*a = rand() % 91 - 45;
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

