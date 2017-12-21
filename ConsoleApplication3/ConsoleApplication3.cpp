// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#pragma warning (disable: 4996)

using namespace std;

void F_Init(int[][10], int*, int*);
int F_Osn(int[][10], int, int);
void F_Display(int[][10], int, int, int);
void In_File(int[][10], int, int, int);
void Out_File(int[][10], int, int, int);
void In_File_Block(int[][10], int, int, int);
void Out_File_Block(int[][10], int, int, int);
int main()
{
	setlocale(LC_ALL, "rus");
	int A[10][10], a,b, sum;
	F_Init(A, &a, &b);
	sum = F_Osn(A, a, b);
	F_Display(A, a, b, sum);
	In_File(A, a, b, sum);
	Out_File(A, a, b, sum);
	In_File_Block(A, a, b, sum);
	Out_File_Block(A, a, b, sum);
	F_Display(A, a, b, sum);

    return 0;
}

void F_Init(int A[10][10], int *a, int *b)
{
	do
	{
		cout << "Введите количество строк массива(не больше 10): ";
		cin >> *a;		
		cout << "Введите количество столбцов массива(не больше 10): ";
		cin >> *b;
		if ((*a > 10) || *b > 10)
		{
			if (*a > 10 || *a <= 0)
				cout << "Неверно введено количество строк." << endl;
			else 
				if (*b > 10 || *b <= 0)
					cout << "Неверно введено количество столбцов." << endl;
		}
	} while (*a > 10 || *b > 10);

	cout << "Вводите элементы массива:" << endl;
	for (int i = 0; i < *a; i++)
	{
		for (int j = 0; j < *b; j++)
			cin >> A[i][j];
	}
}

int F_Osn(int A[10][10], int a, int b)
{
	int sum = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			sum += A[i][j];
	}
	return sum;
}

void F_Display(int A[10][10], int a, int b, int sum)
{
	cout << "Массив: " << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	cout << "Сумма элементов массива: " << sum << endl;
}

void In_File(int A[10][10], int a, int b, int sum)
{
	FILE *fp;
	fp = fopen("file1.txt", "wt");
	if (fp == NULL)
	{
		cout << "Error";
		exit(0);
	}
	for (int i = 0; i < a; i++)
	{		
		for (int j = 0; j < b; j++)
		{
			fprintf(fp, "%3d", A[i][j]);
		}

	}
	fprintf(fp, " %d", sum);

	fclose(fp);
}

void Out_File(int A[10][10], int a, int b, int sum)
{
	FILE *fp;
	fp = fopen("file1.txt", "rt");
	if (fp == NULL)
	{
		cout << "Error";
		exit(0);
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			fscanf(fp, "%d", &A[i][j]);
	}	
	fscanf(fp, "%d", &sum);

	for (int i = 0; i < a; i++)
	{		
		for (int j = 0; j < b; j++)
			printf("%2d", A[i][j]);
		printf("\n");
	}
	
	printf("\nСумма: %d\n", sum);

	fclose(fp);
}

void In_File_Block(int A[10][10], int a, int b, int sum)
{
	FILE *fp;
	fp = fopen("file1.bat", "wb");
	if (fp == NULL)
	{
		cout << "Error!";
		exit(0);
	}
	
	fwrite(&A[0][0], sizeof(int), a*b, fp);		
	
	fwrite(&sum, sizeof(int), 1, fp);

	fclose(fp);
}

void Out_File_Block(int A[10][10], int a, int b, int sum)
{
	FILE *fp;
	fp = fopen("file1.bat", "rb");
	if (fp == NULL)
	{
		cout << "Error";
		exit(0);
	}

	fread(&A[0][0], sizeof(int), a*b, fp);
	fread(&sum, sizeof(int), 1, fp);

	fclose(fp);
}