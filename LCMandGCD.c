#include<stdio.h>

int GCD (int a, int b);
int LCM (int a, int b, int gcd);

int main (void)
{
	int a, b, gcd, lcm;
	scanf("%d %d", &a, &b);
	gcd = GCD(a, b);
	lcm = LCM(a, b, gcd);
	printf("GCD = %d\nLCM = %d\n", gcd, lcm);
}

int GCD (int a, int b)
{
	if ((a == 0) || (b == 0)) return a+b;
	if (a > b) return GCD (a % b, b);
	else return GCD (a, b % a);
}

int LCM (int a, int b, int gcd)
{
	return a*b/gcd;
}
