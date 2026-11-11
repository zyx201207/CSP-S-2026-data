#include<bits/stdc++.h>
using namespace std;
int g, t, n, k, d[4010][4010], c[4010], ff[4010], ans;
vector<int> e[4010];
void dfs(int u, int fa, int f) {
	for(auto v : e[u]) {
		if(v == fa)
			continue;
		d[f][v] = d[f][u] + 1;
		dfs(v, u, f);
	}
}
int find(int u) {
	if(u == ff[u])
		return u;
	return ff[u] = find(ff[u]);
}
void solve(int x) {
	if(x == k + 1) {
		int cnt = 0;
		bool vis[4010];
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++)
			ff[i] = i;
		for(int i = 1; i <= k; i++)
			for(int j = 1; j <= k; j++)
				if(i != j && d[c[i]][c[j]] == 1)
					ff[find(c[i])] = find(c[j]);
		for(int i = 1; i <= k; i++)
			if(!vis[ff[c[i]]])
				cnt++, vis[ff[c[i]]] = 1;
		if(cnt > 2)
			return;
		int mx = 0;
		for(int i = 1; i <= n; i++) {
			int mn = 1e9;
			for(int j = 1; j <= k; j++)
				mn = min(mn, d[i][c[j]]);
			mx = max(mx, mn);
		}
		ans = min(ans, mx);
		return;
	}
	for(int i = c[x - 1] + 1; i <= n; i++) {
		c[x] = i;
		solve(x + 1);
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> g >> t;
	while(t--) {
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			e[i].clear();
		for(int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		memset(d, 0, sizeof(d));
		for(int i = 1; i <= n; i++)
			dfs(i, 0, i);
		ans = 1e9;
		solve(1);
		cout << ans << '\n';
	}
	return 0;
}