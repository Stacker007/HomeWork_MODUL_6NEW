/*
2. Дан отсортированный по возрастанию массив целых чисел, элементы
которого не повторяются (заполнить случайными числами от 0 до 50, а затем
отсортировать). Запросить у пользователя значение элемента. Если такой элемент
имеется в массиве, то удалить его (сдвинуть влево оставшуюся часть массива). Если
такого элемента нет, то вывести сообщение. Использовать указатели для
продвижения по массиву.
*/

#include <iostream>
#include <ctime>
#define SIZE 20
using namespace std;
void randArr(int *a, int sizeArr);
void printArr(int *a, int sizeArr);
void sortArr(int a[], int sizeArr);
int unRepeat(int *a, int sizeArr);
void aloneShiftArr(int *a, int sizeArr, int *alone);

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arrA[SIZE];
	int realSize = SIZE;
	int num;
	//Генерация отсортированного по возрастанию массива целых чисел, элементы
	//которого не повторяются  А[n]:

	{
		randArr(arrA, SIZE);
		sortArr(arrA, SIZE);
		realSize = unRepeat(arrA, SIZE);
		cout << "Сортированный массив А[n]:" << endl;
		printArr(arrA, realSize);
	}
	bool flag = false;
	int *ptrA;

	do {
		ptrA = arrA;
		cout << "Введите значение числа, которое хотите удалить" << endl;
		cin >> num;

		for (; ptrA< arrA + realSize; ptrA++)
			if (*ptrA == num) {
				flag = true;
				break;
			}
		if (!flag) cout << "такого числа нет в массиве!" << endl;
	} while (!flag);
	aloneShiftArr(arrA, realSize, ptrA);
	cout << "Получился массив:" << endl;
	printArr(arrA, realSize - 1);
	system("pause");

}


void randArr(int *a, int sizeArr) {	
	for (int i = 0; i<sizeArr; i++, a++)
		*a = rand() % 51;
}
void printArr(int *a, int sizeArr) {	
	for (int i = 0; i < sizeArr; i++, a++)
		cout << *a << " ";
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
int unRepeat(int *a, int sizeArr) {
	int *ptr;
	int nSize = sizeArr;
	ptr = a;
	for (int i = 0; i < sizeArr; i++, ptr++) {
		if (*ptr == *(ptr + 1) && ptr < a + nSize - 1)
		{
			aloneShiftArr(a, nSize, ptr);
			nSize--;
			i--;
			ptr--;
		}
	}

	return nSize;
}

void aloneShiftArr(int *a, int sizeArr, int *alone) {
	for (; alone < a + sizeArr - 1; alone++)
		*alone = *(alone + 1);
	*alone = 0;

}
