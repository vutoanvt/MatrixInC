#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//hàm cấp phát vùng nhớ động mảng 2 chiều
void Malloc(int** &a, int row, int col)
{
	a = (int **)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++)
		a[i] = (int*)malloc(col * sizeof(int*));
}

//hàm xóa vùng nhớ đã cấp phát
void Del(int** &a, int row, int col)
{
	for (int i = 0; i < row; i++)
		delete[] a[i];
	delete[] a;
	a = NULL;
}

void InputArr(int** a, int row, int col)
{
	for (int i = 0; i < row*col; i++)
	{
		printf("\na[%d][%d]: ", i / col, i%col);
		scanf_s("%d", &a[i / col][i%col]);
	}
}

void OutPutArr(int** a, int row, int col)
{
	for (int i = 0; i < row*col; i++)
	{
		printf("%6d", a[i / col][i%col]);
		if ((i + 1) % col == 0)
			printf("\n");
	}
}

int** x2Matrix(int** a, int** b, int m, int n, int p)
{
	int row, col, el;
	int sum = 0;
	int **c = NULL;
	c = (int**)malloc(m * sizeof(int*));

	for (row = 0; row < m; row++)
		c[row] = (int*)malloc(p * sizeof(int*));

	for (row = 0; row < m; row++)
	{
		for (col = 0; col < p; col++)
		{			
			for (el = 0; el < n; el++)
				sum += a[row][el] * b[el][col];
			c[row][col] = sum;
			sum = 0;
		}
	}
	return c;
}

void main()
{
	int **a = NULL;
	int **b = NULL;
	int **c = NULL;
	int m, n, p;
	do
	{
		printf("\nInsert row a:"); scanf_s("%d", &m);
		printf("\nInsert col a & row b:"); scanf_s("%d", &n);
		printf("\nInsert col b:"); scanf_s("%d", &p);
	} while (m <= 0 || n <= 0 || p <= 0);
	
	Malloc(a, m, n);
	Malloc(b, n, p);
	//Malloc(c, i, j);

	InputArr(a, m, n);
	InputArr(b, n, p);

	printf("\nPrint matrix a: \n");
	OutPutArr(a, m, n);

	printf("\nPrint matrix b: \n");
	OutPutArr(b, n, p);

	c = (int**)x2Matrix(a, b, m, n, p);
	printf("\nResult of multiplication 2 matrix: \n");
	OutPutArr(c, m, p);

	Del(a, m, n);
	Del(b, n, p);
	Del(c, m, p);
	_getch();
}