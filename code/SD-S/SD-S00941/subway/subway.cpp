#include <bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define PII pair<int, int>
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, w[N], a[N], t[N], vis[N], dis[N];
vector<PII> e[N];
priority_queue<PII> pq;
void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	pq = priority_queue<pair<int, int> > ();
	pq.push({0, s});
	dis[s] = 0;
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		vis[u] = 0;
		for (auto x : e[u]) {
			int v = x.first, w = x.second;
			if (vis[v]) continue;
			if (dis[u] + w < dis[v]) {
				dis[v] = dis[u] + w;
				vis[v] = 1;
				pq.push({-w, v});
			}
		}		
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); 
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
		}
		for (int j = 1; j <= k; j++) {
			for (int jj = j + 1; jj <= k; jj++) {
				e[a[j]].push_back({a[jj], t[jj] + t[j]}); 
				e[a[jj]].push_back({a[j], t[jj] + t[j]});
			}
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		dijkstra(x);
		cout << dis[y] + w[x] + w[y] << '\n';
	} 
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
