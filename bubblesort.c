#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }

void bubblesort(int *a, int n)
{
	int i, b = 1;
	while (b)
	{
		b = 0;
		rep(i, n - 1) if (a[i] > a[i + 1]) b = 1, swap(&a[i], &a[i + 1]);
	}
}

int main()
{
	srand(time(NULL));
	int i, t = 0, n = 1000;
	int a[n], b[n];
	while (1)
	{
		rep(i, n) a[i] = b[i] = rand()%99 + 1;
		bubblesort(a, n);
		qsort(b, n, sizeof(a[0]), cmp);
		rep(i, n) assert(a[i] == b[i]);
		if (++t == 10) t = 0, printf("10 arrays sorted!\n");
	}
	return 0;
}
