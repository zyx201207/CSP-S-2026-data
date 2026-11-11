#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int Read(){int x;cin>>x;return x;}
const int kN=5e5+10,kM=500+10,kMod=1e9+7,kInf=1e15;

void Work();

vector<pair<int,int>>edge[kN];
int w[kN],dis[kM][kM];

signed main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;while(T--)Work();
}

void Work()
{
	int c=Read(),n=Read(),m=Read(),d=Read(),q=Read();
	for(int i=1;i<=m;i++)w[i]=Read();
	for(int i=1;i<=n;i++)
	{
		int k=Read();
		for(int j=1;j<=k;j++)
		{
			int v=Read(),t=Read();
			edge[v].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=kInf;
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)
		for(int j=0;j<edge[i].size();j++)
			for(int k=0;k<edge[i].size();k++)
			{
				int u=edge[i][j].first,v=edge[i][k].first;
				dis[u][v]=dis[v][u]=
				min(dis[u][v],edge[i][j].second+edge[i][k].second);
			}
	for(int i=1;i<=m;i++)
		for(int j=0;j<edge[i].size();j++)
			for(int k=j+1;k<edge[i].size();k++)
				for(int v=1;v<=n;v++)
				{
					int u=edge[i][j].first,w=edge[i][k].first;
					if(dis[u][v]>dis[w][v]+dis[u][w])
						dis[u][v]=dis[v][u]=dis[w][v]+dis[u][w];
					if(dis[w][v]>dis[u][v]+dis[u][w])
						dis[w][v]=dis[v][w]=dis[u][v]+dis[u][w];
				}
	for(int i=1;i<=q;i++)
	{
		int u=Read(),v=Read(),res=kInf;
		for(int j=0;j<edge[u].size();j++)
			for(int k=0;k<edge[v].size();k++)
			{
				int x=edge[u][j].first,y=edge[v][k].first;
				res=min(res,dis[x][y]+edge[u][j].second+edge[v][k].second);
			}
		printf("%lld\n",w[u]+w[v]+res);
	}
}