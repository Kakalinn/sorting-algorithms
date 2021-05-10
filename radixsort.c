#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }

#ifndef BASE
#define BASE 10000
#endif
void radixsort(int *a, int n)
{
	int i, j, e, t, b[2][n], c[BASE], d[BASE], mx = 0;
	rep(i, n) mx = mx < a[i] ? a[i] : mx;
	rep(i, n) b[0][i] = a[i];
	for (e = 1; e <= mx; e *= BASE, t = 1 - t)
	{
		rep(i, BASE) c[i] = d[i] = 0;
		rep(i, n) c[(b[t][i]/e)%BASE]++;
		rep(i, BASE) if (i != 0) c[i] += c[i - 1];
		rep(i, n) b[1 - t][--c[(b[t][n - 1 - i]/e)%BASE]] = b[t][n - 1 - i];
	}
	rep(i, n) a[i] = b[t][i];
}

int main()
{
	srand(time(NULL));
	int i, t = 0, n = 100000;
	int a[n], b[n];
	while (1)
	{
		rep(i, n) a[i] = b[i] = rand()%100000000;
		a[n - 1] = b[n - 1] = 0;
		a[0] = b[0] = 100000000;
		radixsort(a, n);
		qsort(b, n, sizeof(a[0]), cmp);
		rep(i, n) assert(a[i] == b[i]);
		if (++t == 10) t = 0, printf("10 arrays sorted!\n");
	}
	return 0;
}
