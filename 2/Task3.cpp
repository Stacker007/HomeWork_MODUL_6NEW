/*
3. Массив из 20-ти элементов заполнить случайными числами от 0 до 20.
Упорядочить элементы, стоящие на четных местах, по возрастанию, а на нечетных –
по убыванию.
*/

#include <iostream>
#include <ctime>
#define SIZE 20
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
	int *oddPtr;
	

	for (oddPtr = arrA; oddPtr < arrA + SIZE - 2; oddPtr += 2) //i-номер последнего из упорядоченных
	{
		int tmp = *(oddPtr + 2); //сохранить копию вставляемого элемента
		int *nowPtr;
		nowPtr = oddPtr;//j = i; //j- индекс элемента, после которого может быть вставка
		while (nowPtr >= arrA && *nowPtr>tmp) //пока не вышли за пределы и не найдено место
		{
			*(nowPtr + 2) = *nowPtr;// a[j + 1] = a[j]; //сдвиг элемента вправо
			nowPtr -= 2;
		}
		*(nowPtr + 2) = tmp; //вставка на место
	}
	

	for (oddPtr = arrA + 1; oddPtr < arrA + SIZE - 1; oddPtr += 2) //i-номер последнего из упорядоченных
	{
		int tmp = *(oddPtr + 2); //сохранить копию вставляемого элемента
		int *nowPtr;
		nowPtr = oddPtr;//j = i; //j- индекс элемента, после которого может быть вставка
		while (nowPtr >= arrA && *nowPtr<tmp) //пока не вышли за пределы и не найдено место
		{
			*(nowPtr + 2) = *nowPtr;// a[j + 1] = a[j]; //сдвиг элемента вправо
			nowPtr -= 2;
		}
		*(nowPtr + 2) = tmp; //вставка на место
	}

	cout << "Сортированный массив А[n]:" << endl;
	printArr(arrA, SIZE);

	system("pause");

}


void randArr(int *a, int sizeArr) {	
	for (int i = 0; i<sizeArr; i++, a++)
		*a = rand() % 21;
}
void printArr(int *a, int sizeArr) {	
	for (int i = 0; i < sizeArr; i++, a++)
		cout << *a << " ";
	cout << endl;
}

