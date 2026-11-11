#include <bits/stdc++.h>
using namespace std;
long long a[500005], ans = 0, n, m, sum = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (long long l = 1, r = 2; r <= n; r++) {
		sum += (r - l) * (a[r] - a[r - 1]);
		if (sum > m) {
			sum -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	printf("%lld", ans);
	return 0;
}
