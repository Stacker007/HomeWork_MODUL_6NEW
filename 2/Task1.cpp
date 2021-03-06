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
#define NSIZE 10
#define MSIZE 10
using namespace std;
void randArr(int *a, int sizeArr);
void printArr(int *a, int sizeArr);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arrA[NSIZE];
	int arrB[MSIZE];
	int arrC[NSIZE];
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
	
	
	int colGeneral = 0;
	while (ptrA < (arrA + NSIZE))
	{
        ptrC = arrC;
		ptrB = arrB;
		bool flag = true;
		
		//Проход по массиву С (если в массиве С есть A[i], то выходим без проверки элементов В)
		while (colGeneral && ptrC < (arrC + colGeneral))
		{
			if (*ptrC == *ptrA) {
				flag = false;
				break;
			}
			ptrC++;
		}
		//Если в массиве В встречаем элемнет равный A[i], 
		//то записываем значение в очередную ячейку С
		while (flag && ptrB < (arrB + MSIZE))
		{
			if (*ptrA == *ptrB) {
				*ptrC++ = *ptrA;
				colGeneral++;
				break;//Выход из цикла если если есть равные элементы
			}
			ptrB++;
		}
		ptrA++;//переход к следующему элементу в А
	}
	if (colGeneral) {
		cout << endl << "Массив общих значений C[]" << endl;
		printArr(arrC, colGeneral);
	}
	else cout << endl << "Общих значений нет!" << endl;

	ptrA = arrA;
	
	colGeneral = 0;
	while (ptrA < (arrA + NSIZE))
	{
		ptrD = arrD;
		ptrB = arrB;
		bool flag = true;		
		while (colGeneral && ptrD < (arrD + colGeneral)) {//Проверяем отсутствие элемента в массиве D
			if (*ptrD == *ptrA) {
				flag = false;
				break;
			}
			ptrD++;
		}
		while (flag && ptrB < (arrB + MSIZE)) {//Проверяем отсутствие элемента в массиве B
			if (*ptrB == *ptrA) {
				flag = false;
				break;
			}
			ptrB++;
		}
		if (flag) {
			*ptrD = *ptrA;
			colGeneral++;
		}
		
		ptrA++;//переход к следующему элементу в А
	}
	if (colGeneral) {
		cout << endl << "Массив отличных значений D[]" << endl;
		printArr(arrD, colGeneral);
	}
	else cout << endl << "Отличных значений нет!" << endl;
	

	system("pause");
	return 0;
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

