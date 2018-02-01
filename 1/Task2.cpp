/*
2. Дан массив целых чисел из 7 элементов (можно ввести значения элементов
или задать случайным образом). Воспользовавшись указателями, поменяйте
местами элементы массива с четными и нечетными индексами (т.е. те элементы
массива, которые стоят на четных местах, поменяйте с элементами, которые стоят
на нечетных местах).
*/

#include <iostream>
#define SIZE 7
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
	int *beginPtr;
	beginPtr = myArr;
	while (beginPtr < (myArr + SIZE-1))
	{
		int tmp = *beginPtr;
		*beginPtr = *(beginPtr + 1);
		*(beginPtr + 1) = tmp;
		beginPtr += 2;
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
