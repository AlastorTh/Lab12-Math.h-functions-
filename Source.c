#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.14159265


int countN(double x)
{

	double eps = 0.000001; 
	double curr = 0; 
	double comp = x; 
	int N = 1;
	double sin_val;
	sin_val = sin(x);

	if (errno != 0) 
	{
		perror("Error calculating sin value");
		return -1;
	}

	while ((fabs(curr - sin_val) > eps)) 
	{
		N++;
		curr += comp;
		comp = -((comp * x * x)) / ((2. * N - 1) * (2. * N - 2)); 

	}


	return N;
}



int main()
{
	system("color F0");
	setlocale(LC_ALL, "Rus");
	float x = 0;
	printf("%s", "введите число x\n");
	scanf_s("%f", &x);
	int count_num = countN(x);
	if (count_num == -1) 
	{
		return -2;
	}
	printf("%s%d%s", "для вычисления значений синуса понадобилось ", count_num, " элементов\n");


	printf("\n\n\n\n");
	
	int M = 4;
	float A = 3;
	float step = 0.1;
	int Num = A / step + 1; 
	float i = 0;
	int j = 0;
	
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