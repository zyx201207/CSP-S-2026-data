#include <bits/stdc++.h>
using namespace std;
bool M1;
const int N = 1e6 + 10;
const int inf = 1e9;
int c, T, n, k, d, cnt, dist[N], node[N], f[N], g[N];
vector<int> G[N];
namespace D {
int fa[N], dep[N];
void dfs(int u, int fno){
	fa[u] = fno, dep[u] = dep[fno] + 1;
	for (int v : G[u]){
		if (v != fno) dfs(v, u);
	}
}
}
void init(){
	D::dfs(1, 0);
	int rt = - 1;
	for (int i = 1; i <= n; i++){
		if (rt == - 1 || D::dep[i] > D::dep[rt]) rt = i;
	}
	D::dfs(rt, 0);
	int k = - 1;
	for (int i = 1; i <= n; i++){
		if (k == - 1 || D::dep[i] > D::dep[k]) k = i;
	}
	d = D::dep[k], node[0] = 0;
	do {
		node[++ node[0]] = k, k = D::fa[k];
	} while (k) ;
	node[0] = 0;
}
void dfs(int u, int fno, int id, int x){
	dist[u] = 0;
	for (int v : G[u]){
		if (v != fno && v != node[id - 1] && v != node[id + 1]){
			dfs(v, u, id, x), dist[u] = max(dist[u], dist[v] + 1);
		}
	}
	if (dist[u] > x) ++ cnt;
}
bool check(int x){
	for (int i = 1; i <= d; i++){
		cnt = 0, dfs(node[i], 0, i, x);
		if (i <= x + 1) f[i] = 1; 
		else f[i] = f[i - 1] + cnt + (dist[node[i]] <= x ? 1 : 0);	
	}
	for (int i = d; i >= 1; i--){
		cnt = 0, dfs(node[i], 0, i, x);
		if (i >= d - x) g[i] = 1;
		else g[i] = g[i + 1] + cnt + (dist[node[i]] <= x ? 1 : 0);
	}
	if (f[d - x] <= k) return true;
	for (int i = 1, j; i < d - x; i++){
		if (f[i] > k) return false;
		j = i + 1;
		int o = inf;
		while (j < d){
			if (dist[node[j]] + j - i > x) o = min(o, x - dist[node[j]] + j);
			if (j + 1 > o) break; j ++ ;
		}
		if (f[i] + g[j] <= k) return true;
	}
	return false;
}
void solve(){
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++){
		cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
	}
	init();
	int l = 1, r = (d - 1) / 2, res = d / 2;
	while (l <= r){
		int md = l + r >> 1;
		if (check(md)) res = md, r = md - 1;
		else l = md + 1;
	}
	cout << res << '\n' ;
	for (int i = 1; i <= n; G[i ++].clear() ) ;
}
bool M2;
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> T;
	while (T --> 0) solve();
	cerr << 1000 * clock() / CLOCKS_PER_SEC << " MS\n" ;
	cerr << 1.0 * fabs(&M1 - &M2) / 1024 / 1024 << " MB\n" ;
	return 0;
}
