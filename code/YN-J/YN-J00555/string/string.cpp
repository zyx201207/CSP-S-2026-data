#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
long long n, l = 0, a[300000], s = 0;
char c[300000], px[300000], p[300000];

int main(void) {
//	freopen("travel.in", "r", stdin);
//	freopen("travel.out", "w", stdout);
	scanf("%lld", &n);
	for (long long i = 1; i <= n; ++i) {
		scanf("%lld %c", &a[i], &c[i]);
		l += a[i];
	}
	long long j = 1;
	for (long long i = 1; i <= l; ++i) {
		if (i > a[j + 1]) {
			++j;
		}
		p[i] = c[a[j]];
		if (i <= n / 2) {
			px[n - i + 1] = a[i];
		}
	}

	for (int i = n / 2 + 1; i <= l; ++i) {
		if (p[i] != px[i]) {
			p[i] = px[i];
			++s;
		}
	}
	printf("%lld", s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}