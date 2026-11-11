#include <stdio.h>
#ifndef __abs
	#define __abs(x) ((x) > 0 ? (x) : -(x))
#endif

long long a[500000];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n;
	long long m, x, ans = n;
	scanf("%d%lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", a+i);
		if (i && a[i]-a[i-1] != a[1]-a[0]) {
			printf("%d", n);
			return 0;
		}
	}
	x = __abs(a[1]-a[0]);
	for (long long i = 1, s = 0; i <= n; i++) {
		s += i;
		if (s*x > m) {
			ans = i;
			break;
		}
	}
	printf("%d", ans);
	return 0;
}

