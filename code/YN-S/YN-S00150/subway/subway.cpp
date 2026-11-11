#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int c, n, m, d, q;
int dis[N * 21];
bool vis[N * 21];

struct node {
	int v, w;
};
vector<node>x[N * 21];

void dij(int s) {
	memset(dis, 0x3f, sizeof(dis));
	fill(vis + 1, vis + N * 21 + 1, 0);
	queue<int>p;
	p.push(s), vis[s] = 1, dis[s] = 0;
	while (!p.empty()) {
		int u = p.front();
		p.pop();
		for (int i = 0; i < x[u].size(); i++) {
			int v = x[u][i].v, w = x[u][i].w;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				p.push(v);
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		int w;
		cin >> w;
		x[i].push_back({i + N, w});
		x[i + N].push_back({i, w});
	}
	for (int i = 1; i <= n; i++) {
		int k, a[k + 5], t[k + 5];
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
			x[a[j] + N].push_back({a[j] + (i + 1) * N, t[j]});
			x[a[j] + (i + 1) * N].push_back({a[j] + N, t[j]});
		}
		for (int j = 1; j < n; j++)
			x[a[j] + (i + 1) * N].push_back({a[j + 1] + (i + 1) * N, 0});
	}
	while (q--) {
		int s, e;
		cin >> s >> e;
		dij(s);
		cout << dis[e] << '\n';
	}
	return 0;
}