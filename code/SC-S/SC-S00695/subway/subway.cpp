#include<bits/stdc++.h>
using namespace std;
const int N = 500 + 10;
int c, n, m, d, q, dis[N], vis[N], w[N], a[N], t[N], qqq[N][N], T;
vector<int> g[N];
struct node {
	int dis, u;
	bool operator < (const node & x) const {
		return dis < x.dis;
	}
};
void dij(int s) {
	priority_queue<node> pq;
	for (int i = 1; i <= m; i ++) dis[i] = 1e9;
	dis[s] = T;
	for (int i = 1; i <= m; i ++) vis[i] = 0;
	vis[s] = 1;
	pq.push({dis[s], s});
	while (!pq.empty()) {
		node x = pq.top(); pq.pop();
		int u = x.u;
		if (!vis[u]) continue;
		for (int i = 0; i < g[u].size(); i ++) {
			int v = g[u][i];
			int len;
			if (qqq[u][v]) len = 0;
			else len = T;
			if (dis[v] > dis[u] + len) {
				dis[v] = dis[u] + len;
				pq.push({dis[v], v});
				vis[v] = 1;
			}
		}
	}
	return ;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
//	int T = 0;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j ++) {
			cin >> a[j] >> t[j];
			T = t[j];
		}
		for (int j = 1; j <= k; j ++) {
			for (int f = 1; f <= k; f ++) {
				qqq[a[j]][a[f]] = 1;
			}
		}
		for (int j = 2; j <= k; j ++) {
			int ww = t[j-1] + t[j];
			g[a[j-1]].push_back(a[j]);
			g[a[j]].push_back(a[j-1]);
		}
	}
//	for (int i = 1; i <= m; i ++) {
//		for (int j = 1; j <= m; j ++) {
//			cout << qqq[i][j] << " ";
//		}
//		cout << "\n";
//	}
	while (q --) {
		int xr, yr;
		cin >> xr >> yr;
		dij(xr);
		cout << dis[yr] + w[xr] + w[yr] + T << "\n";
	}
	return 0;
}
