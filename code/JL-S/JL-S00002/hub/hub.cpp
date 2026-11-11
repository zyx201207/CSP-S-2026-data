#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n, k;
	cin >> n >> k;
	vector<vector<int>> G(n + 1);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<bool> vis(n + 1, 0);
	vector<int> M(n + 1, 0), dis(n + 1, 0);
	vector<int> mdis(n + 1, 2e9 + 7);
	auto dfs1 = [&](auto &&self, int u, int fa, vector<int> mod)->void{
		vis[u] = 1;
		for (int v : G[u]){
			if (v != fa && mod[v] == 1)
				self(self, v, u, mod);
		}
	};
	auto dfs2 = [&](auto &&self, int u, int fa) -> void{
		for (int v : G[u]){
			if (v != fa){
				dis[v] = dis[u] + 1;
				self(self, v, u);
			}
		}
	};
	
	for (int i = 1; i <= k; i++)M[i] = 1;
	int ans = 2e9 + 7;
	do{
		// cout << "P" << endl;
		int cnt = 0;
		for (int i = 1; i<= n; i++)vis[i] = 0, mdis[i] = 2e9 + 7;
		for (int i = 1; i <= n; i++){
			if (M[i] == 0)continue;
			if (!vis[i]){
				cnt++;
				dfs1(dfs1, i, i, M);
			}
		}
		// cout << cnt << endl;
		if (cnt != 2)continue;
		for (int i = 1; i <= n; i++){
			if (M[i] == 0)continue;
			dis[i] = 0;
			dfs2(dfs2, i, i);
			for (int j = 1; j <= n; j++){
				if (M[j] == 1)mdis[j] = 0;
				else mdis[j] = min(mdis[j], dis[j]);
			}
		}
		int td = -1;
		for (int i = 1; i <= n; i++){
			// cout << i << ' ' << mdis[i] << endl;
			td = max(td, mdis[i]);
		}
		// cout << td << endl;
		ans = min(ans, td);
	}while(prev_permutation(M.begin() + 1, M.end()));
	cout << ans << endl;
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c,t;
	cin >> c>> t;
	while (t--){
		solve();
	}
}
