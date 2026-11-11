#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 505, MAXM = 5e5 + 5;
int c, n, m, d, q, w[MAXM], k[MAXN], x, y;
vector<int> a[MAXN], t[MAXN];
vector<pair<int, int>> g[MAXM];
bool vis[MAXM];
int bfs(int s, int t) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	memset(vis, 0, sizeof vis);
	pq.push({0, s});
	while(!pq.empty()) {
		pair<int, int> tp = pq.top(); pq.pop();
		int u = tp.second, w = tp.first;
		if(u == t) return w;
		if(vis[u]) continue;
		vis[u] = 1;
		for(pair<int, int> p : g[u]) {
			int v = p.first;
			if(!vis[v]) pq.push({w + p.second, v});
		}
	}
	return -1;
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++) {
		cin >> k[i];
		for(int j = 1, aij, tij; j <= k[i]; j++)
			cin >> aij >> tij, a[i].push_back(aij), t[i].push_back(tij);
		for(int i1 = 0; i1 < k[i]; i1++)
			for(int i2 = 0; i2 < k[i]; i2++)
				if(i1 != i2) g[a[i][i1]].push_back({a[i][i2], t[i][i1] + t[i][i2]});
	}
	while(q--) {
		cin >> x >> y;
		cout << bfs(x, y) + w[x] + w[y] << "\n";
	}
	return 0;
}
