#include<bits/stdc++.h>
using namespace std;
const int Maxn  = 1e6 + 5;
int n, m, ans;
int a[Maxn];
vector <int> ve[Maxn];
inline int dis(int st, int ed){
	bool vist[Maxn] = {};
	queue <pair<int, int> > que;
	que.push({st, 0});
	while(!que.empty()){
		pair <int, int> p = que.front();
		que.pop();
		int u = p.first;
		vist[u] = true;
		if(u == ed){
			return p.second;
		}
		for(auto v : ve[u]){
			if(!vist[v]){
				que.push({v, p.second + 1});
			}
		}
	}
}
int vis[Maxn];
inline void dfs1(int u){
	vis[u] = 0;
	for(auto v : ve[u]){
		if(vis[v]){
			dfs1(v);
		}
	}
}
inline bool check(){
	for(int i = 1; i <= n; i++){
		vis[i] = a[i];
	}
	int s = 0;
	for(int i = 1; i <= n; i++){
		if(vis[i]){
			dfs1(i);
			s++;
		}
	}
	return s <= 2;
}
inline void dfs(int dep, int k){
	if(k == m){
		if(check()){
			int j, res = -1;
			for(int i = 1; i <= n; i++){
				if(a[i] == 1){
					j = i;
					break;
				}
			}
			for(int i = 1; i <= n; i++){
				if(a[i] == 1){
					continue;
				}
				res = max(res, dis(i, j));
			}
			ans = min(ans, res);
		}
		return;
	}
	if(dep == n + 1){
		return;
	}
	a[dep] = 1;
	dfs(dep + 1, k + 1);
	a[dep] = 0;
	dfs(dep + 1, k);
}
inline void solve(){
	cin >> n >> m;
	for(int i = 1, u, v; i < n; i++){
		cin >> u >> v;
		ve[u].push_back(v);
		ve[v].push_back(u);
	}
	ans = 1e9;
	dfs(1, 0);
	for(int i = 1; i <= n; i++){
		ve[i].clear();
		a[i] = 0;
	}
	cout << ans - 1 << endl;
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int _, __;
	cin >> _ >> __;
	while(__--){
		solve();
	}
	return 0;
}
