#include <stdio.h>

int main (void)
{
	int N = 0;
    double x, M = 0, D = 0;
    char filename[256];
    FILE *fin;
	printf("input filename ->");
	scanf("%s", filename);
	fin = fopen (filename, "r");
	if (fin == NULL)
	{
		printf("Unable to open the file");
		return -1;
	}
	while (fscanf(fin, "%lf", &x) != EOF)
	{
		M += x;
		D += x*x;
		N++;
	}
	M /= N;
	D = D / N - M*M;
	if (D == 0) printf("This file is empty");
	else printf("%lf\n", D);
	return 0;
}