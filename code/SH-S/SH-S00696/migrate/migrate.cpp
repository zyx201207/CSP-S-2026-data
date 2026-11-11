#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

constexpr int N = 2e6 + 10;

int n, p[N], s[N];
i64 m, X[N], ans, f[N], g[N], x[N], y[N];

void solve() {
	cin >> n >> m, ans = 0;
	for (int i = 1, j = 1; i <= n; ++i) {
		cin >> X[i];
		while (X[i] - X[j] > m) {
			++j;
		}
		p[i] = j;
		if (p[i] < i - 1) {
			++y[p[i]];
		}
	}
	for (int i = n, j = n; i >= 1; --i) {
		while (X[j] - X[i] > m) {
			--j;
		}
		s[i] = j;
		if (s[i] > i + 1) {
			++x[s[i]];
		}
	} 
	for (int i = 1; i <= n; ++i) {
		if (s[i] == i) {
			continue;
		}
		if (p[s[i]] == i) {
			f[s[i]] += f[i];
		}
		++f[s[i]];
	}
	for (int i = n; i >= 1; --i) {
		if (p[i] == i) {
			continue;
		}
		if (s[p[i]] == i) {
			g[p[i]] += g[i];
		}
		++g[p[i]];
	}
	for (int i = 1; i <= n; ++i) {
		if (s[i] != i && s[s[i]] != s[i] && p[s[s[i]]] != s[s[i]] && p[s[s[i]]] != i && p[p[s[s[i]]]] == i && p[s[s[i]]] == s[i] - 1) {
			// cout << i << ' ' << f[i] << ' ' << g[s[s[i]]] << endl;
			ans += f[i] * g[s[s[i]]];
		}
		if (s[i] - 1 > i && p[s[i] - 1] == i) {
			ans += f[i] * y[s[i] - 1];
		}
		if (p[i] + 1 < i && s[p[i] + 1] == i) {
			ans += x[p[i] + 1] * g[i];
		}
		// cout << i << ' ' << y[i] << ' ' << x[i + 1] << endl;
		ans += y[i] * x[i + 1];
		// cout << i << ' ' << ans << endl;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; ++i) {
		f[i] = g[i] = x[i] = y[i] = 0;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}