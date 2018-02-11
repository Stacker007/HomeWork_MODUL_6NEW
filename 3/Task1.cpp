/*
1. Создать массив целых чисел размерностью N и заполнить его случайными
числами от -20 до 20. Объявить два массива указателей. Заполнить первый из них
указателями на положительные числа исходного массива, а второй – указателями на
отрицательные числа. Пользуясь массивами указателей, вывести на консоль сначала
положительные, а потом отрицательные значения.
*/

#include <iostream>
#include <ctime>
#define COL 20
using namespace std;
void randArr(int *a, int sizeArr);
void printArr(int *a, int sizeArr);
void printArr(int **a, int sizeArr);
void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int myArr[COL];
	int *posPtr[COL], *negPtr[COL];
	randArr(myArr, COL);
	printArr(myArr, COL);
	int *myPtr = myArr;
	int **positivePtr = posPtr;
	int **negativePtr = negPtr;
	int countOfPos = 0, countOfNeg = 0;
	cout << endl << endl;
	while (myPtr < myArr + COL)
	{
		if (*myPtr < 0)
		{
			*negativePtr++ = myPtr;
			countOfNeg++;
		}
		if (*myPtr > 0) 
		{
			*positivePtr++ = myPtr;
			countOfPos++;
		}
		myPtr++;
	}

	printArr(negPtr, countOfNeg);
	cout << endl << endl;
	printArr(posPtr, countOfPos);
	cout << endl << endl;
	
	system("pause");
}



void randArr(int *a, int sizeArr) {
	for (int i = 0; i<sizeArr; i++, a++)
		*a = rand() % 41 - 20;
}

void printArr(int *a, int sizeArr) {
	for (int i = 0; i < sizeArr; i++, a++)
		printf("%3d ", *a);
}
void printArr(int **a, int sizeArr) {
	for (int i = 0; i < sizeArr; i++, a++)
		printf("%3d ", **a);
}
