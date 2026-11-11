#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,qq,cnt,tot,w[500005],g[1005][1005],INF;
vector<int>v1[500005];
struct node
{
	long long it,v;
};
vector<node>e[500005],t[500005];
long long dis[500005],vis[500005];
bool operator<(node a,node b)
{
	return a.v>b.v;
}
priority_queue<node>q;
long long dij()
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[0]=0;
	q.push({0,0});
	while(!q.empty())
	{
		long long minn=q.top().v,itt=q.top().it;
		q.pop();
		if(vis[itt]==1)
		continue;
		vis[itt]=1;
		for(int j=0;j<e[itt].size();j++)
		{
			int v=e[itt][j].it,len=e[itt][j].v;
			if(dis[v]>minn+len)
			{
				dis[v]=minn+len;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[n+1];
}
long long fun(int x,int y)
{
	int l=-1,r=t[x].size(),mid;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(t[x][mid].it>y)
		{
			r=mid;
		}
		else
		if(t[x][mid].it<y)
		{
			l=mid;
		}
		else
		{
			return t[x][mid].v;
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	memset(g,0x3f,sizeof(g));
	INF=g[0][0];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			t[x].push_back({i,y});
			v1[x].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v1[i].size();j++)
		for(int k=0;k<v1[i].size();k++)
		{
			int x=v1[i][j],y=v1[i][k];
			if(x==y)
			g[x][y]=0;
			else
			g[x][y]=min(g[x][y],fun(i,x)+fun(i,y));
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	if(g[i][j]<=1e12)
	{
		e[i].push_back({j,g[i][j]});
		e[j].push_back({i,g[i][j]});
	}
	while(qq--)
	{
		int x,y;
		cin>>x>>y;
		for(int k=0;k<t[x].size();k++)
		{
			e[0].push_back(t[x][k]);
		}	
		for(int k=0;k<t[y].size();k++)
		{
			e[t[y][k].it].push_back({n+1,t[y][k].v});
		}
		cout<<dij()+w[x]+w[y]<<"\n";
		for(int k=0;k<t[x].size();k++)
		{
			e[0].pop_back();
		}	
		for(int k=0;k<t[y].size();k++)
		{
			e[t[y][k].it].pop_back();
		}
	}
	return 0;
}
