/*4. Даны два массива: А[n] и B[m]. Необходимо создать третий массив, в котором
нужно собрать:
• Общие элементы двух массивов;
• Элементы массива A, которые не включаются в B;*/

#include <iostream>
#include <ctime>
#define NSIZE 33
#define MSIZE 12
using namespace std;
void randArr(int a[], int sizeArr);
void printArr(int a[], int sizeArr);
void sortArr(int a[], int sizeArr);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arrA[NSIZE];
	int arrB[MSIZE];
	int arrC[NSIZE] = {};
	//Генерация сортированного массива  А[n]:
	//(Инициализируем случайными числами)
	{
		randArr(arrA, NSIZE);
		/*cout << "Исходный массив А[n]:" << endl;
		printArr(arrA, NSIZE);*/
		sortArr(arrA, NSIZE);
		cout << "Сортированный массив А[n]:" << endl;
		printArr(arrA, NSIZE);
	}
	//Генерация сортированного массива  B[m]:
	{
		randArr(arrB, MSIZE);
		/*cout << "Исходный массив B[m]:" << endl;
		printArr(arrB, MSIZE);*/
		sortArr(arrB, MSIZE);
		cout << "Сортированный массив B[m]:" << endl;
		printArr(arrB, MSIZE);
	}

	int *ptrA, *ptrB, *ptrC;
	ptrC = arrC;
	int col = 0;
	for (ptrA = arrA; ptrA < &arrA[NSIZE]; ptrA++) {
		for (ptrB = arrB; ptrB<&arrB[MSIZE]; ptrB++)
		{
			if (*ptrA == *ptrB&& *ptrA != *(ptrA - 1)) {
				*ptrC = *ptrA;
				ptrC++;
				col++;
				break;
			}
		}
	}
	
	//Вставляем разделитель
	{
		*ptrC = 111;
		ptrC++;
		col++;
	}
	for (ptrA = arrA; ptrA < &arrA[NSIZE]; ptrA++) {
		int flag = 0;
		for (ptrB = arrB; ptrB<&arrB[MSIZE]; ptrB++)
		{
			if (*ptrA == *ptrB) flag++;
		}
		if (flag < 1 && *ptrA != *(ptrA + 1)) {
			*ptrC = *ptrA;
			ptrC++;
			col++;
		}
	}
	cout << endl << "Итоговый массив C[]" << endl;
	printArr(arrC, col);
	system("pause");
}


void randArr(int a[], int sizeArr) {

	int *ptr;
	ptr = a;
	for (int i = 0; i<sizeArr; i++, ptr++)
		*ptr = rand() % 21 - 10;
}
void printArr(int a[], int sizeArr) {
	int *ptr;
	ptr = a;
	for (int i = 0; i < sizeArr; i++, ptr++)
		cout << *ptr << " ";
	cout << endl;
}
void sortArr(int a[], int sizeArr) {
	bool flag = true;
	int k = sizeArr - 1;
	while (k > 0 && flag)// к - левая граница подмассива
	{
		int endI = -1;
		flag = false;
		for (int i = 0; i < k; i++)
			if (a[i] > a[i + 1]) {
				//Находим максимальный элемент в части массива от k до SIZE 
				int tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
				flag = true;
				endI = i;
			}
		k = endI;
	}
}
