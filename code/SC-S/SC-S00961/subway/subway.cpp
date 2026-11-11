#include <bits/stdc++.h>
using namespace std;

//  #define DEBUG
using ll = long long;
const int N = 505, M = 5e5 + 505 + 5;
const ll inf = 1e18;
int c, n, m, d, q;
ll w[M];
vector<pair<int, ll> > E[M], G[N];
ll dis[N][N];
int vis[N];
priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<int, int> > > pq;

void link(int u, int v, ll w) {
	E[u].push_back({v, w});
}

void link2(int u, int v, ll w) {
	G[u].push_back({v, w});
	G[v].push_back({u, w});
}

void dijk(int s) {
	for (int i = 1; i <= n; ++i)dis[s][i] = inf;
	dis[s][s] = 0;
	pq.push({0, s});
	while(pq.size()) {
		int u = pq.top().second;
		pq.pop();
		if(vis[u] == s)continue;
		vis[u] = s;
		for (pair<int, ll> e : G[u]) {
			int v = e.first;
			if(dis[s][v] > dis[s][u] + e.second) {
				dis[s][v] = dis[s][u] + e.second;
				pq.push({dis[s][v], v});
			}
		}
	}
}

int main() {
#ifndef DEBUG
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i <= n; ++i) {
		int k;
		int a;
		ll t;
		scanf("%d", &k);
		while(k--) {
			scanf("%d%lld", &a, &t);
			link(a, i, t);
		}
	}
	for (int i = 1; i <= m; ++i) {
		int sz = E[i].size();
		for (int j = 0; j < sz; ++j) {
			for (int k = j + 1; k < sz; ++k) {
				link2(E[i][j].first, E[i][k].first, E[i][j].second + E[i][k].second);
			}
		}
	}
	for (int i = 1; i <= n; ++i)dijk(i);
	while(q--) {
		int u, v;
		scanf("%d%d", &u, &v);
		ll ans = inf;
		for (auto e1 : E[u]) {
			for (auto e2 : E[v]) {
				ans = min(ans, dis[e1.first][e2.first] + e1.second + e2.second);
			}
		}
		printf("%lld\n", ans + w[u] + w[v]);
	}
	return 0;
}