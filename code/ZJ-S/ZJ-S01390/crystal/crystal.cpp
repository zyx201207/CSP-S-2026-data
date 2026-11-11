#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long a[500005];
long long sum[500005];
bool check(long long x) {
	long long cnt = 0;
	for (int i = 1; i <= n - x + 1; i++) {
		cnt = 0;
		cnt += a[i + x - 1] * x - (sum[i + x - 1] - sum[i - 1]);
		if (cnt <= m) {
			return 1;
		}
	}
	return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	stable_sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	long long l = 1, r = n;
	long long ans = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
