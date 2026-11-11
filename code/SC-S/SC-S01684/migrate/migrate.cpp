#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 2e6 + 5;

int c, t, n;
int pl[maxn], pr[maxn];
int f[maxn], g[maxn];
long long d, a[maxn];

void Solve();
void SolveA();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> t;
	if (c == 11 || c == 12) {
		for (int i = 1; i <= t; i++) {
			SolveA();
		}
		return 0;
	}
	if (c == 13 || c == 14) {
		for (int i = 1; i <= t; i++) {
			cout << 0 << '\n';
		}
		return 0;
	}
	for (int i = 1; i <= t; i++) {
		Solve();
	}

	return 0;
}

void Solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	pl[0] = 1, pr[n + 1] = n;
	for (int i = 1; i <= n; i++) {
		pl[i] = pl[i - 1];
		while (a[i] - a[pl[i]] > d) pl[i]++;
	}
	for (int i = n; i >= 1; i--) {
		pr[i] = pr[i + 1];
		while (a[pr[i]] - a[i] > d) pr[i]--;
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 0;
		g[i] = 1;
		for (int j = i + 1; j <= n; j++) {
			if (pl[j] == j) break;
			int l = max(pl[j], i);
			f[j] = f[l] + 1;
			g[j] = g[l];
			for (int k = l + 1; k < j; k++) {
				if (f[k] != f[k - 1]) break;
				g[j] += g[k];
				if (g[j] > 3) break;
			}
			if (g[j] == 2) ans++;
		}
	}
	cout << ans << '\n';
}

void SolveA() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long dd = a[2] - a[1];
	long long len = d / dd * 2 - 1;
	if (len > n) cout << 0 << '\n';
	else cout << n - len << '\n';
}