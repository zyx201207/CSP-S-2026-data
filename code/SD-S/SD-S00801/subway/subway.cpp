#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> PLL;
const int INF = 0x3f3f3f3f;
const ll INF2 = 0x3f3f3f3f3f3f3f3f;

ll c, n, m, d, q;
const int N = 505;
const int M = 5e5 + 10;
const int Q = 200;
ll w[M];
ll k[N];
ll x[Q], y[Q];

const int M2 = 1010;
ll a[N][M2], t[N][M2];
vector<PLL> G[M2];
ll dis[M2][M2];
void dijkstra(ll st) {
	priority_queue<PLL, vector<PLL>, greater<PLL>> q;
	q.push({0, st});
	dis[st][st] = 0;
	
	while (!q.empty()) {
		auto it = q.top();
		q.pop();
		
		ll u = it.second;
		ll w = it.first;
		if (dis[st][u] < w) continue;
		
		for (auto t : G[u]) {
			ll v = t.first;
			ll ww = t.second;
			if (dis[st][v] > dis[st][u]+ww) {
				dis[st][v] = dis[st][u]+ww;
				
				q.push({dis[st][v], v}); 
			}
		}
	}
}
void solve1() {
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}
		for (int j = 1; j <= k[i]; j++) {
			for (int jj = j+1; jj <= k[i]; jj++) {
				G[a[i][j]].push_back({a[i][jj], t[i][j]+t[i][jj]});
				G[a[i][jj]].push_back({a[i][j], t[i][j]+t[i][jj]});
			}
		}
	}
	
	memset(dis, 0x3f, sizeof dis);
	for (int i = 1; i <= m; i++) {
		dijkstra(i);
	}
	
	for (int i = 1; i <= q; i++) {
		ll s, t;
		cin >> s >> t;
		cout << w[s]+w[t]+dis[s][t] << '\n';
	}
}


vector<PLL> sw[N];
vector<PLL> zt[M];
ll dt[M];
void dij(int st) {
	memset(dt, 0x3f, sizeof dt);
	priority_queue<PLL, vector<PLL>, greater<PLL>> q;
	q.push({0, st});
	dt[st] = 0;

	while (!q.empty()) {
		int u = q.top().second;
		ll w = q.top().first;
		q.pop();
		
		if (dt[u] < w) continue;
		
		for (auto it : zt[u]) {
			ll w = it.second;
			int ss = it.first;
			for (auto i : sw[ss]) {
				int v = i.first;
				ll ww = w+i.second;
				if (dt[v] > dt[u]+ww) {
					dt[v] = dt[u]+ww;
					q.push({dt[v], v});
				}
			}
		}
	}
}
void solve2() {
	for (int i = 1; i <= n; i++) {
		int k = 0;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			sw[i].push_back({a, t}); 
			zt[a].push_back({i, t});
		}
	}
	
	for (int i = 1; i <= q; i++) {
		int s, t;
		cin >> s >> t;
		dij(s);
		cout << w[s]+w[t]+dt[t] << '\n';
	} 
}

struct Node {
	int u, t, pp;
};
vector<Node> z[M];
vector<PLL> g[N*20];
ll aa[M], tt[M];
void solve3() {
	for (int i = 1; i <= n; i++) {
		int k = 0;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> aa[j] >> tt[j];
			if (j == 1) continue; 
			
			Node tmp;
			tmp.pp = i;
			tmp.u = aa[j-1];
			tmp.t = tt[j];
			z[aa[j]].push_back(tmp);
			tmp.u = aa[j];
			tmp.t = tt[j-1];
			z[aa[j-1]].push_back(tmp);
		}
	}
	
	for (int i = 1; i <= m; i++) {
		cout << i << '\n';
		for (auto it : z[i]) {
			cout << it.u << ' ' << it.t << ' ' << it.pp << '\n';
		}
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < z[i].size(); j++) {
			for (int jj = j+1; jj < z[i].size(); jj++) {
				ll t;
				if (z[i][j].pp == z[i][jj].pp) {
					t = 0;
				} else {
					t = z[i][j].t + z[i][jj].t;
				}
				g[z[i][j].u].push_back({z[i][jj].u, t});
			}
		}
	}
	
	for (int i = 0; i < 5; i++) {
		cout << i << '\n';
		for (auto itt : g[i]) {
			cout << itt.first << ' ' << itt.second << '\n';
		}
	}
}

signed main () {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(),cin.tie(0);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	
	if (n <= 500 && m <= 1000) {
		solve1();
	} else {
		solve2();
	}
//	solve3();
	

	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
