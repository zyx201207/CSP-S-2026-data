#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pr pair<int,int>
int dist[500005], k[150005];

struct node {
	int nxt, w;
};
vector <node> V[900005];
bool vis[500005];
priority_queue<pr, vector<pr>, greater<pr> > q;

void dijk(int x) {
	memset(dist, 0x3f, sizeof dist);
	memset(vis, 0, sizeof vis);
	dist[x] = 0;
	q.push(make_pair(0, x));
	while (!q.empty()) {
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (int i = 0; i <= V[u].size() - 1; i++) {
			int v = V[u][i].nxt, ww = V[u][i].w;
			if (dist[u] + ww < dist[v]) {
				dist[v] = dist[u] + ww;
				q.push(make_pair(dist[v], v));
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int n, c, m, d, g;
	cin >> c >> n >> m >> d >> g;
	for (int i = 1; i <= m; i++) {
		cin >> k[i];
	}
	int kk = m;
	for (int i = 1; i <= n; i++) {
		int nn, y, x, xt;
		cin >> nn;
		for (int j = 1; j <= nn; j++) {
			cin >> x >> xt;
			V[x].push_back({++kk, xt});
			V[kk].push_back({x, xt});
			if (j > 1) {
				V[kk].push_back({y, 0});
				V[y].push_back({kk, 0});
			}
			y = kk;
		}
	}
	while (g--) {
		int x, y;
		cin >> x >> y;
		dijk(x);
		cout << dist[y] + k[x] + k[y] << "\n";
	}
	return 0;
}
