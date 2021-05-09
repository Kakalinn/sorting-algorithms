#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
int cmp(const void* p1, const void* p2) { return *(int*)p1 - *(int*)p2; }

void quicksort(int *a, int n)
{
	int s[n][2], ss = 0, l, r, i, j, k;
	s[ss][0] = 0, s[ss][1] = n, ss++;
	while (ss > 0)
	{
		ss--;
		if (s[ss][1] - s[ss][0] < 2) continue;
		i = j = l = s[ss][0], k = r = s[ss][1];
		while (j < k)
		{
			if (a[j] == a[i]) j++;
			else if (a[j] > a[i]) swap(&a[j], &a[--k]);
			else swap(&a[i++], &a[j++]);
		}
		s[ss][0] = l, s[ss][1] = i, ss++;
		s[ss][0] = j, s[ss][1] = r, ss++;
	}
}

int main()
{
	srand(time(NULL));
	int i, t = 0, n = 100000;
	int a[n], b[n];
	rep(i, n) a[i] = rand()%9 + 1;
#if 1
	while (1)
	{
		rep(i, n) a[i] = b[i] = rand()%99 + 1;
		quicksort(a, n);
		qsort(b, n, sizeof(a[0]), cmp);
		rep(i, n) assert(a[i] == b[i]);
		if (++t == 10) t = 0, printf("10 arrays sorted!\n");
	}
#endif
	return 0;
}
