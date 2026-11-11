#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int u,w;
	bool operator < (const node x) const
	{
		return w>x.w;
	}
};
int c,n,m,d,q;
vector <node> g[500005];
int vis[500005],dis[500005];
int k[2005];
int dij(int s,int t)
{
	for(int i=1;i<=2*m+n;i++) dis[i] = 0x3f3f3f3f3f3f3f3f,vis[i] = 0;
	priority_queue<node> q;
	dis[s] = 0;
	q.push({s,dis[s]});
	while(!q.empty())
	{
		node p = q.top();
		q.pop();
		if(vis[p.u]) continue;
		vis[p.u] = 1;
		for(auto x:g[p.u])
		{
			if(dis[x.u]>dis[p.u]+x.w)
			{
				dis[x.u] = dis[p.u]+x.w;
				q.push({x.u,dis[x.u]});
			}
		}
	}
	return dis[t];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		int w;
		scanf("%lld",&w);
		g[i].push_back({m+i,w});
		g[m+i].push_back({i,w});
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			int uu,ww;
			scanf("%lld%lld",&uu,&ww);
			g[2*m+i].push_back({m+uu,ww});
			g[m+uu].push_back({2*m+i,ww});
		}
	}
	while(q--)
	{
		int u,v;
		scanf("%lld%lld",&u,&v);
		printf("%lld\n",dij(u,v));
		//for(int i=1;i<=2*m+n;i++) printf("%d\n",dis[i]);
	}
}//44(108min)