#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 10;
int n, k;
vector <int> g[N];
int c[N];
bool vis[N];
void con(int x, int fa)
{
	vis[x] = 1;
	for (int i = 0; i < g[x].size(); i++)
	{
		if (c[g[x][i]] == 0 || g[x][i] == fa) continue;
		con(g[x][i], x);
	}
}
int minn = 1e9, maxn = 0;
void calc(int x, int fa, int num)
{
	if (minn <= num) return;
	if (c[x] == 1) 
	{
		minn = min(minn, num);
		return;
	}
	for (int i = 0; i < g[x].size(); i++)
	{
		if (g[x][i] == fa) continue;
		calc(g[x][i], x, num + 1);
	}
}
void solve()
{
	maxn = 0;
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (c[i] == 0) continue;
		if (vis[i] == 0)
		{
			con(i, 0);
			if (++cnt > 2) 
			{
				maxn = 1e9;
				return;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (c[i]) continue;
		minn = 1e9;
		calc(i, 0, 0);
		maxn = max(maxn, minn);
	}
}
int ans = 1e9;
void dfs(int step)
{
	if (step > n)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += c[i];
		if (cnt != k) return;
		solve();
		ans = min(ans, maxn);
		return;
	}
	c[step] = 1;
	dfs(step + 1);
	c[step] = 0;
	dfs(step + 1);
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c, T;
	cin >> c >> T;
	while(T--)
	{
		cin >> n >> k;
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		ans = 1e9;
		dfs(1);
		cout << ans << endl;
	}
	return 0;
}
