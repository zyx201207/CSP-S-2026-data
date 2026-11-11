#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c, n, m, d, q, w[505], x[505], y[505], a[25][505], t[25][505], dp[200005], k[505], ans;
bool vis[25][505];

struct nde {
	int x, t, y;
};
queue<nde>que;
vector<nde>v[505];

int bfs_a(int yyyy) {
	int mn = INT_MIN;
	while (!que.empty()) {

//		cout << "inok" << endl;
		nde d = que.front();
		if (d.x == yyyy) {
			mn = min(mn, d.t);
		}
		for (auto u : v[d.x]) {
			if (!vis[u.y][u.x]) {
				que.push({u.x, d.t + u.t, u.y});
			}
		}
	}
	return mn;
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	cout << "imok" << endl;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int qq = 1; qq <= q; qq++) {
		cin >> x[qq] >> y[qq];
		for(int i = 1;i<=n;i++){
			dp[i] = max(dp[i],dp[i-1]+a[i][dp[i]]);
		}
		cout<<dp[n]<<endl;
	}
	if (c >= 7 && c <= 11) {
		for (int qq = 1; qq <= q; qq++) {
			ans += w[x[qq]] + w[y[qq]];
			for (int i = 1; i <= n; i++) {
				if (k[i] == 2) {
					nde azc = {a[i][2], t[i][2] + t[i][1], i};
					v[a[i][1]].push_back(azc);
					v[a[i][2]].push_back(azc);
				}
			}
			que.push({x[qq], 0, -1});
			ans += bfs_a(y[qq]);
			cout << ans << endl;
		}
	}
	return 0;
}
