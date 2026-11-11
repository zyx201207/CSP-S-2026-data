#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 505;

int op, n, m, d, q;
int w[N];
int dis[505][505];
vector <pair <int, int>> ive[N];

signed main () {
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	cin >> op >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (i != j) dis[i][j] = 1e18;
	for (int i = 1, k; i <= n; i++) {
		cin >> k;
		for (int j = 1, a, tim; j <= k; j++) {
			cin >> a >> tim;
			for (auto [v, t] : ive[a]) dis[i][v] = dis[v][i] = tim + t;
			ive[a].push_back ({i, tim});
		}
	}
	for (int k = 1; k <= n; k++) 
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min (dis[i][j], dis[i][k] + dis[k][j]);
	while (q--) {
		int l, r, ans = 1e18;
		cin >> l >> r;
		for (auto [u, t1] : ive[l])
			for (auto [v, t2] : ive[r]) {
				int res = dis[u][v] + t1 + t2 + w[l] + w[r];
				ans = min (ans, res);
			}
		cout << ans << "\n";
	}
	return 0;
}