// ConsoleApplication23.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#pragma warning(disable: 4996)
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");

	FILE *fp;
	char A1[16];
	scanf("%s", A1);
	long double A[20][5] = { {0},{0},{0} };
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 5; j++)
			A[i][j] = 10 * i + j;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << i << "." << j << ") " <<  A[i][j] << "\t\t";
		}
		cout << "\n\n";
	}
	fp = fopen(A1, "wt");
	if (fp == NULL)
	{
		cout << "Error!";
		exit(0);
	}

	for (int i = 0; i < 20; i++)
	{
		fprintf(fp, "\n %2d)", i + 1);
		for (int j = 0; j < 5; j++)
		{
			fprintf(fp, " %3.0Lf", A[i][j]);
		}
	}
	fclose(fp);

	char A2[16];
	scanf("%s", A2);
	fp = fopen(A2, "wb");
	if (fp == NULL)
	{
		cout << "Error!";
		exit(0);
	}


	fwrite(&A, sizeof(double), 100, fp);	
	fclose(fp);
	fp = fopen(A2, "rb");
	fread(&A, sizeof(double), 100, fp);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << i << "." << j << ") " << A[i][j] << "\t\t";
		}
		cout << "\n\n";
	}
	fclose(fp);

    return 0;
}

