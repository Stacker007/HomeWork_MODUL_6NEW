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
	//int arrD[MSIZE];
    
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

	int *ptrA, *ptrB, *ptrC;/*, *ptrD;*/
	ptrA = arrA;
	ptrB = arrB;
	ptrC = arrC;
	int colGeneral = 0;
	while (ptrA < (arrA + NSIZE))
	{
		bool flag = true;
		int *tmpptr = arrC;
//Проход по массиву С (если в массиве С есть A[i], то выходим без проверки элементов В)
		while (colGeneral && tmpptr < (arrC + colGeneral))
		{
			if (*tmpptr == *ptrA) {
				flag = false;
				//break;
			}
			tmpptr++;
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

/*
	ptrA = arrA;
	ptrB = arrB;
	ptrD = arrD;
	int different = 0;
	while (ptrA < arrA + NSIZE)
	{
		bool flag = true;
		int *tmpptr = arrD;
		while (tmpptr < arrD + NSIZE)
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
				flag = false;
				break;
			}
			ptrB++;
		}
		if (flag) {
			*ptrD++ = *ptrA;
			different = 0;
		}
		ptrA++;
	}
	if (different) {
		cout << endl << "Массив различных значений D[]" << endl;
		printArr(arrD, different);
	}
	else cout << endl << "Различных значений нет!" << endl;

	*/
	
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

