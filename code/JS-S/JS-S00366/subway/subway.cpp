#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,qe,w[500005];
long long mp[505][505],dist[505][505];
vector<pair<int,long long>> e[500005],a[505];
priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
inline int read()
{
    char c='X';
    int x=0;
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9')
    {
        x=10*x+c-'0';
        c=getchar();
    }
    return x;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),qe=read();
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) mp[i][j]=-1;
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++)
    {
		int k=read();
		while(k--)
		{
			int u=read(),x=read();
			e[u].push_back({i,x});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<e[i].size();j++)
		{
			for(int k=0;k<e[i].size();k++) if(j!=k)
			{
				int u=e[i][j].first,v=e[i][k].first;
				long long w=e[i][j].second+e[i][k].second;
				if(mp[u][v]==-1) mp[u][v]=w;
				else mp[u][v]=min(mp[u][v],w);
			}
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(mp[i][j]!=-1&&i!=j) a[i].push_back({j,mp[i][j]});
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dist[i][j]=3e18;
		dist[i][i]=0;
		while(!q.empty()) q.pop();
		q.push({0,i});
		while(!q.empty())
		{
			int u=q.top().second;
			long long s=q.top().first;
			q.pop();
			if(dist[i][u]!=s) continue;
			for(auto x:a[u])
			{
				long long w=x.second+s,v=x.first;
				if(dist[i][v]>w)
				{
					dist[i][v]=w;
					q.push({w,v});
				}
			}
		}
	}
    while(qe--)
    {
		int u,v;
		long long ans=3e18;
		u=read(),v=read();
		for(auto i:e[u]) for(auto j:e[v]) ans=min(ans,i.second+j.second+dist[i.first][j.first]);
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
