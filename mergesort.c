#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }
int min(int a, int b) { return a < b ? a : b; }

void mergesort(int *a, int n)
{
	int t = 0, i, j, c, s, e, b[2][n], l, m, r;
	rep(i, n) b[0][i] = a[i];
	for (e = 1; e <= n; e *= 2, t = 1 - t)
	{
		for (l = 0; l < n; l += 2*e)
		{
			i = c = l, j = m = min(l + e, n), r = min(l + 2*e, n);
			while (i < m && j < r)
			{
				if (b[t][j] < b[t][i]) b[1 - t][c++] = b[t][j++];
				else b[1 - t][c++] = b[t][i++];
			}
			while (i < m) b[1 - t][c++] = b[t][i++];
			while (j < r) b[1 - t][c++] = b[t][j++];
		}
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
		n = rand()%100001;
		rep(i, n) a[i] = b[i] = rand()%99 + 1;
		mergesort(a, n);
		qsort(b, n, sizeof(a[0]), cmp);
		rep(i, n) assert(a[i] == b[i]);
		if (++t == 10) t = 0, printf("10 arrays sorted!\n");
	}
	return 0;
}
