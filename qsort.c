#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#ifndef MAXN
#define MAXN 1000000
#endif
int a[MAXN];
int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }

int main(int argc, char** argv)
{
	int i;
	assert(argc > 1);
	srand(atoi(argv[1]));
	rep(i, MAXN) a[i] = rand();
	qsort(a, MAXN, sizeof(a[0]), cmp);
	//rep(i, MAXN - 1) assert(a[i] <= a[i + 1]);
	return 0;
}
