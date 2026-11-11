#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qu,w[20010],a;
long long b,dist[510][510],g[20010][510];
bool vis[510][510];
pair<int,long long> p;
vector< pair<int,long long> > f[510];
vector< pair<int,long long> > e[20010];
priority_queue< pair<long long,int>,vector< pair<long long,int> > > q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qu);
	for(int i=1;i<=m;++i)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&c);
		for(int j=1;j<=c;++j)
		{
			scanf("%d%lld",&a,&b);
			p.second=b;p.first=i;
			e[a].push_back(p);
		}
		for(int j=1;j<=n;++j)
			if(i!=j)
				dist[i][j]=LONG_LONG_MAX;
	}
	for(int i=1;i<=m;++i)
	{
		if(e[i].size()>1)
		{
			for(int j=1;j<e[i].size();++j)
				for(int k=0;k<j;++k)
				{
					p.first=e[i][j].first;p.second=e[i][j].second+e[i][k].second;
					f[e[i][k].first].push_back(p);
					p.first=e[i][k].first;
					f[e[i][j].first].push_back(p);
					//cout<<e[i][j].first<<' '<<e[i][k].first<<' '<<p.second<<'\n';
				}
		}
	}
	for(int i=1;i<=n;++i)
	{
		p.first=0;p.second=i;
		q.push(p);
		for(int j=1;j<=n;++j)
			vis[i][j]=false;
		while(!q.empty())
		{
			int now=q.top().second;
			q.pop();
			if(vis[i][now]) continue;
			vis[i][now]=true;
			for(int j=0;j<f[now].size();++j)
			{
				int v=f[now][j].first;
				if(!vis[i][v]&&f[now][j].second+dist[i][now]<dist[i][v])
				{
					dist[i][v]=f[now][j].second+dist[i][now];
					p.first=dist[i][v];p.second=v;
					q.push(p);
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			g[i][j]=LONG_LONG_MAX;
			for(int k=0;k<e[j].size();++k)
				g[i][j]=min(g[i][j],dist[i][e[j][k].first]+e[j][k].second);
		}
	}
	for(int i=1;i<=qu;++i)
	{
		long long ans=LONG_LONG_MAX;
		scanf("%d%d",&c,&d);
		for(int j=1;j<=n;++j)
			ans=min(ans,g[j][c]+g[j][d]);
		printf("%lld\n",ans+w[c]+w[d]);
	}
	return 0;
}
