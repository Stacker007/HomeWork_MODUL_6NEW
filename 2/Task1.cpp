/*
1. Даны два массива: А[n] и B[m] (сгенерировать случайным образом).
Необходимо создать еще два массива, в которые нужно собрать:
• Общие элементы двух массивов;
• Элементы массива A, которые не включаются в B;
Повторов в новых массивах не должно быть! (т.е. если общий элемент повторяется
в исходном массиве несколько раз, то в результирующем массиве он присутствует
только один раз)
*/

#include <iostream>
#include <ctime>
#define NSIZE 7
#define MSIZE 6
using namespace std;
void randArr(int *a, int sizeArr);
void printArr(int *a, int sizeArr);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arrA[NSIZE];
	int arrB[MSIZE];
	int arrC[MSIZE];
	int arrD[NSIZE];
	//Генерация  массива  А[n]:
	//(Инициализируем случайными числами)
	{
		randArr(arrA, NSIZE);
		cout << "Исходный массив А[n]:" << endl;
		printArr(arrA, NSIZE);
		
	}
	//Генерация  массива  B[m]:
	{
		randArr(arrB, MSIZE);
		cout << "Исходный массив B[m]:" << endl;
		printArr(arrB, MSIZE);
		
	}

	int *ptrA, *ptrB, *ptrC, *ptrD;
	ptrA = arrA;
	ptrB = arrB;
	ptrC = arrC;
	int colGeneral = 0;
	while (ptrA < arrA + NSIZE)
	{
		bool flag = true;
		int *tmpptr = arrC;
		while (tmpptr < arrC + MSIZE)
		{
			if (*tmpptr == *ptrA) {
				flag = false;
				break;
			}
			tmpptr++;
		}
		while (flag && ptrB < arrB + MSIZE)
		{
			if (*ptrA == *ptrB) {
				*ptrC++ = *ptrA;
				colGeneral++;
				break;
			}
			ptrB++;
		}
	}

	

	cout << endl << "Итоговый массив C[]" << endl;
	printArr(arrC, colGeneral);
	system("pause");
}


void randArr(int *a, int sizeArr) {	
	for (int i = 0; i<sizeArr; i++, a++)
		*a = rand() % 21 - 10;
}
void printArr(int *a, int sizeArr) {	
	for (int i = 0; i < sizeArr; i++, a++)
		cout << *a << " ";
	cout << endl;
}

