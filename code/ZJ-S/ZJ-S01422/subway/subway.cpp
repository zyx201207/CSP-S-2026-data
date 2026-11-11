#include <bits/stdc++.h>
using namespace std;
int a[500005], st, ed, ans = 10002221 * 101;
int cnt[500005];
bool vis[500005];
bool visl[505];
vector < int > vs[505];
vector < int > vt[505];
vector < int > vl[500005];
vector < int > :: iterator it;
vector < int > :: iterator itt;
void dfs(int x, int lin, int ti, int ch)
{
	if (x == ed)
	{
		int t = 0;
		for (it = vs[lin].begin(); it != vs[lin].end(); it++)
		{
			if (*it == x) 
			{
				itt = vt[lin].begin() + (it - vs[lin].begin());
				t += *itt;
			}
		}
		ans = min(ans, ti + t);
		return;
	}
	if (ch == 1)
		for (auto i : vl[x])
		{
			int t = 0;
			for (it = vs[i].begin(); it != vs[i].end(); it++)
			{
				if (*it == x) 
				{
					itt = vt[i].begin() + (it - vs[i].begin());
					t += *itt;
				}
			}
			for (it = vs[lin].begin(); it != vs[lin].end(); it++)
			{
				if (*it == x) 
				{
					itt = vt[lin].begin() + (it - vs[lin].begin());
					t += *itt;
				}
			}
			dfs(x, i, ti + t, 0);
		}
	else
	{
		for (int i : vs[lin])
		{
			if (!vis[i])
			{
				vis[i] = 1;
				dfs(i, lin, ti, 1);
				vis[i] = 0;
			}
		}
	}
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int q, n, m, mxd, pl;
	scanf("%d%d%d%d%d", &q, &n, &m, &mxd, &pl);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int num, t;
			cin >> num >> t;
			vs[i].push_back(num);
			vl[num].push_back(i);
			vt[i].push_back(t);
		}
	}
	for (int i = 1; i <= pl; i++)
	{
		ans = 10002221 * 101.0000;
		memset(vis, 0, sizeof vis);
		scanf("%d%d", &st, &ed);
		dfs(st, 0, a[st] + a[ed], 1);
		printf("%d\n", ans);
	}
	return 0;
}
