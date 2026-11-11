#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 510;
const int M = 1e6 + 10;
int c, n, m, d, q;
int w[N];
int x, y;
struct node {
	int idx, v, now;
};
struct query {
	int x, y, idx;
} p[100010];
vector<pii > vec[N];
int cost[N][N]; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!cost[N][M]
vector<node> e[N];
bool vis_edge[M];
//int e[N][N];
//vector<int> lt; //lian tong
int dis[N]; //离线后分次做 
int ans[100010];
bool cmp(query x, query y) {
	return x.x < y.x;
}
void dfs(int u, int fa, int tim) {
	for (int i = 0; i < (int)e[u].size(); ++i) {
//		cout << "B";
		int idx = e[u][i].idx, v = e[u][i].v;
		if (v == fa) continue;
//		cout << idx << " " << u << " " << v << " \n";
//		cout << cost[idx][u] << " " << cost[idx][v] << "\n";
		int nt = tim;
		nt += cost[idx][u] + cost[idx][v];
//		cout << nt << "\n";
//		dis[v] = min(dis[v], nt + w[v]);
		if (dis[v] > nt + w[v]) {
			dis[v] = nt + w[v];
			dfs(v, u, nt);
		}
	}
}
int main() {
	freopen("subway2.in", "r", stdin);
//	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	for (int i = 1, k, a, t; i <= n; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> a >> t;
			vec[i].push_back({a, t});
			cost[i][a] = t;
			if (j != 0) {
				e[vec[i][j - 1].first].push_back({i, a});
				e[a].push_back({i, vec[i][j - 1].first});
//				e[vec[i][j - 1].first][a] += t;
//				e[a][vec[i][j - 1].first] += t;
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		cin >> p[i].x >> p[i].y;
		p[i].idx = i;
	}
	
	sort(p + 1, p + q + 1, cmp);
	int i = 1;
	while (i <= q) {
//		now++;
		for (int i = 1; i <= m; ++i) dis[i] = 1e9;
		dfs(p[i].x, 0, w[p[i].x]);
		ans[p[i].idx] = dis[p[i].y];
		while (i <= q && p[i].x == p[i + 1].x) {
			i++;
			ans[p[i].idx] = dis[p[i].y];
		}
		i++;
	}
	
//	cout << w[1] << "\n";
//	now++;
//	for (int i = 1; i <= m; ++i) dis[i] = 1e9;
//	dfs(1, 0, w[1]);
//	for (int i = 1; i <= m; ++i) {
//		cout << dis[i] << " ";
//	}
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
