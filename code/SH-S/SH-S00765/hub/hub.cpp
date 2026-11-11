#include <bits/stdc++.h>
using namespace std;
int C, t, n, k, ok[20], fa[20], mn;
vector<int>g[20];
void dfs0(int now, int pre){
	fa[now] = pre;
	for (int i = 0; i < g[now].size(); i++){
		int nxt = g[now][i];
		if (nxt == pre){
			continue;
		}
		dfs0(nxt, now);
	}
}
void dfs(int now, int pre, int dep){
	if (ok[now]){
		mn = min(mn, dep);
	}
	for (int i = 0; i < g[now].size(); i++){
		int nxt = g[now][i];
		if (nxt == pre){
			continue;
		}
		dfs(nxt, now, dep + 1);
	}
}
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> C >> t;
	while (t--){
		cin >> n >> k;
		for (int i = 1; i <= n; i++){
			g[i].clear();
		}
		for (int i = 1; i < n; i++){
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs0(1, 0);
		int ans = 1e9;
		for (int i = 1; i < (1 << n); i++){
			int c = 0;
			for (int j = 0; j < n; j++){
				if (i >> j & 1){
					c++;
				}
			}
			if (c != k){
				continue;
			}
			for (int j = 0; j < n; j++){
				ok[j + 1] = (i >> j & 1);
			}
			int cnt = 0;
			for (int j = 1; j <= n; j++){
				if (ok[j] && (!ok[fa[j]])){
					cnt++;
				}
			}
			if (cnt > 2){
				continue;
			}
			int res = 0;
			for (int j = 1; j <= n; j++){
				mn = 1e9;
				dfs(j, 0, 0);
				res = max(res, mn);
			}
			ans = min(ans, res);
		}
		cout << ans << '\n';
	}
	return 0;
}
