#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;
int n;
long long a[N], d;

namespace sub6 {
	const int N = 300 + 10;
	int f[N][N], g[N][N];
	void solve() {
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				f[i][j] = 1e9, g[i][j] = 0;
		for (int i = n;i >= 1;i--) {
			f[i][i] = 0, g[i][i] = 1;
			for (int j = i;j <= n;j++)
				for (int k = i - 1;k >= 1;k--) {
					if (a[i] - a[k] > d) break;
					if (f[k][j] > f[i][j] + 1) f[k][j] = f[i][j] + 1, g[k][j] = g[i][j];
					else if (f[k][j] == f[i][j] + 1) g[k][j] += g[i][j];
				}
		}
		int ans = 0;
		for (int i = 1;i <= n;i++)
			for (int j = i + 1;j <= n;j++) if (g[i][j] == 2)
				ans++;
		cout << ans << "\n";
	}
}
namespace sub12 {
	void solve() {
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		int m = 1;
		while (m <= n && a[m] - a[1] <= d) m++;
		m -= 2;
		if (n == 1 || m <= 1) { cout << 0 << "\n"; return ; }
		cout << max(0, n - 2 * m + 1) << "\n";
	}
}
namespace sub14 {
	void solve() {
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
			cin >> a[i];
		int cnt = 0;
		for (int i = 1;i <= n;i++)
			cnt += (abs(a[i] - a[1]) <= d && abs(a[i] - a[n]) <= d);
		long long ans = 0;
		if (cnt == 2) ans = 1ll * n * (n - 1) / 2;
		cout << ans << "\n";
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int sid, T; cin >> sid >> T;
	while (T--) {
		if (sid <= 6) sub6::solve();
		if (sid == 11 || sid == 12) sub12::solve();
		if (sid == 13 || sid == 14) sub14::solve();
	}

	return 0;
}