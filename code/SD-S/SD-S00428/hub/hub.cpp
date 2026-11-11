#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

//#define LOCAL
#define SIZE (1 << 20)

#ifndef LOCAL
	char in[SIZE], *p1, *p2;
	#define getchar() (p1 == p2 && (p2 = (p1 = in) + fread(in, 1, SIZE, stdin)), p1 == p2 ? EOF : *p1 ++)
#endif

int read(){
	int x = 0, f = 1, ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	} while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar();
	} return x * f;
}

const int N = 1e2 + 10;
int c, t, n, k, ans;
int a[N], f[N];
int cntd, fa[N], dfn[N], dep[N], top[N], siz[N], son[N];
vector<int> e[N];
pair<int, int> eg[N];

void dfs1(int pre, int u){
	dep[u] = dep[pre] + 1;
	siz[u] = 1; fa[u] = pre;
	for(auto v : e[u]){
		if(v == pre) continue;
//		cout << u << " " << v << "??\n";
		dfs1(u, v); siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int pre, int u){
	top[u] = pre, dfn[u] = ++ cntd;
	if(!son[u]) return;
	dfs2(pre, son[u]);
	for(auto v : e[u])
		if(!dfn[v]) dfs2(v, v);
}
 
int find(int x){ return f[x] == x ? x : f[x] = find(f[x]); }

int LCA(int x, int y){
	while(top[x] != top[y]){
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	} if(dep[x] > dep[y]) swap(x, y);
	return x;
}

void dfs(int u, int cnt){
	if(cnt == k){
		int res = 0;
		for(int i = 1; i <= n; ++ i)
			f[i] = i;
		for(int i = 1; i < n; ++ i){
			int u = eg[i].first, v = eg[i].second;
			u = find(u), v = find(v);
			if(u == v) continue;
			f[u] = v;
		} int sum = 0;
		for(int i = 1; i <= n; ++ i){
			if(a[i] && find(i) == i) ++ sum;
		} if(sum > 2) return;
		for(int i = 1; i <= n; ++ i){
			if(a[i]) continue;
			int mn = (1ll << 60);
			for(int j = 1; j <= n; ++ j){
				if(!a[j]) continue;
				mn = min(mn, dep[i] + dep[j] - dep[LCA(i, j)]);
			} res += mn;
		} ans = min(ans, res);
		return;
	} if(u == n + 1) return;
	dfs(u + 1, cnt);
	a[u] = 1;
	dfs(u + 1, cnt + 1);
	a[u] = 0;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	c = read(), t = read();
	while(t --){
		n = read(), k = read(); cntd = 0;
		for(int i = 1; i <= n; ++ i)
			e[i].clear();
		memset(dfn, 0, sizeof dfn);
		memset(fa, 0, sizeof fa);
		memset(top, 0, sizeof top);
		memset(siz, 0, sizeof siz);
		memset(dep, 0, sizeof dep);
		memset(son, 0, sizeof son);
		for(int i = 1, u, v; i < n; ++ i){
			u = read(), v = read();
			e[u].pb(v); e[v].pb(u);
			eg[i] = {u, v};
		} dfs1(0, 1); dfs2(1, 1);
		ans = (1ll << 60);
		dfs(1, 0); cout << ans << "\n";
	}
	
	return 0;
}

