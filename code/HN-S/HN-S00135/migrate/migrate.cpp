#include<bits/stdc++.h>
#define int long long
#define inf 1e9
using namespace std;
int n, d, ans, f, cnt, mn, x[2000005];
void dfs(int a, int b, int len) {
	if (a > b) return;
	if (a == b) {
		if (len < mn) {
			mn = len, cnt = 1;
		} else if (len == mn) cnt++;
		return;
	}
	for (int i = a + 1; i <= b; i++) {
		if (x[i] > x[a] + d) break;
		dfs(i, b, len + 1);
	}
}
void solve() {
	cin >> n >> d, f = ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		if (!f && i > 1) f = x[i] - x[i - 1];
		else if (i > 1 && f != x[i] - x[i - 1]) f = -1;
	}
//	if (f) {
//		if (d < f * 2) cout << "0\n";
//		else {
//			for (int i = 1; i <= n - 3; i++) {
//				ans += ((n - 4) / 2);
//			}
//			cout << ans << "\n";
//		}
//	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				cnt = 0, mn = inf, dfs(i, j, 0);
				if (cnt == 2) ans++;
			}
		}
		cout << ans << "\n";
//	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int T = 1, c;
	cin >> c >> T;
	while (T--) solve();
	return 0;
}

