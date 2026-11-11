//这个题没有满足24，25约束的大样例吗 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M],jg[M],id[M][25],t[M][25],dis[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int u,w;
			cin>>u>>w;
			jg[u]++,id[u][jg[u]]=i,t[u][jg[u]]=w;
		}
	} 
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=jg[i];j++)
		{
			for(int k=1;k<=jg[i];k++)
			{
				if(j==k) continue;
				int u=id[i][j],v=id[i][k];
				dis[u][v]=min(dis[u][v],t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=1;i<=jg[x];i++)
		{
			for(int j=1;j<=jg[y];j++)
			{
				int u=id[x][i],v=id[y][j];
				ans=min(ans,w[x]+w[y]+dis[u][v]+t[x][i]+t[y][j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}


