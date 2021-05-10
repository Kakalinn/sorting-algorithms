#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }

void insertionsort(int *a, int n)
{
	int i, j;
	rep(i, n) rep(j, i)
		if (a[i - j] < a[i - 1 - j]) swap(&a[i - j], &a[i - 1 - j]);
		else break;
}

int main()
{
	srand(time(NULL));
	int i, n = 10000, t = 0;
	int a[n], b[n];
	while (1)
	{
		rep(i, n) a[i] = b[i] = rand()%99 + 1;
		insertionsort(a, n);
		qsort(b, n, sizeof(a[0]), cmp);
		rep(i, n) assert(a[i] == b[i]);
		if (++t == 10) t = 0, printf("10 arrays sorted!\n");
	}
	return 0;
}
