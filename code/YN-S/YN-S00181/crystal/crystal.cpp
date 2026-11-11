#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long minn = 1e18 + 5, maxn = -1e18 - 5, n, m, a[N], s[N], ans;

bool check(long long w) {
	for (long long i = w; i <= n; i++) {
		long long cnt = s[i] - s[i - w - 1];
		if (abs(a[i]*w - cnt) <= m) {
			return 1;
		}
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		minn = min(minn, a[i]);
		maxn = max(maxn, a[i]);
	}
	sort(a + 1, a + n + 1);
	for (long long i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	long long l = 1, r = n;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}