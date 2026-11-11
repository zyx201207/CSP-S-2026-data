#include <bits/stdc++.h>
using namespace std;
int vis[11],a[11],cnt[11],pa[11];
int dis[11],viss[11];
int sumans;
struct node
{
	int u,w;
	bool operator < (const node x) const
	{
		return w>x.w;
	}
};
vector <int> g[200005];
int n,k;
void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(viss,0,sizeof(viss));
	priority_queue<node> q;
	dis[s] = 0;
	q.push({s,dis[s]});
	while(!q.empty())
	{
		node p = q.top();
		q.pop();
		if(viss[p.u]) continue;
		viss[p.u] = 1;
		for(auto x:g[p.u])
		{
			if(dis[x]>dis[p.u]+1)
			{
				dis[x] = dis[p.u]+1;
				q.push({x,dis[x]});
			}
		}
	}
}
int getfa(int x)
{
	return pa[x]==x?x:pa[x] = getfa(pa[x]);
}
void dfs(int dep)
{
	if(dep==k+1)
	{
		for(int i=1;i<=k;i++) pa[a[i]] = a[i];
		for(int i=1;i<=k;i++)
		{
			int p = a[i];
			for(auto x:g[p])
			{
				bool flag = 0;
				for(int j=1;j<=k&&j!=i;j++)
					if(x==a[j]) flag = 1;
				if(flag)
				{
					int uu = getfa(p),vv = getfa(x);
					if(uu!=vv) pa[uu] = vv;
				}
			}
		}
		for(int i=1;i<=k;i++) cnt[pa[a[i]]]++;
		int qwq = 0;
		for(int i=1;i<=10;i++)
			if(cnt[i]!=0) qwq++;
		memset(cnt,0,sizeof(cnt));
		if(qwq>2) return;
		int ans = 0;
		for(int i=1;i<=k;i++)
		{
			dij(a[i]);
			for(int j=1;j<=n;j++) ans = max(ans,dis[j]);
		}
		sumans = min(sumans,ans);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			a[dep] = i;
			vis[i] = 1;
			dfs(dep+1);
			vis[i] = 0;
		}
	
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		sumans = 1e9;
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		printf("%d\n",sumans);
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
	}
}//0(235min)