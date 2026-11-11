#include<bits/stdc++.h>
using namespace std;
#define int long long

int c, t, n, k, l[15], vis[15];
vector<int> a[15];

void dfs(int now)
{
	if (vis[now] || !l[now]) return;
	vis[now] = 1;
	for (int i : a[now])
		dfs(i);
}

int dfs2(int now, int fa)
{
	if (l[now]) return 0;
	int ans = 1e18;
	for (int i : a[now])
		if (i != fa) ans = min(ans, dfs2(i, now) + 1);
	return ans;
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) a[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		int Min = 2e18;
		for (int i = 0; i < (1 << n); i++)
		{
			memset(l, 0, sizeof(l));
			memset(vis, 0, sizeof(vis));
			int sum = 0, cnt = 0;
			for (int j = 1; j <= n; j++)
				if (i & (1 << (j - 1))) l[j] = 1, cnt++;
			for (int j = 1; j <= n; j++)
				if (!vis[j] && l[j]) dfs(j), sum++;
			if (cnt != k || sum != 2) continue;
			int Max = 0;
			for (int j = 1; j <= n; j++)
				Max = max(Max, dfs2(j, -1));
			Min = min(Min, Max);
		}
		cout << Min << '\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}