#include <bits/stdc++.h>
using ll = long long; using ull = unsigned long long;
const int MAXN = 5e2 + 10, MAXM = 2e5 + 10, MAXD = 30, MAXT = 2e7 + 10;
const int INF32 = INT_MAX; const ll INF64 = LLONG_MAX;
using namespace std;
int c, n/*线路*/, m/*地铁口*/, d, q, tot;
ll k[MAXN], cnt[MAXN], w[MAXN];
unordered_map<int, int> idxK/*地铁口*/, idxTi/*站厅*/, idxTa[MAXN]/*每个站的站台编号*/;
struct Data {
	int a, t;
} DA[MAXN]; 
struct Edge {
	ll v, w;
};
vector<Edge> G[MAXT];
void add(int u, int v, int _w) {
	G[u].emplace_back((Edge){v, _w});
	G[v].emplace_back((Edge){u, _w});
}

using pll = pair<int, ll>;
priority_queue<pll, vector<pll>, greater<pll>> pq;
bitset<MAXT> vis;
ll dis[MAXT]; 
void dij(int s) {
	vis.reset();
	for (int i = 1; i <= tot; i++) dis[tot] = INF64;
	
	
	dis[s] = 0;
	pq.emplace(make_pair(s, 0));
	while (pq.size()) {
		pll f = pq.top(); pq.pop();
		int u = f.first;
		
		if (vis[u]) continue;
		vis[u] = 1;
		
		for (Edge i : G[u]) {
			int v = i.v; ll _w = i.w;
			if (dis[v] > dis[u] + _w) {
				dis[v] = dis[u] + _w;
				pq.emplace(make_pair(v, dis[v]));
			}
		}
	}
}
int main() {
//	using pll = pair<ll, ll>;
//	priority_queue<pll, vector<pll>, greater<pll>> pq;
//	pq.emplace(make_pair(1, 3)), pq.emplace(make_pair(1, 0));
//	while (pq.size()) {
//		cout << pq.top().second << ' ';
//		pq.pop();
//	}
//	return 0;
	
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {// zhan
		cin >> w[i];
		idxK[i] = ++tot, idxTi[i] = ++tot;
		add(idxK[i], idxTi[i], w[i]);
	}
	for (int i = 1; i <= n; i++) {// xian lu
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {// zhan tai
			ll a, t;
			cin >> a >> t;
			DA[j].a = a, DA[j].t = t;
			idxTa[i][a] = ++tot;
			
			add(idxTa[i][a], idxTi[a], t);
		} 
		sort(DA + 1, DA + k[i] + 1, [](Data x, Data y) {
			return x.a < y.a;
		});
		for (int j = 2; j <= k[i]; j++) {
			int a = DA[j].a, b = DA[j - 1].a;
			add(idxTa[i][a], idxTa[i][b], 0);
		}
	}
//	cout << tot;
	
	while (q--) {
		int x, y;
		cin >> x >> y;
//		dij(x);
		cout << dis[y] << '\n';
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

ans:
32
17

*/
