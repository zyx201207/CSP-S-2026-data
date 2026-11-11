/*
如何游玩粉键？
↑↗→↘↓↙←↖

DESTRUCTION 3,2,1
↑~

Exoplanetary Mirage
↑↑↑~
↑↑↑~

Desultory Signals
↑↑↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑
↑ ↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑
↑ ↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑
↑ ↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑ ↑↑↑↑↑
*/

#include<bits/stdc++.h>
typedef long long ll;
const int N = 505, M = 5e5 + 5;
std::vector< std::pair<int, ll> > metros[M];
std::vector< std::pair<int, ll> > stations[N];
std::vector< std::pair<int, ll> > E[N];
ll dis[N][N], dis2[N][N];
ll W[M];

struct Node {
	int u;
	ll dis;

	bool operator<(Node b) const {
		return b.dis > dis;
	}
};

void dijkstra(int s) {
	memset(dis2[s], 0x3f, sizeof dis2[s]);
	dis2[s][s] = 0;
	std::priority_queue<Node> Q;
	Q.push({s, 0});
	while(Q.size()) {
		auto cur = Q.top(); Q.pop();
		int u = cur.u;
		ll d = cur.dis;
		if(d != dis2[s][u])
			continue;
		for(auto e : E[u]) {
			int v = e.first;
			ll w = e.second;
			if(dis2[s][u] + w < dis2[s][v])
				dis2[s][v] = dis2[s][u] + w, Q.push({v, dis2[s][v]});
		}
	}
}


int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int _, n, m, d, q;
	scanf("%d%d%d%d%d", &_, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
		scanf("%lld", W + i);
	for(int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++) {
			int a;
			ll t;
			scanf("%d%lld", &a, &t);
			stations[i].push_back(std::make_pair(a, t));
			metros[a].push_back({i, t});
		}
	}
	memset(dis, 0x3f, sizeof dis);
	for(int i = 1; i <= n; i++) {
		for(auto raw_cur : stations[i]) {
			int cur = raw_cur.first;
			ll t = raw_cur.second;
			for(auto raw_metro : metros[cur]) {
				int metro = raw_metro.first;
				ll t2 = raw_metro.second;
				if(metro != i)
					dis[i][metro] = std::min(dis[i][metro], t + t2);
			}
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j && dis[i][j] <= 1e18)
				E[i].push_back({j, dis[i][j]});
	for(int i = 1; i <= n; i++)
		dijkstra(i);

	while(q--) {
		int s, t;
		ll ans = 0x3f3f3f3f3f3f3f3f;
		scanf("%d%d", &s, &t);
		for(auto ii : metros[s])
			for(auto jj : metros[t]) {
				int i = ii.first, j = jj.first;
				ll ti = ii.second, tj = jj.second;
				ans = std::min(ans, W[s] + W[t] + ti + tj + dis2[i][j]);
			}
		printf("%lld\n", ans);
	}
	return 0;
}
