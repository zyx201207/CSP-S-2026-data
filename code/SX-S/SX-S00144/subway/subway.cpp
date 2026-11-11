#include <bits/stdc++.h>
using namespace std;
int n, m, d, q; //n为地铁线路数，m为地铁站数，d为每个地铁站最多被几条线路穿过，q为出行计划数

struct edge {
	int id, kind, w;
};
int ans;
vector<edge> g[1005][505]; //g[i][1]为i站的地铁口，g[i][2]为i站的站厅，g[i][j+2]为i站的j号线站台，g[0][j]为j号线
bool flag[1005][505];

void dfs(int uid, int ukind, int eid, int ekind, int cost) {
	if (uid == eid && ukind == ekind) {
		ans = min(ans, cost);
		return;
	}
	if (cost > ans) {
		return;
	}
	for (auto i : g[uid][ukind]) {
		if (!flag[i.id][i.kind]) {
			flag[i.id][i.kind] = true;
			dfs(i.id, i.kind, eid, ekind, cost + i.w);
			flag[i.id][i.kind] = false;
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		int x;
		cin >> x;
		g[i][1].push_back({i, 2, x});
		g[i][2].push_back({i, 1, x});
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		while (k--) {
			int x, y;
			cin >> x >> y;
			g[0][i].push_back({x, i + 2, 0});
			g[x][i + 2].push_back({0, i, 0});
			g[x][2].push_back({x, i + 2, y});
			g[x][i + 2].push_back({x, 2, y});
		}
	}
	while (q--) {
		int s, e;
		ans = 0x3f3f3f3f;
		cin >> s >> e;
		dfs(s, 1, e, 1, 0);
		printf("%d\n", ans);
	}
	return 0;
}