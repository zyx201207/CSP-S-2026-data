#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e2+10, M = 2e4+10;;
struct node {
	int v, w;
	bool operator < (const node &o) const {
		return w > o.w;
	}
};
vector<node> g[M];
priority_queue<node> pq;
int c, n, m, d, q, k, w[M], a[N][M], t[N][M], vis[M], dis[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++)
			cin >> a[i][j] >> t[i][j];
		for (int x = 1; x <= k; x++)
			for (int y = x+1; y <= k; y++)
			{
				g[a[i][x]].push_back((node){a[i][y], t[i][x]+t[i][y]});
				g[a[i][y]].push_back((node){a[i][x], t[i][x]+t[i][y]});
			}
	}
	while (q--) {
		int b, e;
		cin >> b >> e;
		memset(dis, 0x7f, sizeof(dis));
		memset(vis, 0, sizeof(vis));
		pq.push((node){b, 0});
		dis[b] = 0;
		while (!pq.empty()) {
			int u = pq.top().v;
			pq.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (int i = 0; i < g[u].size(); i++)
			{
				int v = g[u][i].v, w = g[u][i].w;
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					pq.push((node){v, dis[v]});
				}
			}
		}
		cout << w[b] + dis[e] + w[e] << "\n";
	}
	return 0;
}
