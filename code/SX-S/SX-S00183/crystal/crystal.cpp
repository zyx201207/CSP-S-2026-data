#include <bits/stdc++.h>
using namespace std;
long long a[100];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	bool b = 1;
	scanf("%lld%lld", &n, &m);
	if (n == 1) {
		cout << 1;
		return 0;
	}
	scanf("%lld%lld", &a[1], &a[2]);
	for (long long i = 3; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	long long x = abs(a[1] - a[2]);
	for (long long i = 3; i <= n; i++) {
		if (a[i] - a[i - 1] != x)
			b = 0;
	}
	if (b == 1) {
		long long sum = 0, i;
		for (i = 1; i * x <= m ; i++) {
			sum += i * x;
			if (sum > m) {
				sum -= i * x;
				break;
			}
		}
		cout << i ;
		return 0;
	}

	long long ans = 0;
	for (long long i = 1; i <= n; i++) {
		x = 0;
		long long sum = 0;
		for (long long j = i; j >= 1; j--) {
			sum += a[i] - a[j];
			x++;
			if (sum > m) {
				x -= 1;
				break;
			}
		}
		ans = max(ans, x);
	}
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}