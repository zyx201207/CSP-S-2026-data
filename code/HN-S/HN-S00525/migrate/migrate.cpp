#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, t, n, d;
//bitset <2000006> vis1, vis2;
//
//void solve() {
//	cin >> n >> d;
//	int m = 1, ans = 0;
//	vector <int> x(n + 1), dp[2];
//	dp[0].resize(n + 1, 0);
//	dp[1].resize(n + 1, 0);
//	dp[0][1] = dp[1][1] = 1;
//	dp[0][0] = dp[1][0] = 2000005;
//	for (int i = 0; i <= n; i++) vis1[i] = vis2[i] = 0;
//	for (int i = 1; i <= n; i++) {
//		cin >> x[i];
//		while (x[i] - x[m] > d) m++;
//		dp[0][i] += dp[0][m] + dp[1][m];
//		dp[1][i] = dp[0][m + 1];
//		dp[0][1] = 1;
//		if (i == n) {
//			for (int j = m + 1; j < i - 1; j++) {
////		cout << m << ' ' << dp[0][i] << ' ' << dp[1][i] << '\n';
//				dp[0][i] += dp[0][j] + dp[1][j];
//				dp[1][i] += dp[0][j] + dp[1][j];
//				
//			}
//		}
//		if (m != 1) {
//			vis1[dp[0][m - 1]] = 1;
//			vis2[dp[1][m - 1]] = 1;
//		}
////		cout << m << ' ' << dp[0][i] << ' ' << dp[1][i] << '\n';
//		if (dp[0][i] - 1 >= 0 && dp[1][i] - 1 >= 0 && vis1[dp[0][i] - 1] && vis2[dp[1][i] - 1]) ans++, cout << i << " 114514\n";
//	}
//	cout << ans << '\n';
//	return ;
//}

void solve() {
	cin >> n >> d;
	int ans = 0;
	vector <int> x(n + 1), m(n + 1), st;
	bitset<2000006> vis;
	m[1] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		m[i] = m[i - 1];
		while (x[i] - x[m[i]] > d) m[i]++;
	}
	for (int i = 4; i <= n; i++) {
		if (m[m[i] + 1] == m[m[i]] + 1) {
			st.push_back(i);
			vis[i] = vis[m[m[i] + 1]] = 1;
			ans++;
//			cout << i << ' ';
		}
	}
	vis[1] = 1;
	if (st.empty()) {
		cout << "0\n";
		return ;
	}
	for (auto it : st) {
//		cout << "114514\n";
		int v = m[m[it] + 1], tot = 0;
		while (vis[m[v]] && v != m[v]) {
			v = m[v];
			vis[v] = 1;
			tot++;
//			cout << v << '\n';
		}
		if (v != 1) ans += tot;
		ans += tot;
	}
	int lst = st[st.size() - 1];
	for (int i = lst; i <= n; i++) {
		if (m[i] > lst && m[i - 1] < lst) ans++, lst = i;
//		,cout << i << '\n';;
	}
	cout << ans << '\n';
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/

