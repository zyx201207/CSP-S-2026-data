#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf = 0x3f3f3f3f3f3f3f3f;
int C, n, k, use[1000005], vis[1000005], dis[1000005], ans;
vector<int> g[1000005];
void dfs2(int u){
	vis[u] = 1;
	for(int i = 0; i < g[u].size(); i ++){
		int v = g[u][i];
		if(use[v] && !vis[v]){
			dfs2(v);
		}
	}
}
void check(){
	for(int i = 1; i <= n; i ++){
		vis[i] = 0; dis[i] = inf;
	}
	int tot = 0;
	for(int i = 1; i <= n; i ++){
		if(use[i] && !vis[i]){
			dfs2(i);
			tot ++;
		}
	}
	if(tot > 2) return;
	int maxn = 0; queue<int> q;
	for(int i = 1; i <= n; i ++){
		if(use[i]) q.push(i), dis[i] = 0;
	}
	while(q.size()){
		int u = q.front(); q.pop();
		for(int i = 0; i < g[u].size(); i ++){
			int v = g[u][i];
			if(dis[v] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				q.push(v); maxn = max(maxn, dis[v]);
			}
		}
	}
	ans = min(ans, maxn);
}
void dfs(int stp, int sum){
	if(stp == n + 1){
		if(sum == k) check();
		return;
	}
	if(n - stp + sum >= k){
		use[stp] = 0;
		dfs(stp + 1, sum);
	}
	if(sum < k){
		use[stp] = 1;
		dfs(stp + 1, sum + 1);
	}
}
void Solve(int Case){
	cin >> n >> k; ans = inf; for(int i = 1; i <= n; i ++) g[i].clear();
	int flag = (n & 1);
	for(int i = 1; i < n; i ++){
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		if((i <= n / 2 && (u != i || v != i + 1)) || (i > n / 2 && (u != i - n / 2 && v != i + 1))) flag = 0;
	}
	if(n <= 10){
		dfs(1, 0);
		cout << ans << "\n";
		return;
	}
	if(flag) cout << max(((n + 1) / 2 - k + 4) / 4, 0LL);
	else{
		dfs(1, 0);
		cout << ans << "\n";
	}
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> C >> t;
	for(int i = 1; i <= t; i ++){
		Solve(i);
	}
	return 0;
}
