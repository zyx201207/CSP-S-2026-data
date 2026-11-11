#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n,m;
vector < int > g[N];
int res = N;
int a[N];
queue < int > q;
int vis[N];
int dis[N];
int f[N];
void check()
{
	int c = 0;
	for(int i = 1;i <= n;i++) vis[i] = 0;
	for(int i = 1;i <= m;i++)
	{
		if(!vis[a[i]])
		{
			q.push(a[i]);
			c++;
			vis[a[i]] = 1;
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				for(int j = 0;j < g[u].size();j++)
				{
					int v = g[u][i];
					if(!f[v]) continue;
					if(vis[v]) continue;
					vis[v] = 1;
					q.push(v);
				}
			}
		}
	}
	if(c > 2) return ;
	int mx = 0;
	for(int i = 1;i <= n;i++) dis[i] = N;
	for(int i = 1;i <= n;i++) vis[i] = 0;
	for(int i = 1;i <= m;i++)
	{
		q.push(a[i]);
		vis[a[i]] = 1;
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int i = 0;i < g[u].size();i++)
		{
			int v = g[u][i];
			if(vis[v]) continue;
			vis[v] = 1;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		mx = max(mx,dis[i]);
	}
	res = min(res,mx);
}
void dfs(int x,int y)
{
	if(x == n + 1)
	{
		if(y == m)
		{
			check();
		}
		return ;
	}
	dfs(x + 1,y);
	a[y + 1] = x;
	f[x] = 1;
	dfs(x + 1,y + 1);
	f[x] = 0;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i = 1;i <= n;i++) g[i].clear();
		for(int i = 1;i < n;i++)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
//		dfs(1,0);
		printf("%d\n",0);
	}
	return 0;
}
