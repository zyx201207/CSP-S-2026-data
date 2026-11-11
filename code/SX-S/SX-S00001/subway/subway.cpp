#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int c, n, m, d, q, k, w[500005];
vector<pair<pii, int>> e[500005][25];
vector<int> a[505], t[505], id[500005];
bool vis[500005];
int dst[500005][25];
int dist[50005][50005];

void dij(int S) {
	priority_queue<pair<int, pii>> pq;
	memset(vis, 0, sizeof(vis));
	memset(dst, 0x3f, sizeof(dst));
	pq.push({0, {S, 0}});
	dst[S][0] = 0;
	vis[S] = 1;
	while (!pq.empty()) {
		auto ux = pq.top().se.fi;
		auto uy = pq.top().se.se;
		pq.pop();
		vis[ux] = 1;
		for (auto vv : e[ux][uy]) {
			auto vx = vv.fi.fi;
			auto vy = vv.fi.se;
			auto ww = vv.se;
			if (vis[vx] == 0) {
				if (dst[ux][uy] + ww < dst[vx][vy]) {
					dst[vx][vy] = dst[ux][uy] + ww;
					pq.push({dst[vx][vy], {vx, vy}});
				}
			}
		}
	}
	for (int i = 0; i <= n; i++) {
		dist[S][i] = dst[i][0];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "w", stdin);
	freopen("subway.out", "r", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int aa, tt;
			cin >> aa >> tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
		for (int j = 0; j < k - 1; j++) {
			e[a[i][j]][i].push_back({{a[i][j + 1], i}, 0});
			e[a[i][j + 1]][i].push_back({{a[i][j], i}, 0});
		}
		for (int j = 0; j < k; j++) {
			e[a[i][j]][i].push_back({{a[i][j], 0}, t[i][j]});
		}
	}
	for (int i = 1; i <= m; i++) {
		dij(i);
	}
	int x, y;
	while (q--) {
		cin >> x >> y;
		cout << dist[x][y] + w[x] + w[y] << "\n";
	}
	return 0;
}