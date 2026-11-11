#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500 + 5, M = 1e3 + 5, Max = 1e18;
int c, n, m, d, q, w[M], dis[M][22], ans[M][M], k[M], vis[M][22];
vector<pair<int, int>>g[M];
vector<pair<int, int>>hb[M];
map<int, int>mp[M];

struct wy {
	int u, w, id;
	friend bool operator<(wy a, wy b) {
		return a.w > b.w;
	}
};

void bfs(int x) {

	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= d; j++) {
			dis[i][j] = Max;
		}
	}
	queue<wy>pq;
	for (int i = 0; i < hb[x].size(); i++) {
		int xl = hb[x][i].first;
		int costt = g[xl][hb[x][i].second].second;
		dis[x][i] = w[x] + costt;
		pq.push({x, w[x] + costt, xl});
	}
	while (pq.size()) {
		wy u = pq.front();
		pq.pop();
		int uu = u.u;
		int ww = u.w;
		int id = u.id;
		int ysid = mp[uu][id] - 1;
//		cout << ysid << '\n';


		for (int i = 0; i < hb[uu].size(); i++) {
			int yxl = hb[uu][ysid].first;
			int ycost = g[yxl][hb[uu][ysid].second].second;
			int xl = hb[uu][i].first;
			int costt = g[xl][hb[uu][i].second].second + ycost;
			if (dis[uu][i] > ww + costt) {
				dis[uu][i] = ww + costt;
				pq.push({uu, ww + costt, xl});
			}
		}
		for (int i = 0; i < k[id]; i++) {
			int vv = g[id][i].first;
			int ysid1 = mp[vv][id] - 1;
			if (dis[vv][ysid1] > ww) {
				dis[vv][ysid1] = ww;
				pq.push({vv, ww, id});
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		if (i != x)
			for (int j = 0; j < hb[i].size(); j++) {
				int xl = hb[i][j].first;
				int costt = g[xl][hb[i][j].second].second + w[i];
				ans[x][i] = min(ans[x][i], dis[i][j] + costt);
			}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			ans[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int aa, tt;
			cin >> aa >> tt;
			//	cout << aa << ' ' << tt << '\n';
			hb[aa].push_back({i, j - 1});
			mp[aa][i] = hb[aa].size();

			g[i].push_back({aa, tt});
		}
	}

	for (int i = 1; i <= m; i++) {
		bfs(i);
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << ans[x][y] << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/