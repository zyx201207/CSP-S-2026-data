#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 6;
int n, k, ans, cnt;
vector< int > G[N];
int f[N], mi, b;
int clac(int u, int pre)
{
	int res = n;
	if (f[u])
	{
		return 0;
	}
	for (auto v : G[u])
	{
		if (v != pre)
		{
			res = min(res, clac(v, u) + 1);
		}
	}
	return res;
}
bool check(int u, int pre)
{
	if (!f[pre] && f[u])
	{
		b++;
	}
	if (b > 2)
	{
		return 0;
	}
	for (auto v : G[u])
	{
		if (v != pre)
		{
			if (!check(v, u))
			{
				return 0;
			}
		}
	}
	return 1;
}
void dfs(int step)
{
	if (step == k + 1)
	{
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			res = max(res, clac(i, 0));
		}
		b = 0;
		if (check(1, 0))
		{
			ans = min(ans, res);
		}
	}
	int tmp = mi;
	for (int i = mi; i <= n; i++)
	{
		if (!f[i])
		{
			f[i] = 1;
			mi = i + 1;
			dfs(step + 1);
			mi = tmp;
			f[i] = 0;
		}
	}
}
signed main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
	int Case, T;
	cin >> Case >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			G[i].clear();
		}
		for (int i = 1, u, v; i < n; i++)
		{
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		if (k >= n)
		{
			cout << 0;
			continue;
		}
		ans = n;
		mi = 1;
		dfs(1);
		cout << ans << "\n";
	}
    return 0;
}
