#include<bits/stdc++.h>
#include<cstdio>
const int N = 5e5+10;
using namespace std;
int n, m, tot;
struct node{
	int u, v;
	long long w;
}e[N];
struct line{
	int to, val;
};
int a[N], dep[N], f[N][30], g[N];
long long sum[N];
vector<line> l[N];
void dfs(int u, int fa){
	dep[u] = dep[fa]+1, f[u][0] = fa;
	for(int i=1; i<=20; ++i){
		f[u][i] = f[f[u][i-1]][i-1];
	}
	for(int i=0; i<l[u].size(); ++i){
		int v = l[u][i].to, w = l[u][i].val;
		if(v == fa) continue;
		dfs(v, u);
		sum[v] = sum[u]+w; 
	}
	return;
}
int lca(int u, int v){
	if(dep[u]<dep[v]) swap(dep[u], dep[v]);
	int p = dep[u]-dep[v];
	for(int i=20; i+1; --i){
		if(dep[f[u][i]]<dep[v]) u = f[u][i];
	} 
	if(u == v){
		return u;
	}
	for(int i=20; i+1; --i){
		if(f[u][i]!=f[v][i]) u = f[u][i], v = f[v][i];
	}
	return f[u][0];
}
int find(int u){
	if(g[u] == u) return u;
	return g[u]=find(g[u]);
}
bool cmp(node x, node y){
	return x.w < y.w;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int c, d, T;
	cin >> c >> n >> m >> d >> T;
	for(int i=1; i<=m; ++i) cin >> a[i];
	for(int i=1; i<=n; ++i){
		int k; cin >> k;
		for(int j=1; j<=k; ++j){
			int u, t; 
			cin >> u >> t;
			e[++tot].u = m+i, e[tot].v = u, e[tot].w = t;
		}
	}
	for(int i=1; i<=m+n; ++i){
		g[i] = i;
	}
	sort(e+1, e+tot+1, cmp);
	for(int i=1; i<=tot; ++i){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if(find(u)!=find(v)){
			g[find(u)] = find(v);
			l[u].push_back(line{v, w});
			l[v].push_back(line{u, w});
		}
	}
	dfs(1, 0);
	while(T--){
		int u, v; 
		cin >> u >> v;
		int LCA = lca(u, v);
		cout << a[u]+a[v]+sum[u]+sum[v]-2*sum[LCA] << '\n';
	}
	return 0;
}
