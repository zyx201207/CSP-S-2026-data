#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10 + 5;

bool vis[N], chs[N];
vector <int> g[N];
int c, T, n, k, ans, cnt, co[N];

void clear()
{
	ans = 1e9;
	cnt = 0;
	for (int i = 1; i <= n; i++)
		g[i].clear();
	memset (vis, false, sizeof vis);
	memset (co, 0, sizeof co);
	memset (chs, false, sizeof chs);
}

void dfs (int u)
{
	co[u] = cnt;
	for (int v : g[u])
	{
		if (co[v])	continue;
		dfs (v);
	}
}

bool check2 (int mask)
{
	cnt = 0;
	memset (co, 0, sizeof co);
	for (int u = 1; u <= n; u++)
		if (!co[u] && (mask >> u - 1) & 1)
		{
			cnt++;
			dfs (u);
		}
	return cnt <= 2;
}

int dfs (int u, int step)
{
	int res = 20;
	vis[u] = true;
	if (chs[u])	return step;
	for (int v : g[u])
	{
		if (vis[v])	continue;
		res = min (res, dfs (v, step + 1));
	}
	return res;
}

int calc (int mask)
{
	int mx = 0;
	memset (chs, false, sizeof chs);
	for (int u = 1; u <= n; u++)
		if ((mask >> u - 1) & 1)	chs[u] = true;
	for (int u = 1; u <= n; u++)
	{
		memset (vis, false, sizeof vis);
		mx = max (mx, dfs (u, 0));
	}
	return mx;
}

void mian()
{
	clear();
	cin >> n >> k;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int mask = 0; mask < (1 << n); mask++)
	{
		if (__builtin_popcount (mask) != k)	continue;
		if (!check2 (mask))	continue;
		ans = min (ans, calc (mask));
	}
	cout << ans << "\n";
}

signed main()
{
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--)	mian();
	return 0;	
} 
