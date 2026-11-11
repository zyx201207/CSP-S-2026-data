#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,t;
int a[505];
struct node
{
	int x,y;
}e[20005];
int g[5005][5005],dis[5005][5005];
int vis[20005],flag[20005];
priority_queue<pair<int,int> > q;
void dfs(int s)
{
	for(int i=1;i<=m;i++) vis[i]=0,dis[s][i]=0x3f3f3f3f;
	q.push({0,s});
	dis[s][s]=0;
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=1;i<=m;i++)
		{
			if(!g[x][i]) continue;
			if(dis[s][x]+g[x][i]<dis[s][i])
			{
				dis[s][i]=dis[s][x]+g[x][i];
				q.push({-dis[s][i],i});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	memset(g,0,sizeof(g));
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>e[j].x>>e[j].y;
		}
		for(int j=1;j<=k;j++)
		{
			for(int s=j+1;s<=k;s++)
			{
				if(g[e[j].x][e[s].x])g[e[j].x][e[s].x]=g[e[s].x][e[j].x]=min(g[e[j].x][e[s].x],e[j].y+e[s].y);
				else g[e[j].x][e[s].x]=g[e[s].x][e[j].x]=e[j].y+e[s].y;
			}
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		dfs(i);
	}
	for(int i=1;i<=t;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<a[x]+dis[x][y]+a[y]<<'\n';
	}
	return 0;
}
