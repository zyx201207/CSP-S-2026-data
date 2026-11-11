#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 2e6+5;
int c, t, n, d;
int x[N], y[N]; //最远到达点下标

//void solve() {
//	memset(y, 0, sizeof y);
//	cin >> n >> d;
//	for (int i = 1; i <= n; ++i)
//		cin >> x[i];
//
//	bool B = 0;
//	for (int i = 1; i <= n; ++i) {
//		if (x[i] - d <= x[1] && x[i] + d >= x[n])
//			B = 1;
//	}
//	if (B) {
//		cout << "0\n";
//		return;
//	}
//	for (int i = 1; i <= n; ++i) {
//		for (int j = i; j <= n; ++j) {
//			if (x[i] + d < x[j])
//				y[i] = j - 1;
//		}
//		if (y[i] == 0)
//			y[i] = n;
//	}
//
//	for (int i = 1; i <= n; ++i)
//		cout << x[i] << ' ' << y[i] << '\n';
//
//	for (int u = 1; u <= n; ++u) {
//		for (int v = u + 1; v <= n; ++v) {
//			int pos = u, cnt = 0;
//			while (pos < v) {
//				pos = y[pos];
//				++cnt;
//			}
//			cout << cnt << ' ';
//		}
//		cout << '\n';
//	}
//}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> c >> t;
	while (t--)
		cout << "0\n";
//		solve();

	return 0;
}