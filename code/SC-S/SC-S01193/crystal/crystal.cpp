#include<stdio.h>
#include<algorithm>
#ifndef stdin
#define stdin (__acrt_iob_func(0))
#endif
#ifndef stdout
#define stdout (__acrt_iob_func(1))
#endif
#define N 500005
long long n, m, a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	std::sort(a + 1, a + 1 + n);
	long long cost = 0ll, now = 0ll, ans;
	for (long long i = 1; i <= n; i++) {
		cost = cost + (a[i] - now) * (i - 1);
		now = a[i];
		if (cost > m) {
			ans = i - 1;
			break;
		}
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}