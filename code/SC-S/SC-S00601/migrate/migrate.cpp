#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int c, T, n, d, x[N];
int lgt[N];
inline bool check(int u, int v) {
	int cnt = 0;
	for (int i = u + 1; i < v; ++i) {
		if (x[i] - x[u] <= d && x[v] - x[i] <= d) {
			++cnt;
		}
	} return (cnt == 2);
}
inline void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i)	cin >> x[i];
	if (n == 1 || n == 2) {
		cout << "0\n";
		return ;
	}
	if (c == 11 || c == 12) {
		int diff = x[2] - x[1];
		int Max = d / diff;
		if (Max == 0) {
			cout << "0\n";
			return ;
		}
		if (Max == 1) {
			cout << "0\n";
			return ;
		}
		cout << max(0ll, n - Max - Max + 1) << '\n';
		return ;
	}
	if (c == 13 || c == 14) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (x[i] - x[1] <= d && x[n] - x[i] <= d)	++cnt;
		}
		if (cnt > 2) {
			cout << "0\n";
			return ;
		}
		int ans = 0;
		int pos = 0;
		for (int i = 1; i <= n; ++i) {
			if (x[i] - x[1] <= d && x[n] - x[i] <= d) {
				pos = i;
				break;
			}
		}
		if (pos == 1 || pos == n) {
			cout << "0\n";
			return ;
		}
		for (int i = 1, j = 1; i <= n; ++i) {
			j = max(j, i);
			while (x[j + 1] - x[i] <= d && j < n)	++j;
			lgt[i] = j;
		}
		if (cnt == 2) {
			// pos, pos + 1
			int cur = lgt[pos - 1];
			for (int i = 1; i < pos; ++i) {
				if (x[pos + 2] - x[i] <= d)	continue;
				ans += n - cur;
			}
		} else {
			// pos
			int cur = lgt[pos - 1];
			for (int i = 1; i < pos; ++i) {
				if (x[pos + 1] - x[i] <= d) {
					ans += n - cur;
				} else {
					ans += cur - pos;
				}
			}
		} cout << ans << '\n';
		return ;
	}
	for (int i = 1, j = 1; i <= n; ++i) {
		j = max(j, i);
		while (x[j + 1] - x[i] <= d && j < n)	++j;
		lgt[i] = j;
	}
	int ans = 0;
	for (int u = 1; u <= n; ++u) {
		for (int v = lgt[u] + 1; v <= n; ++v) {
			if (check(u, v)) {
				++ans;
			}
		}
	} cout << ans << '\n';
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T--)	solve();
	return 0;
}
/*
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/