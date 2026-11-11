#include <bits/stdc++.h>
using namespace std;
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
vector <int> g[15];
int vis[15];
void dfs(int u)
{
	for (int v:g[u])
	{
		if(vis[v])
			continue;
		vis[v] = 1;
		dfs(v);
	}
}
int sp(int now,int end,int dis)
{
	if (now == end)
		return dis;
	int minn = 1e9;
	for (int v:g[now])
	{
		if (!vis[v])
		{
			vis[v] = 1;
			minn = min(minn,sp(v,end,dis+1));
			vis[v] = 0;
		}
	}
	return minn;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while (t--)
	{
		int n,k;
		cin >> n >> k;
		for (int i = 1;i <= n;i++)
			g[i].clear();
		for (int i = 1;i < n;i++)
		{
			int u,v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			vis[i] = 0;
		}
		int ans = 1e9;
		for (int j = 0;j < (1 << n);j++)
		{
			vector<int> ps;
			for (int i = 0;i < n;i++)
			{
				if ((j >> i)&1) 
					ps.push_back(1+i);				
			}
			int cnt = 0;
//			cout << ps.size() << endl;
			if (ps.size() != k)
				continue;
			for (int p : ps)
			{
				if (vis[p] == 0)
				{
					cnt++;
					vis[p] = 1;
					dfs(p);
				}
			}
			if (cnt > 2)
				continue;
			fill(vis+1,vis+n+1,0);
			int maxn = 0;
			for (int i = 1;i <= n;i++)
			{
				int minn = 1e9;
				for (int j : ps)
				{
					minn = min(minn,sp(i,j,0));
				}
				
				maxn = max(maxn,minn);
			}
			cout << maxn << ' ';
			for (int p : ps)
				cout << p <<' ';
			cout << endl;
			ans = min(maxn,ans);
		}
		cout << ans << '\n';
	}
}
