#include <bits/stdc++.h>
#define int long long
using namespace std;
int _, t, n, m, u, v, a[5005], f[5005], vis[5005], ans;
vector<int> e[5005];
void dfs(int x)
{
	vis[x] = 1;
	for (int i : e[x]) if (!vis[i] && f[i]) dfs(i);
}
int dis(int x, int y, int k)
{
	if (x == y) return 0;
	for (int i : e[x]) if (i != k)
	{
		int t = dis(i, y, x);
		if (t != -1) return t + 1;
	}
	return -1;
}
void dfs1(int x, int k)
{
	if (x > n)
	{
		if (k != m) return;
		for (int i = 1; i <= n; i++) vis[i] = 0;
		int s = 0;
		for (int i = 1; i <= n; i++) if (f[i] && !vis[i]) dfs(i), s++;
		if (s > 2) return;
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			s = 0;
			for (int j = 1; j <= m; j++) s += dis(i, 0, a[j]);
			maxn = max(maxn, s);
		}
		ans = min(ans, maxn);
		return;
	}
	if (x - k - 1 < n - m) dfs1(x + 1, k);
	if (k < m) a[k + 1] = x, f[x] = 1, dfs1(x + 1, k + 1), f[x] = 0;
}
signed main()
{
//	freopen("hub.in", "r", stdin);
//	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> _ >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++) e[i].clear();
		for (int i = 1; i < n; i++) {cin >> u >> v; e[u].push_back(v), e[v].push_back(u);}
		memset(f, 0, sizeof f), ans = 1e18, dfs1(1, 0);
		cout << ans << endl;
	}
	return 0;
}
