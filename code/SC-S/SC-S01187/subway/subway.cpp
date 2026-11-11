#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>p;
vector<p>g[500005];
int c,n,m,d,q,w[500005],a[505][500005],t[505][500005],k[505],dis[500005],vis[500005];
void dij(int s)
{
	memset(dis,0x3f3f3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<p,vector<p>,greater<p> >q;
	dis[s]=0;
	vis[s]=1;
	while(q.size()!=0)
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto i:g[u])
		{
			int w=i.first,v=i.second;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({dis[v],v});
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++)
		{
			for(int k1=j+1;k1<=k[i];k1++)
			{
				g[a[i][j]].push_back({t[i][j]+t[i][k1],a[i][k1]});
				g[a[i][k1]].push_back({t[i][j]+t[i][k1],a[i][j]});
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int start,end,ans=0;
		cin>>start>>end;
		ans=ans+w[start]+w[end];
		dij(start);
		ans+=dis[end];
		cout<<ans<<"\n";
	}
} 