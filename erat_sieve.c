#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_prime(int x, int *a) {
  int count_dividers = 0;
  for (int i = 0; a[i] <= sqrt(x); i++){
    if (x % a[i] == 0) return 1;
  }
  return 0;
}


unsigned int Erats_sieve_simple (int N) {
   int i = 2, j = 5;
   int *a;
   a = (int*)malloc(N*sizeof(int));
   a[0] = 2;
   a[1] =  3;
   for (; i < N; j+=2) {
     if (!(is_prime(j, a))) {
       a[i] = j;
       i++;
     }
   }
   return a[N-1];
}



int main () {
  int N;
  printf("Put N, please\n");
  scanf("%d", &N);
  printf("%u\n", Erats_sieve_simple(N));
  return 0;
}