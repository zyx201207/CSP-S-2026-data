#include <bits/stdc++.h>
#define INIT(a, n, v) for(int i = 1; i <= n; i++) a[i] = v
#define int long long
using namespace std;
const int N = 2e5 + 5;
int c, t, n, k;
vector<int> e[N];
namespace t1 {
	int hub[N], dis[N], vis[N];
	void dfs(int u){
		for(int v : e[u]){
			if(vis[v] || !hub[v]) continue;
			vis[v] = 1;
			dfs(v);
		}
	}
	void solve1(){
		int ans = 1e9;
		for(int j = 0; j < (1 << n); j++){
			int cnt = 0;
			vector<int> v;
			for(int i = 1; i <= n; i++){
				hub[i] = 0;
				if(j >> (i - 1) & 1){
					hub[i] = 1;
					v.push_back(i);
					cnt++;
				}
			}
			if(cnt != k) continue;
			INIT(vis, n, 0);
			int sum = 0;
			for(auto i : v) if(!vis[i]) dfs(i), sum++;
			if(sum > 2) continue;
			INIT(vis, n, 0);
			INIT(dis, n, 0);
			queue<int> q;
			for(auto i : v) q.push(i), vis[i] = 1;
			int mx = 0;
			while(!q.empty()){
				int u = q.front();
				q.pop();
				for(int v : e[u]){
					if(vis[v]) continue;
					vis[v] = 1;
					dis[v] = dis[u] + 1;
					mx = max(mx, dis[v]);
					q.push(v);
				}
			}
			ans = min(ans, mx);
		}
		cout << ans << "\n";
	}
	
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) e[i].clear();
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	t1::solve1();
}
signed main(){
	freopen("hub2.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}
//0 2
//5 2
//1 2
//2 3
//3 4
//4 5
//10 3
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//3 8
//7 9
//9 10

