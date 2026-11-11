#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> PII;
const ll N = 1e3 + 10;
const ll INF = 1e18;

ll __, n, m, d, _, tot, 
	dis[N][N * 10], vis[N][N * 10];
vector <PII> e[N * 10];		// 最多3m个点 

void add(ll u, ll v, ll w) {
	e[u].push_back({v, w});
	e[v].push_back({u, w});
}

void dijkstra(ll s) {
	priority_queue <PII, vector <PII>, greater <PII> > q;
	q.push({0, s});
	for (ll i = 1; i <= tot; i ++) dis[s][i] = INF;
	dis[s][s] = 0;
	
	while (q.size()) {
		ll u = q.top().second;
		q.pop();
		
		if (vis[s][u]) continue;
		vis[s][u] = 1;
		
		for (ll i = 0; i < e[u].size(); i ++) {
			ll v = e[u][i].first, w = e[u][i].second;
			if (dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				q.push({dis[s][v], v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> __ >> n >> m >> d >> _;
	for (ll i = 1, w; i <= m; i ++) {
		cin >> w;
		++ tot;
		add(tot, m + tot, w);
	}
	tot = 2 * m;
	for (ll i = 1, k; i <= n; i ++) {
		cin >> k;
		ll lst = 0;
		for (ll j = 1, a, t; j <= k; j ++) {
			cin >> a >> t;
			add(++ tot, m + a, t);
			if (lst) add(tot, lst, 0);
			lst = tot;
		}
	}
//	for (ll i = 1; i <= tot; i ++) {
//		for (ll j = 0; j < e[i].size(); j ++) {
//			ll to = e[i][j].first, w = e[i][j].second;
//			cout << "点" << i << "与点" << to << "连边权值" << w << endl << endl;
//		}
//	}
	
	for (ll i = 1; i <= m; i ++) dijkstra(i);		// O(4m^2log^2m) 44pts
	while (_ --) {
		ll x, y; cin >> x >> y;
		cout << dis[x][y] << endl;
	}
	
	return 0;
}

// 应该已经过掉 T1 了
// T2 这雷霆题面谁出的 太猎奇了 
// 我【数据删除】 读题读了快 half an hour 
// 写了 1h 仅得到 44pts 我是不是可以拿到 Fe 牌了 


/* ?????

点1与点11连边权值0

点11与点1连边权值0

点13与点14连边权值0

点14与点13连边权值0

*/


