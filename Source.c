#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.14159265


int countN(double x)
{

	double eps = 0.000001; //погрешность
	double curr = 0; //текущее значение суммы
	double comp = x; //текущий элемент суммировани¤
	int N = 1;
	double sin_val;
	sin_val = sin(x);

	if (errno != 0) 
	{
		perror("Error calculating sin value");
		return -1;
	}

	while ((fabs(curr - sin_val) > eps)) // замена вычислени¤ sin каждый раз в цикле на его вычисление перед началом
	{
		N++;
		curr += comp;
		comp = -((comp * x * x)) / ((2. * N - 1) * (2. * N - 2)); // замена на числа с плавающей точкой дл¤ избежани¤ переполнени¤

	}


	return N;
}



int main()
{

	setlocale(LC_ALL, "Rus");
	float x = 0;
	printf("%s", "¬ведите число x\n");
	scanf_s("%f", &x);
	int count_num = countN(x);
	if (count_num == -1) 
	{
		return -2;
	}
	printf("%s%d%s", "ƒл¤ вычислени¤ значени¤ синуса понадобилось ", count_num, " элементов\n");


	printf("\n\n\n\n");
	int k = 0;
	int M = 4;
	float A = 3;
	float step = 0.1;
	int Num = A / step + 1; //количество элементов в таблице
	float i = 0;
	int j = 0;
	for (k = 0; k < Num / M + 1; k++) {
		printf("%s", " x sin(x) ");
	}
	printf("\n");
	for (i = 0; i < A; i += 0.1) 
	{
		j++;
		printf("%s%.1f%s%f%s", "|", i, " - ", sin(i), "|");
		if (j % (30 / M + 1) == 0) 
		{
			printf("\n");
		}


	}

	printf("\n");
	return 0;
}