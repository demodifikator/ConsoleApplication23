// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void F_Init(int[], int*);
int F_Osn(int[], int);
void F_Display(int[], int, int);
int main()
{
	setlocale(LC_ALL, "rus");
	int A[100], a, sum;
	F_Init(A, &a);
	sum = F_Osn(A, a);
	F_Display(A, a, sum);

    return 0;
}


void F_Init(int A[], int *a)
{
	int i;
	cout << "Вводите числа. Для окончания ввода введите 0.";
	for (i = 0; i < 100; i++)
	{
		cin >> A[i];
		if (A[i] == 0)
		{
			*a = i;
			break;
		}
	}
	
}
int F_Osn(int A[], int a)
{
	int sum = 0;
	for (int i = 0; i < a; i++)
		sum += A[i];
	return sum;
}

void F_Display(int A[], int r, int sum)
{
	for (int i = 0; i < r; i++)
		cout << A[i] << " ";
	cout << endl;
	cout << "Сумма элементов массива: " << sum << endl;
}

