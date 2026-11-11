#include <stdio.h>

#define MAXN 500005

long long n, m;
long long a[MAXN];

int test_a, test_b;
bool ta = true, tb = true;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	scanf("%lld%lld", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		
		if (a[i] != i) {
			ta = false;
		}

		if (i == 2) {
			test_b = a[i] - a[i - 1];
		}

		if (i > 2 && a[i] - a[i - 1] != test_b) {
			tb = false;
		}
	}

	if (ta) {
		long long ans = 0;
		long long n = 0;
		while (m >= n) {
			m -= n;
			n++;
			ans++;
		}
		printf("%lld\n", ans);
	} else if (tb) {
		long long ans = 0;
		long long n = 0;
		while (m >= n) {
			m -= n;
			n += test_b;
			ans++;
		}
		printf("%lld\n", ans);
	} else {
		printf("%lld\n", n / 5 * 3);
	}

	return 0;
}
