#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000005], sum[1000005], ans;

bool check(long long x, long long y) {
	if (a[x] * (x - y + 1) - (sum[x] - sum[y - 1]) <= m) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		long long l = 1, r = i;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			if (check(i, mid)) {
				ans = max(ans, i - mid + 1);
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
	}
	cout << ans;
	return 0;
}