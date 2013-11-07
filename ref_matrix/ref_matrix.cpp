// ref_matrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>

using namespace std;

void fill_m(int **matrix, const int lines, const int columns)
{
	srand(time(0));
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			matrix[i][j] = rand() % 5 + 1;
}

void print_m(int **matrix, const int lines, const int columns)
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << setw(2) << matrix[i][j];
		}
		cout << endl;
	}
}

void change(int **matrix, const int lines, const int columns, int m, int n)
{
	int *line = new int[lines];
	int *column = new int[columns];

	m--, n--;

	for (int j = 0; j < columns; j++)
		line[j] = matrix[m][j];
	for (int i = 0; i < lines; i++)
		column[i] = matrix[i][n];

	for (int j = 0; j < columns; j++)
		matrix[m][j] = column[j];
	for (int i = 0; i < lines; i++)
		matrix[i][n] = line[i];
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");

	const int lines = 5;
	const int columns = 5;

	int **matrix = new int*[lines];
	for (int i = 0; i < columns; i++)
		matrix[i] = new int[columns];

	fill_m(matrix, lines, columns);
	cout << "Матрица:\n\n";
	print_m(matrix, lines, columns);

	int m, n;

	cout << "\n\nВведите номер строки, которую хотите заменить: ";
	cin >> m;
	cout << "Введите номер столбца, на который хотите ее заменить: ";
	cin >> n;
	cout << "\n";

	change(matrix, lines, columns, m, n);
	cout << "Измененная матрица:\n\n";
	print_m(matrix, lines, columns);
	system("pause");
	return 0;
}

