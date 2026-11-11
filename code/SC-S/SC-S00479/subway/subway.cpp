#include<bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(),(x).end()

const int inf = 9e18;
int c, n, m, d, q;
vector<int>w;
vector<vector<int>>f, g, t, dis;

void work() {
	cin >> c >> n >> m >> d >> q;
	dis.assign(m + 5, vector<int>(m + 5, inf));
	f.resize(m + 5);
	g.resize(n + 5);
	w.resize(m + 5);
	t.resize(n + 5);
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
		dis[i][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		t[i].resize(m + 5);
		for (int j = 1; j <= k; j++) {
			int a;
			cin >> a;
			f[a].push_back(i);
			g[i].push_back(a);
			cin >> t[i][a];
		}
	}
	for (int i = 1; i <= m; i++)
		for (auto j : f[i])
			for (auto k : g[j]) {
				if (i == k)	continue;
				dis[i][k] = min(dis[i][k], t[j][i] + t[j][k]);
			}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= m; k++)
				if (dis[i][k] != inf && dis[k][j] != inf)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		cout << dis[x][y] + w[x] + w[y] << "\n";
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--)	work();
	return 0;
}