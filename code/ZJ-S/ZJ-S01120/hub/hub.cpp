#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
vector<int> g[N];
int col[N], vis[N], vis2[N];
void dfs(int x)
{
	vis[x] = 1;
	for (int i : g[x])
	{
		if (vis[i] || !col[i])
			continue;
		dfs(i);
	}
}
int bfs(int st)
{
	queue<pair<int, int>> q;
	q.push({st, 0});
	while (!q.empty())
	{
		int x = q.front().first, cnt = q.front().second;
		q.pop();
		vis2[x] = 1;
		if (col[x])
			return cnt;
		for (int i : g[x])
		{
			if (vis2[i])
				continue;
			q.push({i, cnt + 1});
		}
	}
	return -1;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n, k, ans = 0x3f3f3f3f;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			g[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int s = 0; s < (1 << n); s++)
		{
			for (int i = 1; i <= n; i++)
				col[i] = vis[i] = 0;
			int cnt = 0, num = 0, tmp = s;
			while (tmp)
			{
				cnt += (tmp & 1);
				col[++num] = (tmp & 1);
				tmp >>= 1;
			}
			if (cnt != k)
				continue;
			num = 0;
			for (int i = 1; i <= n; i++)
			{
				if (col[i] && !vis[i])
				{
					num++;
					if (num >= 3)
						break;
					dfs(i);
				}
			}
			if (num >= 3)
				continue;
			int res = 0;
			for (int i = 1; i <= n; i++)
			{
				if (col[i])
					continue;
				res = max(res, bfs(i));
				for (int j = 1; j <= n; j++)
					vis2[j] = 0;
			}
			ans = min(ans, res);
		}
		cout << ans << "\n";
	}
	return 0;
}
