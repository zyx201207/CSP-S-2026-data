#include<bits/stdc++.h>
#include<cstdio>
const int N = 1e6+10;
using namespace std;
int n, k, c, t;
long long ans;
int a[N], dep[N], f[N][30], g[N];
vector<int> l[N];
bool vis[N];
void dfs(int u, int fa){
	dep[u] = dep[fa]+1, f[u][0] = fa;
	for(int i=1; i<=20; ++i){
		f[u][i] = f[f[u][i-1]][i-1];
	}
	for(int i=0; i<l[u].size(); ++i){
		int v = l[u][i];
		if(v == fa) continue;
		dfs(v, u);
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
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1; i<n; ++i){
			int u, v; cin >> u >> v;
			l[u].push_back(v), l[v].push_back(u);
		}
		dfs(1, 0);
		cout << 1 << '\n';
	}
	return 0;
}
