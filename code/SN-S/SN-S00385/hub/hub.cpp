#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 4010;

int c, T, n, ke, flag[maxn][maxn], father[maxn], deep[maxn], maxx, wei, add[maxn], ans, dpst[maxn];
vector<int>mapp[maxn];

void dfs(int now)
{
	deep[now] = deep[father[now]] + 1;
	dpst[now] = deep[now];
	if (deep[now] > maxx)
	{
		maxx = deep[now];
		wei = now;
	}
	for (int i = 0; i < mapp[now].size(); i++)
	{
		int nxt = mapp[now][i];
		if (father[now] == nxt)  continue;
		if (flag[now][nxt])  continue;
		father[nxt] = now;
		dfs(nxt);
		dpst[now] = max(dpst[now], dpst[nxt]);
	}
	return;
}

void get(int root)
{
	maxx = 0; father[root] = 0;
	dfs(root);
	maxx = 0; father[wei] = 0;
	dfs(wei);
	int ret = wei, len = maxx / 2;
	while (len--)  ret = father[ret];
	father[ret] = 0; dfs(ret);
	return;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--)
	{
		ans = 1e9;
		cin >> n >> ke;
		for (int i = 1; i <= n; i++)  mapp[i].clear(), father[i] = 0;
		for (int i = 1; i < n; i++)
		{
			int u, v; cin >> u >> v;
			mapp[u].push_back(v);
			mapp[v].push_back(u);
		}
		for (int i = 1; i <= n; i++)  add[i] = 0;
		get(1);
		for (int i = 1; i <= n; i++)
		{
			int thi = dpst[i] - deep[i];
			add[thi]++;
		}
		for (int i = n; i >= 0; i--)
		{
			add[i] += add[i + 1];
			if (add[i] <= ke)  ans = min(ans, i);
		}
		for (int k = 1; k <= n; k++)  for (int j = 0; j < mapp[k].size(); j++)
		{
			int nxt = mapp[k][j];
			if (k > nxt)  continue;
			flag[k][nxt] = flag[nxt][k] = 1;
			for (int i = 1; i <= n; i++)  add[i] = 0;
			get(k);
			get(nxt);
			for (int i = 1; i <= n; i++)
			{
				int thi = dpst[i] - deep[i];
				add[thi]++;
			}
			for (int i = n; i >= 0; i--)
			{
				add[i] += add[i + 1];
				if (add[i] <= ke)  ans = min(ans, i);
			}
			flag[k][nxt] = flag[nxt][k] = 0;
		}
		cout << ans << "\n";
	}
	return 0;
}
