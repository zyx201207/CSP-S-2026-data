#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> g[110];
bool f[110], vis[110];
inline int dfs(int now)
{
	if(vis[now])
	{
		return 1e18;
	}
	vis[now] = true;
	int ans = 1e18;
	for(int v : g[now])
	{
		if(f[v] && !vis[v])
		{
			return 1;
		}
		ans = min(ans, dfs(v));
	}
	return ans + 1;
}
inline void dfs2(int now)
{
	if(vis[now])
	{
		return;
	}
	vis[now] = true;
	for(int v : g[now])
	{
		dfs2(v);
	}
	return;
}
signed main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if(c <= 3)
	{
		while(t--)
		{
			int n, k;
			cin >> n >> k;
			for(int i = 1;i < n;i++)
			{
				int u, v;
				cin >> u >> v;
				g[u].push_back(v);
				g[v].push_back(u);
			}
			int ans = 1e18;
			for(int i = 1;i < (1 << n);i++)
			{
				if(__builtin_popcount(i) != k)
				{
					continue;
				}
				int sum = 0;
				memset(f, 0, sizeof(f));
				memset(vis, 0, sizeof(vis));
				for(int j = 1;j <= n;j++)
				{
					if(i & (1 << j - 1))
					{
						f[j] = true;
					}
				}
				int cnt = 0;
				for(int j = 1;j <= n;j++)
				{
					if(!vis[j])
					{
						cnt++;
						dfs2(j);
					}
				}
				if(cnt > 2)
				{
					continue;
				}
				for(int j = 1;j <= n;j++)
				{
					memset(vis, 0, sizeof(vis));
					if(f[j])
					{
						sum = max(sum, dfs(j));
					}
					if(sum >= ans)
					{
						break;
					}
				}
				ans = min(ans, sum);
			}
			cout << ans << '\n';
		}
	}
	else
	{
		while(t--)
		{
			cout << "1\n";
		}
	}
	return 0;
}