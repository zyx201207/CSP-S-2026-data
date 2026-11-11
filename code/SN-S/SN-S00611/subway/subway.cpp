//SN-S00611
//¶­¹ú¶°
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long zhan[500005];
vector<pair<int,int>>a[501005];
long long dis[2005][2005];
void dj(int x)
{
	memset(dis[x],0x3f,sizeof dis[x]);
	dis[x][x]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,x});
	bool vis[2005]={0};
	while(q.size())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto p:a[u])
		{
			int v=p.first,w=p.second;
			if(vis[v])continue;
			if(dis[x][v]>dis[x][u]+w)
				dis[x][v]=dis[x][u]+w,q.push({dis[x][v],v});
		}
	}
}
long long bfs(int x,int y)
{
	queue<pair<long long,int>>q;
	q.push({0,x});
	bool vis[501005]={0};
	while(q.size())
	{
		long long u=q.front().second,now=q.front().first;
		q.pop();
		if(u==y)
			return now;
		if(vis[u])continue;
		vis[u]=1;
		for(auto p:a[u])
		{
			int v=p.first,w=p.second;
			if(vis[v])continue;
			q.push({now+w,v});
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>zhan[i];
	for(int i=m+1;i<=m+n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int t,u;
			cin>>u>>t;//undertale?
			a[i].push_back({u,t});
			a[u].push_back({i,t});
		}
	}
	if(c<=11)
	{
		for(int i=1;i<=m;i++)
			dj(i);
		for(int i=1;i<=q;i++)
		{
			int u,v;
			cin>>u>>v;
			cout<<dis[u][v]+zhan[u]+zhan[v]<<'\n';
		}
	}
	if(c>11&&c<=19)
	{
		for(int i=1;i<=q;i++)
		{
			int x,y;
			cin>>x>>y;
			cout<<bfs(x,y)+zhan[x]+zhan[y]<<'\n';
		}
	}
	return 0;
}
