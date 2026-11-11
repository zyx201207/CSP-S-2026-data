#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q;

struct node {
	int xian, t;
};
int w[500010];

struct node1 {
	int zhan, t;
};
vector<node1>g[500];
vector<node>p[500010];
bool vis[510][50010];
int x, y;
int res;

void dfs(int ter, int time) {
	if (time > res)
		return;
	if (ter == y) {
		res = time;
		return;
	}
	for (int i = 0; i < p[ter].size(); i++) {
		for (int j = 0; j < g[p[ter][i].xian].size(); j++) {
			if (!vis[p[ter][i].xian][g[p[ter][i].xian][j].zhan]) {
				vis[p[ter][i].xian][g[p[ter][i].xian][j].zhan] = 1;
				dfs(g[p[ter][i].xian][j].zhan, time + p[ter][i].t + g[p[ter][i].xian][j].t);
				vis[p[ter][i].xian][g[p[ter][i].xian][j].zhan] = 0;
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	int mmax = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int u, dis;
			cin >> u >> dis;
			mmax += dis;
			g[i].push_back({u, dis});
			p[u].push_back({i, dis});
		}
	}
	while (q--) {

		cin >> x >> y;
		res = mmax * 10;
		dfs(x, 0);
		cout << res + w[x] + w[y] << endl;
	}
	return 0;
}