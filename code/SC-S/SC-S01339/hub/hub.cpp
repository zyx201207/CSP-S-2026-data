#include <bits/stdc++.h>
#define int long long
#define inf (int)1e18
#define ios ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
//#define i128 __int128_t
const int N = 15, LG = 8;
int n, k;
vector<int> g[N];
int dep[N], up[N][LG];
void dfs(int u, int fa){
	dep[u] = dep[fa] + 1;
	up[u][0] = fa;
	for(int i = 1;i <LG;i ++)up[u][i] = up[up[u][i - 1]][i - 1];
	for(int v : g[u]){
		if(v == fa)continue;
		dfs(v, u);
	}
}
int lca(int u, int v){
	if(dep[u] < dep[v])swap(u, v);
	for(int i = LG - 1;i >= 0;i --){
		if(dep[u] - (1 << i) >= dep[v])u = up[u][i];
		
	}
	if(u == v)return u;
	for(int i = LG - 1;i >= 0;i --){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}
int dis(int u, int v){
	return dep[u] + dep[v] - 2 * dep[lca(u, v)] + 1;
}
bool vis[N];
bool ck(vector<int> nv){
	for(int v : nv)vis[v] = 1;
	return true;
}
void _std(){
	cin >> n >> k;
	for(int i = 1;i <= n;i ++)g[i].clear();
	for(int i = 1;i < n;i ++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 0);
	int ans = inf;
	for(int msk = 1;msk < (1 << n);msk ++){
		vector<int> nv;
		for(int i = 0;i < n;i ++){
			
			if(msk >> i & 1){
				nv.push_back(i + 1);
			}
		}
		if(!ck(nv))continue;
		int mx = 0;
		for(int i = 1;i <= n;i ++){
			int val = inf;
			for(int vv : nv){
				int nd = dis(i, vv);
				val = min(val, nd);
			}
			mx = max(mx, val);
		}
		ans = min(ans, mx);
	}
	cout << ans << "\n";
}
signed main(){
//	ios;
//    freopen("data.in", "r", stdin);
//	freopen("data.out", "w", stdout);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
    int c, t;
	cin >> c >> t;
	while(t --){
		_std();
	}
    return 0;
}
// g++ std.cpp -o std