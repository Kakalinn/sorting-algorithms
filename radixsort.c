#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#ifndef BASE
#define BASE 10000
#endif
#ifndef MAXN
#define MAXN 1000000
#endif

int a[MAXN], b[2][MAXN], c[BASE], d[BASE];
void radixsort(int *a, int n)
{
	int i, j, e, q = 0, t, mx = 0;
	rep(i, n) mx = mx < a[i] ? a[i] : mx;
	while (mx > 0) mx /= BASE, q++;
	rep(i, n) b[0][i] = a[i];
	for (t = 0, e = 1; q > 0; q--, e *= BASE, t = 1 - t)
	{
		rep(i, BASE) c[i] = d[i] = 0;
		rep(i, n) c[(b[t][i]/e)%BASE]++;
		rep(i, BASE) if (i != 0) c[i] += c[i - 1];
		rep(i, n) b[1 - t][--c[(b[t][n - 1 - i]/e)%BASE]] = b[t][n - 1 - i];
	}
	rep(i, n) a[i] = b[t][i];
}

int main(int argc, char** argv)
{
	int i;
	assert(argc > 1);
	srand(atoi(argv[1]));
	rep(i, MAXN) a[i] = rand();
	radixsort(a, MAXN);
	//rep(i, MAXN - 1) assert(a[i] <= a[i + 1]);
	return 0;
}
