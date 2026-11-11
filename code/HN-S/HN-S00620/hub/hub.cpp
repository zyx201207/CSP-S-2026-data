#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int c, t, n, k, f[N], ans = 1e9;
bool vis[N], v2[N], v3[N];
vector<int> g[N], pr;
queue<int> q;
void dfs2(int x){
	vis[x] = 1;
	for(auto p : g[x]){
		if(!vis[p] && v3[p]) dfs2(p);
	}
}
void dfs(int x){
	if(x > n){
		if(pr.size() != k) return ;
		int sum = 0;
		for(auto p : pr) v3[p] = 1;
		for(auto p : pr){
			if(!vis[p]) dfs2(p), sum++;
		}
		for(int i = 1; i <= n; i++) vis[i] = 0, v3[i] = 0;
		if(sum <= 2){
			for(auto p : pr) q.push(p), f[p] = 0, v2[p] = 1;
			while(q.size()){
				int u = q.front();
				q.pop();
				for(auto p : g[u]){
					if(!v2[p]) f[p] = f[u] + 1, v2[p] = 1, q.push(p);
				}
			}
			int mx = 0;
			for(int i = 1; i <= n; i++) mx = max(mx, f[i]);
			ans = min(ans, mx);
			for(int i = 1; i <= n; i++) f[i] = 0, v2[i] = 0;
		}
		return ;
	}
	dfs(x + 1);
	pr.push_back(x);
	dfs(x + 1);
	pr.pop_back();
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		ans = 1e9;
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v), g[v].push_back(u);
		}
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}
