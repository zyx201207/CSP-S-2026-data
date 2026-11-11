#include <bits/stdc++.h>

using namespace std;

int n,k;
bool st[1000010];
bool st1[1000010];
vector<int> g[1000010];

void dfs1(int now)
{
	st[now] = 0;
	st1[now] = 1;
	
	for (int i = 0; i < g[now].size(); i++)
		if (st[g[now][i]])
			dfs1(g[now][i]);
}

int dfs2(int now,int fa)
{
	if (st1[now] == 1)
		return 0;
		
	int mn = 0x3f3f3f3f;
	for (int i = 0; i < g[now].size(); i++)
	{
		if (g[now][i] == fa)
			continue;
		mn = min(mn,dfs2(g[now][i],now));
	}
	return mn + 1;
}
	
int dfs(int now)
{
	if (now > k)
	{
		int cnt = 0;
		int mn = 0x3f3f3f3f;
		for (int i = 1; i <= n; i++)
		{
			if (st[i])
			{
				cnt++;
				dfs1(i);
			}
		}
		
		if (cnt > 2)
			return 0x3f3f3f3f;
	
		for (int i = 1; i <= n; i++)
			if (!st1[i])
				mn = min(mn,dfs2(i,-1));
				
		return mn;
	}
	
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++)
	{
		if (st[i])
			continue;
		st[i] = 1;
		ans = min(ans,dfs(now + 1));
		st[i] = 0;
	}
	return ans;
}

void solve()
{
	cin >> n >> k;
	
	for (int i = 1; i <= n; i++)
		g[i].clear();
	
	for (int i = 1; i < n; i++)
	{
		int u,v;
		cin >> u >> v;
		
		g[u].push_back(v);
		g[v].push_back(u);
	}	
	
	cout << dfs(1) << "\n";
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0);
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	
	while (t--)
		solve();
		
	return 0;	
}
