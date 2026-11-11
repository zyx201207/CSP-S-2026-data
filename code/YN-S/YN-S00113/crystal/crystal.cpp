#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a[500010];
long long b[500010];
long long ans, maxn = 1e18;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long l = -1e12, r = 1e12;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = min(a[i], l);
		r = max(a[i], r);
	}
	sort(a + 1, a + 1 + n);
	if (l == r) {
		cout << n;
		return 0;
	}
	while (l < r) {
		long long w = 0;
		double mid = (l + r) * 1.0 / 2;
		for (int i = 1; i <= n; i++) {
			if (a[i] <= mid)
				w += mid - a[i];
			else
				break;
		}
		if (w > m)
			r = mid;
		else
			l = mid + 1;
	}
	for (int i = 1; i <= n; i++) {
		if (l - a[i] - 1 < 0)
			b[i] = maxn;
		else
			b[i] = l - a[i] - 1;
	}
	sort(b + 1, b + 1 + n);
	int i = 0;
	while (m >= 0) {
		i++;
		if (m - b[i] >= 0) {
			m -= b[i];
			ans++;
		} else
			m = -1;
	}
	cout << ans;
	return 0;
}