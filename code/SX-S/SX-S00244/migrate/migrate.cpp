#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010], l[2000010], r[2000010];

void solve() {
	memset(l, 0, sizeof l);
	memset(r, 0, sizeof r);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	l[2] = 1;
	for (int i = 2; i < n; i++) {
		if (a[i] - a[i - 1] <= d and a[i + 1] - a[i] <= d and a[i + 1] - a[i - 1] > d)
			l[i + 1] = l[i] + 1;
	}
//	if(a[n] - a[n - 1] <= d and a[n] - a[n - 2] > d) l[n] = l[n - 1]
	r[n - 1] = 1;
	for (int i = n - 1; i >= 2; i--) {
		if (a[i] - a[i - 1] <= d and a[i + 1] - a[i] <= d and a[i + 1] - a[i - 1] > d)
			r[i - 1] = r[i] + 1;
	}

	for (int i = 1; i <= n; i++)
		cout << l[i] << ' ' << r[i] << '\n';
	int ans = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = u + 3; v <= n; v++) {
			int cnt = 0;
			for (int u1 = u + 1; u1 < v; u1++) {
				for (int u2 = u1 + 1; u2 < v; u2++) {
					if (u2 - u <= d and v - u > d and u1 - u <= d and v <= u2 + d) {
						cnt++;
						cout << u << ' ' << v << ' ' << u1 << ' ' << u2 << '\n';
					}
				}
			}
			ans += cnt == 1 ? (l[u] + 1) * (r[v] + 1) : 0;
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T--) {
		solve();
	}
	return 0;
}
