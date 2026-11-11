#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e3 + 10;
vector <int> adj[MAXN];
int dis[MAXN][MAXN], n, k, ans;
bool flag[MAXN], g[MAXN][MAXN];
void dfs(int st, int u, int p, int d){
	dis[st][u] = d;
	for (int v : adj[u]){
		if (v == p){
			continue;
		}
		dfs(st, v, u, d + 1);
	}
	return;
}
void calc(int u, int cnt, int o){
	if (u > n){
		if (cnt != k){
			return;
		}
		int maxn = 0;
		for (int i = 1; i <= n; i++){
			if (flag[i]){
				continue;
			}
			int minn = 1e9;
			for (int j = 1; j <= n; j++){
				if (flag[j]){
					minn = min(minn, dis[i][j]);
				}
			}
			maxn = max(maxn, minn);
		}
		ans = min(ans, maxn);
		return;
	}
	if (cnt <= k){
		for (int i = 1; i <= n; i++){
			if (flag[i]){
				continue;
			}
			bool ok = false;
			for (int j = 1; j <= n; j++){
				if (flag[j] && g[i][j]){
					ok = true;
					break;
				}
			}
			if (ok){
				flag[i] = true;
				calc(u + 1, cnt + 1, o);
				flag[i] = false;
			}
			else if (o <= 1){
				flag[i] = true;
				calc(u + 1, cnt + 1, o + 1);
				flag[i] = false;
			}
		}
	}
	calc(u + 1, cnt, o);
	return;
}
void solve(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		adj[i].clear();
	}
	memset(g, false, sizeof(g));
	for (int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		g[u][v] = g[v][u] = true;
	}
	for (int i = 1; i <= n; i++){
		dfs(i, i, 0, 0);
	}
	ans = 1e9;
	calc(1, 0, 0);
	cout << ans << "\n";
	return;
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--){
		solve();
	}
	return 0;
}