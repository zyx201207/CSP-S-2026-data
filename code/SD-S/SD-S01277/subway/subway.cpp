#include<bits/stdc++.h>
using namespace std;
long long ccc,n,m,ddd,q,w[1000010],k[1010],a[510][500010],t[510][500010],vis[1000010],dis[1000010],ans=0;
struct node
{
	long long id,t;
};
struct node2
{
	long long p,step;
};
vector<node> v[500010];
long long bfs(long long x,long long y)
{
	for(long long i=1;i<=m;i++)
	{
		vis[i]=0,dis[i]=1e18;
	}
	queue<node2>q;
	node2 h;h.p=x,h.step=0;
	q.push(h);
	while(!q.empty())
	{
		node2 h=q.front();q.pop();
		long long p=h.p,step=h.step;
		if(dis[p]<step)
		{
			continue;
		}
		else 
		{
			dis[p]=h.step;
		}
		node2 g;
		for(auto u:v[p])
		{
			for(long long i=1;i<=k[u.id];i++)
			{
				if(a[u.id][i]==p)
				{
					continue;
				}
				g.p=a[u.id][i];
				g.step=step+u.t+t[u.id][i];
				if(g.step>dis[g.p])
				{
					continue;
				}
				q.push(g);
			}
		}
	}
	return dis[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&ccc,&n,&m,&ddd,&q);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(long long j=1;j<=k[i];j++)
		{
			scanf("%lld%lld",&a[i][j],&t[i][j]);
			node h;
			h.id=i,h.t=t[i][j];
			v[a[i][j]].push_back(h);
		}
	}
	
	for(long long i=1;i<=q;i++)
	{
		long long x,y;
		scanf("%lld%lld",&x,&y);
		ans=bfs(x,y)+w[x]+w[y];
		printf("%lld\n",ans);
	}
	return 0;
}
