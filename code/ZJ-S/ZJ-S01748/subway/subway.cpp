#include <bits/stdc++.h>
using namespace std;
#define int long long
//constexpr int N = 501, M = 5e5+1, Q = 1e5+1, inf = 0x3f3f3f3f3f3f3f3f;
constexpr int N = 505, M = 5e5+5, Q = 1e5+5, inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, D, q, w[M], k[N]; bool vis[M]; vector<int> a[N], t[N], d[M];
struct grp{
	int b, t;
	bool operator < (const grp &x) const{
		return t < x.t;
	}
}; vector<grp> e[M], g[N]; // buhuiyong bitset www
inline void dij(int x){
	if (vis[x]) return ; vis[x] = 1; d[x].resize(n+1);
	for (int i = 1; i <= n; i++) d[x][i] = inf;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= k[i]; j++) if (a[i][j] == x) d[x][i] = t[i][j];
	priority_queue<grp> q;
	for (int i = 1; i <= n; i++) if (d[x][i] != inf) q.push({i, d[x][i]});
	while (!q.empty()){
		int u = q.top().b, p = q.top().t; q.pop(); if (p > d[x][u]) continue;
		for (grp nxt : g[u]){ int v = nxt.b, w = nxt.t; if (d[x][v] > d[x][u]+w) q.push({v, d[x][v] = d[x][u]+w}); }
	}
}
inline int slv(int x, int y){
	dij(x); dij(y); int ans = inf;
	for (int i = 1; i <= n; i++) ans = min(ans, d[x][i]+d[y][i]);
	return ans+w[x]+w[y];
}
signed main(){
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> D >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++){
		cin >> k[i]; a[i].resize(k[i]+1), t[i].resize(k[i]+1);
		for (int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j], e[a[i][j]].push_back({i, t[i][j]});
	} for (int i = 1; i <= m; i++){
		int nk = e[i].size(); for (int j = 0; j < nk; j++) for (int p = j+1; p < nk; p++){
			int u = e[i][j].b, v = e[i][p].b, w = e[i][j].t+e[i][p].t; 
			g[u].push_back({v, w}), g[v].push_back({u, w});
		}
	} while (q--){ int x, y; cin >> x >> y; cout << slv(x, y) << "\n"; }
	return 0;
}

