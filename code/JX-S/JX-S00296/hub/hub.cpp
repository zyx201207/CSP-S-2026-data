#include <iostream>
#include <vector>
#include <cstring> 
#define fi first
#define se second
using namespace std;
const int N = 1005, inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair <int, int> pll;
int c, t;
int n, k;
bool s, h;
vector <int> g[N];
int f[N], dep[N], w[N], root, dis[N];
void get_dep(int x, int fa){
	dep[x] = 1;
	for(auto u : g[x]){
		if(u == fa) continue;
		dis[u] = dis[x] + 1;
		get_dep(u, x);
		dep[x] = max(dep[x], dep[u] + 1);
	}
}
void dfs(int x, int fa, int d, int p){
	f[x] = 0;
	if(dep[x] > d) f[x] = 1;
	int mx = 0, Mn = 0;
	for(auto u : g[x]){
		if(u == fa) continue ;
		if(dep[u] > mx) Mn = mx, mx = dep[u];
		else if(dep[u] > Mn) Mn = dep[u];
	}
	for(auto u : g[x]){
		if(u == fa) continue;
		if(dep[u] == mx) dfs(u, x, d, max(p, Mn) + 1);
		else dfs(u, x, d, max(p, mx) + 1);
		f[x] += f[u];
	}
	if(p <= d){
		if(s) w[dis[x]] = min(w[dis[x]], f[x]);
		else if(dis[x] + 1 <= d * 2 && f[x] + w[d * 2 - (dis[x] + 1)] <= k){ h = true ; }
	}
}
bool check(int x){
	for(int i = 1; i <= n; i++){
		for(auto u : g[i]){
			dis[u] = dis[i] = 0;
			get_dep(i, u), get_dep(u, i);
			for(int j = 0; j <= n; j++) w[j] = inf;
			h = false ;
			s = true ;
			dfs(i, u, x, 0);
			for(int j = 1; j <= n; j++) w[j] = min(w[j - 1], w[j]);
			s = false;
			dfs(u, i, x, 0);
			//if(h){ cout << i << " " << u << " " << x << "---\n"; }
			if(h) return true;
		}
	}
	return false;
}
void solve(){
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int l = 0, r = n / 2, res = n / 2;
	while(l <= r){
		int mid = (l + r) >> 1;
		if(check(mid)) res = mid, r = mid - 1;
		else l = mid + 1;
	}
	//check(2);
	cout << res << "\n";
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
