/*4. Массив из 10-ти элементов заполнить случайными числами от 0 до 5.
Пользуясь указателями, найти максимальное количество подряд идущих нулей.*/

#include <iostream>
#include <ctime>
#define SIZE 50
using namespace std;
void randArr(int *a, int sizeArr);
void printArr(int *a, int sizeArr);


void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arrA[SIZE];
	//Генерация массива А[n]:

	{
		randArr(arrA, SIZE);
		cout << "Несортированный массив А[n]:" << endl;
		printArr(arrA, SIZE);
	}

	int maxCountOfZero = 0;
	int *ptrA;
	for (ptrA = arrA; ptrA <= arrA + SIZE - 1; ptrA++) { //перебор всех элементов массива
		if (*ptrA == 0) {
			int *nullPtr;
			int nullCout = 1;
			for (nullPtr = ptrA + 1; nullPtr < arrA + SIZE; nullPtr++) {//перебор всех элементов массива, следующихза нулем
				if (*nullPtr == 0) nullCout++;
				else break;
			}
			if (nullCout > maxCountOfZero)maxCountOfZero = nullCout;
		}
	}
	cout << "Сортированный массив А[n]:" << maxCountOfZero << endl;
	system("pause");
}


void randArr(int *a, int sizeArr) {
	for (int i = 0; i<sizeArr; i++, a++)
		*a = rand() % 3;
}
void printArr(int *a, int sizeArr) {
	for (int i = 0; i < sizeArr; i++, a++)
		cout << *a << " ";
	cout << endl;
}

