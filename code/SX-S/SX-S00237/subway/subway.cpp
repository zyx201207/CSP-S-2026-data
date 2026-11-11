#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N = 505;
constexpr int M = 125300; //125250;
constexpr int K = 5e5+5;
constexpr int D = 25;
constexpr int Q = 1e5+5;
int c, n, m, d, q;
int w[M], k[N]/*, a[N][K], t[N][K]*/, x[Q], y[Q];
vector<int>blo[N];
using pi = pair<int, int>;
vector<pi>g[N];
#define F first
#define S second
int dis[N];
bool vis[N];
#define check cout<<"ffs\n"

void dijkstra(int u) {
//	check;
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<pi>pq;
	pq.push({0, u});
	dis[u] = 0;
	while (!pq.empty()) {
		check;
		int y = pq.top().S;
		pq.pop();
		if (vis[y])
			continue;
		vis[y] = 1;
		for (const auto & p : g[y]) {
			int z = p.F, w = p.S;
			if (dis[z] > dis[y] + w) {
				dis[z] = dis[y] + w;
				pq.push({-dis[z], z});
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	check;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i)
		cin >> w[i];
	vector<int>a[n + 1], t[n + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		for (int j = 1, aa, tt; j <= k[i]; ++j) {
			cin >> aa >> tt;
			a[i].emplace_back(aa);
			t[i].emplace_back(tt);
		}
	}
	for (int i = 1; i <= q; ++i)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= k[i]; ++j) {
//			check;
			blo[i].emplace_back(a[i][j]);
		}
		if (i != 1) {
			for (int j = 1; j <= i - 1; ++j)
//				for(const auto&v:blo[j])
				for (int vv = 0; vv < blo[j].size(); ++vv)
//					for(const auto&u:blo[i])
					for (int uu = 0; uu < blo[i].size(); ++uu) {
						int u = blo[i][uu], v = blo[j][vv];
						if (u == v)
							g[i].emplace_back(j, t[i][uu] + t[j][vv]),
							g[j].emplace_back(i, t[i][uu] + t[j][vv]);
					}
		}
	}
//	check;
	for (int i = 1; i <= q; ++i) {
		int blo_id = -1;
		for (int j = 1; j <= n; ++j) {
			int cnt = 0;
			for (const auto&pos : blo[j])
				if (pos == x[i] || pos == y[i])
					cnt++;
			if (cnt == 2) {
				blo_id = j;
				break;
			}
		}
		if (blo_id != -1) {
			cout << w[x[i]] + w[y[i]] + t[blo_id][x[i]] + t[blo_id][y[i]] << '\n';
		} else {
			int idx = 0, idy = 0;
			for (int j = 1; j <= n; ++j) {
				for (const auto&xx : blo[j])
					if (xx == x[i]) {
						idx = j;
						break;
					}
				for (const auto&yy : blo[j])
					if (yy == y[i]) {
						idy = j;
						break;
					}
			}
			dijkstra(idx);
			cout << dis[idy] + w[x[i]] + w[y[i]] + t[idx][x[i]] + t[idy][y[i]] << '\n';
		}
	}
	return 0;
}
