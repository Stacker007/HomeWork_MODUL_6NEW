/*
3. Дан массив целых чисел из 10 элементов (задать случайным образом).
Пользуясь ДВУМЯ указателями, нужно поменять порядок элементов массива на
обратный.
*/

#include <iostream>
#define SIZE 11
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
	int *beginPtr, *endPtr;
	beginPtr = myArr;
	endPtr = (myArr + SIZE - 1);
	while (beginPtr < endPtr)
	{
		int tmp = *beginPtr;
		*beginPtr = *endPtr;
		*endPtr = tmp;
		beginPtr++;
		endPtr--;
	}
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
