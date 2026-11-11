#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
const int N=1e3+5;
int c,n,m,d,q;
int w[M];
int k[505];
int a[M],t[M];
int G[N][N];
vector<pair<int,int> > H[N];
ll dis[M];
bool vis[M];
priority_queue<pair<ll,int> > Q;
void dij(int s,int e)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++) dis[i]=1e18;
	dis[s]=0;
	Q.push({0,s});
	while(!Q.empty())
	{
		int u=Q.top().second;
		Q.pop();
		if(vis[u]) continue;
		for(int i=0;i<H[u].size();i++)
		{
			int v=H[u][i].first;
			if(vis[v]) continue;
			ll w=H[u][i].second;
			//cout<<w<<" ";
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				Q.push({-dis[v],v});
			}
		}
		vis[u]=true;
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			G[i][j]=2e9+5;
		}
	}
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[j]>>t[j];
		}
		for(int u=1;u<=k[i];u++)
		{
			for(int v=u+1;v<=k[i];v++)
			{
				G[a[u]][a[v]]=min(G[a[u]][a[v]],t[u]+t[v]);
				G[a[v]][a[u]]=min(G[a[v]][a[u]],t[u]+t[v]);
			}
		}
	}
	for(int u=1;u<=m;u++)
	{
		for(int v=u+1;v<=m;v++)
		{
			//cout<<u<<' '<<v<<' '<<G[a[u]][a[v]]<<endl;
			if(G[u][v]<2e9+5&&G[u][v]>0)
			{
				H[u].push_back({v,G[u][v]});
				H[v].push_back({u,G[u][v]});
			}
		}
	}
	/*for(int i=1;i<=m;i++)
	{
		for(auto j:H[i])
		{
			cout<<i<<" "<<j.first<<" "<<j.second<<endl;
		}
	}*/
	while(q--)
	{
		int xr,yr;
		cin>>xr>>yr;
		dij(xr,yr);
		//for(int i=1;i<=m;i++) cout<<dis[i]<<" ";
		cout<<dis[yr]+w[xr]+w[yr]<<endl;
	}
	return 0;
}

