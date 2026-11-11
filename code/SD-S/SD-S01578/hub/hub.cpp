#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(I, A, B) for(int I = (A); I <= (B); I++)
#define den(I, A, B) for(int I = (A); I >= (B); I--)
#define int long long
const int N = 2e6 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;
int fa[N], sz[N];
int n;
int lim;
vector<int> g[N];
bool is[N];
bool vis[N];
void init(){
	rep(i, 1, n) fa[i] = i, sz[i] = 1; 
}
vector<int> vec;
void dfs(int u, int dis, int mid, int f){
	if(dis < mid) is[u] = 1;
	if(dis >= mid) return;
	for(int v : g[u]){
		if(v == f) continue;
		dfs(v, dis + 1, mid, u);
	}
}
vector<int> a;
void dfs2(int u, int dis, int mid, int f){
	if(is[u]) return;
	if(dis < mid && is[u] == 0) is[u] = 1, a.push_back(u);
	if(dis >= mid) return;
	for(int v : g[u]){
		if(v == f) continue;
		dfs2(v, dis + 1, mid, u);
	}
}
int find(int u){
	if(fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if(sz[x] < sz[y]) swap(x, y);
	fa[y] = x;
	sz[x] += sz[y];
}

bool check1(int mid, int u){
	init();
	dfs2(u, 0, mid, 0);
//	rep(i, 1, n) cout << is[i] << " ";
//	cout << endl;
	int cnt = 0;
	rep(i, 1, n) vis[i] = 0;
	rep(i, 1, n) if(is[i] == 0){
		for(int v : g[i]) if(is[v] == 0){
			merge(i, v);
		}
	}
	rep(i, 1, n) if(is[i] == 0) vis[find(i)] = 1;
	rep(i, 1, n) cnt += vis[i];
	int c1 = 0;
//	rep(i, 1, n) cout << is[i] << " ";
	rep(i, 1, n) c1 += !is[i];
//	for(int v : a) cout<< v << " ";
	for(int v : a) is[v] = 0;
	a.clear();
	if(cnt > 2) return 0;
	return c1 <= lim;
}
bool check(int mid){
	rep(i, 1, n) is[i] = 0;
	for(int v : vec){
		dfs(v, 0, mid, 0);
	}
//	rep(i, 1, n) cout << is[i] << " ";
//	cout << endl;
	rep(i, 1, n){
		if(is[i] == 0 && check1(mid, i)) return 1; 
	}
	bool ok = 1;
	rep(i, 1, n){
		if(is[i] == 0) ok = 0;
	}
	return 0 | ok;
}
void solve(){
	vec.clear();
	cin >> n >> lim;
	rep(i, 2, n){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep(i, 1, n) if(g[i].size() == 1) vec.push_back(i);
//	for(int v : vec){
//		cout << v << " ";
//	}
//	cout << endl;
//	cout << endl;
	int l = 0, r = n;
	int ans = n;
	while(l <= r){
		int mid = (l + r) >> 1;
//		cout << mid << endl;
//		cout << endl;
		if(check(mid)){
			r = mid - 1;
			ans = mid;
		}else l = mid + 1;
	}
	cout << ans << endl;
	rep(i, 1, n) g[i].clear();
}
signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0), cin.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t_;
	cin >> c >> t_;
	while(t_--) solve();
	return 0;
}

