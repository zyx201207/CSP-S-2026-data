#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 1, M = 501;
int c, n, m, d, Q, K[N], a[M][N], t[M][N], w[N], W[M][M], dis[M], vis[M];

struct node {
	int v, w;
};
vector<node>e[N];
vector<int>g[M];

void bfs(int st, int en) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
//	queue<pair<int, int>>q;
	int res = 1e18;
	for (auto p : g[st]) {
		memset(dis, 0x3f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		dis[p] = 0;
		q.push({0, p});
		int ans = -1;
		while (!q.empty()) {
			int x = q.top().second;
//			int x = q.front().second;
			if (x == en) {
				ans = dis[x];
				break;
			}
			for (int i = 0; i < e[x].size(); i++) {
				int v = e[x][i].v;
				int w = e[x][i].w;
				if (dis[v] > dis[x] + w && vis[v] < 91) {
					dis[v] = dis[x] + w;
					q.push({dis[v], v});
				}
			}
		}
		res = min(res, ans);
	}
	cout << res << '\n';
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> K[i];
		for (int j = 1; j <= K[i]; j++) {
			cin >> a[i][j] >> t[i][j];
			g[a[i][j]].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			W[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < e[i].size() - 1; j++) {
			for (int k = i + 1; k < e[i].size(); k++) {
				W[j][k] = min(W[j][k], t[j][i] + t[k][i]);
			}
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; i <= n; i++) {
			e[i].push_back({j, W[i][j]});
			e[j].push_back({i, W[i][j]});
		}
	}
	while (Q--) {
		int st, en;
		cin >> st >> en;
		bfs(st, en);
	}
	return 0;
}