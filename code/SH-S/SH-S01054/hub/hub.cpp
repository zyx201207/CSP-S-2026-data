#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const int maxn = 2e6 + 7;

int c, t, ans = 0;
vector<vector<int> > g;
vector<bool> vis(maxn, false);
vector<int> dis(maxn, 0), fa(maxn, 0);

inline int dfs(int u) {
	vis[u] = true;
	for(auto v : g[u]) {
		if(vis[v]) continue;
		dis[v] = dis[u] + 1;
		fa[v] = u;
		dfs(v); 
	}
	for(auto i : g[u]) {
		ans = max(ans, dis[i]);
	}
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		cout << ans << "\n";
	}
	return 0;
} 
