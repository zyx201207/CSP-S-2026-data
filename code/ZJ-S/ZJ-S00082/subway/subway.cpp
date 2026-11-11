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
int cost[N][M]; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!cost[N][M] 476MB
vector<node> e[N];
//int vis[M];
//int e[N][N];
//vector<int> lt; //lian tong
int dis[N];
int ans[100010];
//int now;
bool instk[M];
bool cmp(query x, query y) {
	return x.x < y.x;
}
void dfs(int u, int last_idx, int fa, int tim) {
	for (int i = 0; i < (int)e[u].size(); ++i) {
//		cout << "B";
		int idx = e[u][i].idx, v = e[u][i].v;
//		cout << idx << " " << u << " " << last_idx << " " << v << " \n";
		if (v == fa || instk[v]) continue;
//		cout << idx << " " << u << " " << last_idx << " " << v << " \n";
//		cout << cost[last_idx][u] << " " << cost[idx][u] << "\n";
		int nt = tim;
		if (idx != last_idx) nt += cost[last_idx][u] + cost[idx][u];
//		cout << nt << "\n";
		if (dis[v] > nt + cost[idx][v] + w[v]) {
			dis[v] = nt + cost[idx][v] + w[v];
		}
		instk[v] = 1;
		dfs(v, idx, u, nt);
		instk[v] = 0;
//		if (v == 6) cout << dis[v] << "\n";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
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
				e[vec[i][j - 1].first].push_back({i, a, 0});
				e[a].push_back({i, vec[i][j - 1].first, 0});
//				e[vec[i][j - 1].first][a] += t;
//				e[a][vec[i][j - 1].first] += t;
			}
		}
	}
	
//	for (auto i : e[5]) {
//		cout << i.v << " " << i.idx << "\n";
//	}
//	return 0;
	
	for (int i = 1; i <= q; ++i) {
		cin >> p[i].x >> p[i].y;
		p[i].idx = i;
	}
	
	sort(p + 1, p + q + 1, cmp);
	int i = 1;
	while (i <= q) {
//		now++;
		for (int i = 1; i <= m; ++i) dis[i] = 1e9;
		dfs(p[i].x, 0, 0, w[p[i].x]);
		dis[p[i].x] = 0;
		ans[p[i].idx] = dis[p[i].y];
		while (i <= q && p[i].x == p[i + 1].x) {
			i++;
			ans[p[i].idx] = dis[p[i].y];
		}
		i++;
	}
	
//	now++;
//	for (int i = 1; i <= m; ++i) dis[i] = 1e9;
//	dfs(1, 0, 0, w[1]);

//	for (int i = 1; i <= m; ++i) {
//		cout << dis[i] << " ";
//	}
	
	for (int i = 1; i <= q; ++i) {
		cout << ans[i] << "\n";
	}
	return 0;
}
