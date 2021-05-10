#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }

void fix(int *h, int n, int x)
{
	int p = (x - 1)/2, l = 2*x + 1, r = 2*x + 2, y = x;
	if (x != 0 && h[x] > h[p]) y = p;
	else if (l < n && h[l] > h[x] && (r >= n || h[l] > h[r])) y = l;
	else if (r < n && h[r] > h[x]) y = r;
	if (y != x) swap(&h[x], &h[y]), fix(h, n, y);
}

void heapsort(int *a, int n)
{
	int i;
	rep(i, n) fix(a, i + 1, i);
	rep(i, n) swap(&a[0], &a[n - 1 - i]), fix(a, n - i - 1, 0);
}

int main()
{
	srand(time(NULL));
	int i, t = 0, n = 100000;
	int a[n], b[n];
	while (1)
	{
		rep(i, n) a[i] = b[i] = rand()%99 + 1;
		heapsort(a, n);
		qsort(b, n, sizeof(a[0]), cmp);
		rep(i, n) assert(a[i] == b[i]);
		if (++t == 10) t = 0, printf("10 arrays sorted!\n");
	}
	return 0;
}
