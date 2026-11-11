#include <bits/stdc++.h>
using namespace std;
const int N = 1010, inf = 0x3f3f3f3f;
int n, k, dp[N][N], sz[N], f[N], mi[N], fa[N], tp[N], now;
vector<int> e[N];
bool vis[N];
void dfs(int u, int fath)
{
//	cout << "dfs :" << u << ' ' << fath << '\n';
	tp[u] = now;
	fa[u] = fath;
	sz[u] = 1;
	dp[u][0] = 0;
	dp[u][1] = 0;
	for(int v : e[u])
	{
		if(v == fath) continue;
		dfs(v, u);
		for(int i = 0; i <= min(sz[u], k); i ++) f[i] = dp[u][i];
		dp[u][0] = max(dp[v][0] + 1, dp[u][0]);
		for(int i = 1; i <= min(k, sz[u] + sz[v]); i ++)
		{
			dp[u][i] = max(dp[v][0] + 1, f[i]);
			for(int j = 1; j < i && j <= min(sz[v], k); j ++)
				dp[u][i] = min(dp[u][i], max(f[i - j], dp[v][j]));
		}
		sz[u] += sz[v];
	}
//	cout << "u : " << u << '\n';
//	for(int i = 0; i <= k; i ++) cout << dp[u][i] << ' ';
//	cout << '\n';
}
int get(int u, int v)
{
//	cout << "get: " << u << ' ' << v << '\n';
//	if(u != 3 || v != 2) return inf;
	memset(vis, 0, sizeof vis);
	memset(mi, 0, sizeof mi);
	for(int i = 1; i <= n; i ++) mi[u] = vis[u] = 0;
	vis[u] = vis[v] = 1;
	queue<pair<int, int>> q;
	vis[fa[u]] = 1, vis[fa[v]] = 1;
	int mx = 0;
	if(fa[u] != v && fa[v] != u)
	{
		mi[fa[u]] = mi[fa[v]] = 1;
		q.push({fa[u], 1});
		q.push({fa[v], 1});
	}
	while(!q.empty())
	{
		pair<int, int> p = q.front(); q.pop();
		int u = p.first, d = p.second;
//		cout << u << '\n';
		for(int v : e[u])
		{
			if(vis[v]) continue;
			vis[v] = 1;
			mi[v] = d + 1;
			q.push({v, d + 1});
		}
	}
	for(int i = 1; i <= n; i ++) mx = max(mx, mi[i]);
//	cout << "mx: " << mx << '\n';
	int ans = inf;
	for(int i = 1; i < k; i ++)
		ans = min(ans, max(mx, max(dp[u][i], dp[v][k - i])));
//	cout << "RES: " << ans << '\n';
	return ans;
}
void solve()
{
	cin >> n >> k;
	for(int i = 1; i < n; i ++)
	{
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	int ans = inf;
	for(int u = 1; u <= n; u ++)
	{
		for(int v : e[u])
		{
			if(u > v) continue;
			memset(dp, 0x3f, sizeof dp);
			memset(sz, 0, sizeof sz);
			now = 1;
			dfs(u, v);
			now = 2;
			dfs(v, u);
			for(int i = 1; i <= n; i ++)
			{
				for(int j = 1; j <= n; j ++)
				{
					if(tp[i] == tp[j] || i >= j) continue;
					ans = min(ans, get(i, j));
				}
			}
		}
	}
	cout << ans << '\n';
	for(int i = 1; i <= n; i ++) e[i].clear();
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int c, t;
	cin >> c >> t;
	while(t --) solve();
	return 0;
}
