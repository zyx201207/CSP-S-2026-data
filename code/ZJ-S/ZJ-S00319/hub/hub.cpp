#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, ans, a[15], dis[15];
bool vis[15], vis2[15];
vector<int> e[1000005];
void dfs(int d, int x)
{
	if(++d > k)
	{
		memset(vis2, 0, sizeof vis2);
		int cnt = 0;
		for(int i = 1; i <= k; i++)
			if(!vis2[a[i]])
			{
				queue<int> q;
				cnt++, vis2[a[i]] = 1, q.push(a[i]);
				while(!q.empty())
				{
					int u = q.front();
					q.pop();
					for(int v : e[u])
						if(vis[v] && !vis2[v])
							vis2[v] = 1, q.push(v);
				}
			}
		if(cnt > 2) return;
		memset(dis, 63, sizeof dis);
		int mx = 0;
		queue<int> q;
		for(int i = 1; i <= k; i++)
			dis[a[i]] = 0, q.push(a[i]);
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			for(int v : e[u])
				if(dis[v] > dis[u] + 1)
					dis[v] = dis[u] + 1, mx = max(mx, dis[v]), q.push(v);
		}
		ans = min(ans, mx);
		return;
	}
	for(int i = x + 1; i <= n; i++)
		a[d] = i, vis[i] = 1, dfs(d, i), vis[i] = 0;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> k, ans = 1e9;
		for(int i = 1; i <= n; i++)
			e[i].clear();
		for(int i = 1, u, v; i < n; i++)
			scanf("%d%d", &u, &v), e[u].push_back(v), e[v].push_back(u);
		if(c <= 3) dfs(0, 0);
		else if(k == 2)
		{
			
		}
		cout << ans << '\n';
	}
	return 0;
}