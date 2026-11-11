#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

const int MAXN = 2000;
int c,n,m,d,q;
int g[8005][8005];
int a[35],t[25];
bool vis[8005];
int dis[8005];

int dij(int s,int e)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	dis[s] = 0;
	pq.push({0,s});
	while(!pq.empty())
	{
		int u=pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int v=1;v<=8000;v++)
		{
			if(g[u][v]<0) continue;
			if(dis[v]>dis[u]+g[u][v])
			{
				dis[v]=dis[u]+g[u][v];
				pq.push({dis[v],v});
			}
		}
	}
	return dis[e];
} 

int main()
{
	cin.tie(0);
	cout.tie(0);  
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=8000;i++)
	{
		for(int j=1;j<=8000;j++)
		{
			g[i][j] = -1;
		}
	}
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)
	{
		int w;
		cin >> w;
		g[i][MAXN+i]=w;
		g[MAXN+i][i]=w;
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			cin >> a[j] >> t[j];
		}
		for(int j=1;j<=k;j++)
		{
			if(j>1)
			{
				g[2*MAXN+i*100+a[j]][2*MAXN+i*100+a[j-1]]=0;
				g[2*MAXN+i*100+a[j-1]][2*MAXN+i*100+a[j]]=0;
			}
			g[2*MAXN+i*100+a[j]][MAXN+a[j]]=t[j];
			g[MAXN+a[j]][2*MAXN+i*100+a[j]]=t[j];
		}
	}
	while(q--)
	{
		int x,y;
		cin >> x >> y;
		cout << dij(x,y) << endl;
	}
	return 0;
 } 
