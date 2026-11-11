#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t, n, k, f[1000010], vis[1000010];
vector<int> g[1000010];
void color(int p, int fa){
	f[p] = 2;
	for (auto it : g[p]){
		if (it == fa || !f[it])
			continue;
		color(it, p);
	}
}
int dfs(int p, int fa, int dis){
	if (f[p])
		return dis;
	if (vis[p])
		return 1e18;
	vis[p] = 1;
	int res=1e18;
	for (auto it : g[p]){
		if (it == fa)
			continue;
		res = min(res, dfs(it, p, dis+1));
	}
	return res;
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> k;
		for (int i=1; i<=n; i++)
			g[i].clear();
		for (int i=1, u, v; i<n; i++){
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if (c <= 3){
			int ans=1e18;
			for (int i=0; i<(1<<n); i++){
				if (__builtin_popcount(i) != k)
					continue;
				for (int j=1; j<=n; j++)
					f[j] = 0;
				int cnt=0;
				for (int j=1; j<=n; j++)
					if (i & (1 << j - 1))
						f[j] = 1;
				for (int j=1; j<=n; j++){
					if (f[j] == 1){
						color(j, 0);
						++cnt;
					}
				}
				if (cnt > 2)
					continue;
				int w=0;
				for (int j=1; j<=n; j++){
					for (int t=1; t<=n; t++)
						vis[t] = 0;
					w = max(w, dfs(j, 0, 0));
				}
				ans = min(ans, w);
			}
			cout << ans << '\n';
		}
		else
			cout << n / (k * 2) - 1 << '\n';
	}
}