#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, k;
vector <int> e[N];
int a[N], dis[N], vis[N];
int vis2[N];
void dfs(int u){
	dis[u] = 0;
	vis[u] = 1;
	for (int v : e[u]){
		if (vis[v]) continue;
		if (!a[v]) continue;
		dfs(v);
	}
}
void dfs2(int u){
	vis2[u] = 1;
	for (int v : e[u]){
		if (vis2[v]) continue;
		dis[v] = min(dis[v], dis[u] + 1);
		dfs2(v);
	}
}
void solve(){
	cin >> n >> k;
	int u, v;
	for (int i = 1; i <= n; i ++) e[i].clear();
	for (int i = 1; i < n; i ++){
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int ans = n;
	for (int i = 0; i < (1 << n); i ++){
		int sum = 0;
		for (int j = 1; j <= n; j ++){
			if (i & (1 << (j - 1))){
				a[j] = 1;
				sum ++;
			}
			else a[j] = 0;
			dis[j] = n;
			vis[j] = 0;
		}
		if (sum != k) continue;
		sum = 0;
		for (int j = 1; j <= n; j ++){
			if (a[j] && !vis[j]){
				sum ++;
				if (sum > 2) break;
				dfs(j);
				for (int k = 1; k <= n; k ++) vis2[k] = 0;
				dfs2(j);
			}
		}
		int res = 0;
		if (sum <= 2){
			for (int j = 1; j <= n; j ++){
				res = max(res, dis[j]);
			}
			ans = min(ans, res);
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, T;
	cin >> c >> T;
	while (T --){
		solve();
	}
	return 0;
}
