#include <iostream>
#include <vector>
using namespace std;
int c, t, n, k, hae[2000005], cnt, col[2000005], ans, vis[2000005];
vector<int> e[2000005];
void dfs2(int x)
{
	vis[x] = 1;
	col[x] = 1;
	for (auto g : e[x])
		if (hae[g] == 1 && vis[g] == 0)
			dfs2(g);
}
int dfs1(int x, int stp)
{
	vis[x] = 1;
	if (hae[x] == 1)
		return stp;
	int res = n;
	for (auto g : e[x])
		if (vis[g] == 0)
			res = min(res, dfs1(g, stp + 1));
	return res;
}
void dfs(int x, int nk)
{
	if (x == n + 1 && nk == k)
	{
		for (int i = 1; i <= n; i++)
			col[i] = 0;
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (hae[i] == 1 && col[i] == 0)
			{
				dfs2(i);
				for (int j = 1; j <= n; j++)
					vis[j] = 0;
				cnt++;
			}
		}
		if (cnt > 2)
			return;
		int maxdis = 0;
		for (int i = 1; i <= n; i++)
		{
			maxdis = max(maxdis, dfs1(i, 0));
			for (int j = 1; j <= n; j++)
				vis[j] = 0;
		}
		ans = min(ans, maxdis);
		return;
	}
	if (nk + n - x + 1 < k || nk > k)
		return;
	hae[x] = 0;
	dfs(x + 1, nk);
	hae[x] = 1;
	dfs(x + 1, nk + 1);
}
signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			e[i].clear();
		for (int i = 1, u, v; i < n; i++)
		{
			cin >> u >> v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		ans = n;
		dfs(1, 0);
		cout << ans << endl;
	}
	return 0;
}