#include<stdio.h>
#include<stdlib.h>

void Heapify(int i, int n, int *arr);
void BuildHeap(int n, int *arr);
void HeapSort (int n, int *arr);

int main (void)
{
	int *array, n, i;
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
	fscanf(fin, "%d", &n);
	array = (int*)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		fscanf(fin, "%d", array+i);
	}
	HeapSort(n, array);
	for (i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	
	free(array);
}

void HeapSort(int n, int *arr)
{
	int i, helper;
	BuildHeap(n, arr);
	i = n-1;
	for (; i > 0; i--)
	{
		helper = arr[0];
		arr[0] = arr[i];
		arr[i] = helper;
		Heapify (0, i, arr);
	}
}

void BuildHeap(int n, int *arr)
{
	int i;
	i = n/2 - 1;
	for (; i >=0; i--) Heapify(i, n, arr);
}

void Heapify (int i, int n, int *arr)
{
	int left, right, j, helper;
	while (1)
	{
		left = 2*i + 1;
		right = left + 1;
		j = i;
		if ((left < n) && (arr[i] < arr[left])) i = left;
		if ((right < n) && (arr[i] < arr[right])) i = right;
		if (i == j) break;
		helper = arr[i];
		arr[i] = arr[j];
		arr[j] = helper;
	}
}