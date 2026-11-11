#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
const int N=500;
const int M=5e5;
const int D=20;
int C,n,m,d,q;
ll w[M+5];
int k[N+5];
int res[M+5][D+5];
ll rec[M+5][D+5];
ll dis[N+5][N+5];
void Floyd()
{
	for(register int t=1;t<=n;t++)
	{
		for(register int u=1;u<=n;u++)
		{
			for(register int v=1;v<=n;v++)
			{
				dis[u][v]=min(dis[u][v],dis[u][t]+dis[t][v]);
			}
		}
	}
}
int x,y;
ll ans=0;
void solve()
{
	cin>>x>>y;
	ans=inf;
	for(register int i=1;i<=res[x][0];i++)
	{
		for(register int j=1;j<=res[y][0];j++)
		{
			int u=res[x][i];
			int v=res[y][j];
			ans=min(ans,rec[x][i]+dis[u][v]+rec[y][j]);
		}
	}
	ans=ans+w[x]+w[y];
	cout<<ans<<"\n";
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>C>>n>>m>>d>>q;
	for(register int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(register int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(register int j=1;j<=k[i];j++)
		{
			int a,t;
			cin>>a>>t;
			res[a][0]++;
			res[a][res[a][0]]=i;
			rec[a][res[a][0]]=t;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			dis[i][j]=inf;
		}
		dis[i][i]=0;
	}
	for(register int i=1;i<=m;i++)
	{
		for(register int j=1;j<=res[i][0];j++)
		{
			for(register int l=j+1;l<=res[i][0];l++)
			{
				int u=res[i][j];
				int v=res[i][l];
				dis[u][v]=dis[v][u]=min(dis[u][v],rec[i][j]+rec[i][l]);
			}
		}
	}
	Floyd();
	while(q--)
	{
		solve();
	}
	return 0;
}
