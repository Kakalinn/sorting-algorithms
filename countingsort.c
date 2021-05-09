#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }

void countingsort(int *a, int n)
{
	int i, j = 0, mx = 1;
	rep(i, n) mx = mx - 1 < a[i] ? a[i] + 1 : mx;
	int c[mx];
	rep(i, mx) c[i] = 0;
	rep(i, n) c[a[i]]++;
	rep(i, mx) while (c[i]-- > 0) a[j++] = i;
}

int main()
{
	srand(time(NULL));
	int i, n = 100000;
	int a[n], b[n];
	while (1)
	{
		rep(i, n) a[i] = b[i] = rand()%99 + 1;
		countingsort(a, n);
		qsort(b, n, sizeof(a[0]), cmp);
		rep(i, n) assert(a[i] == b[i]);
	}
	return 0;
}
