#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q;
int tot=0;
const int N=1e3+10,N2=5e2+10;
int a[N2],k,u[N];
int dist[N][N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			dist[i][j]=1e9+7;
		}
	}
	for(int i=1;i<=N;i++)
	{
		dist[i][i]=0;
	}
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dist[i][n+i]=a[i];
		dist[n+i][i]=a[i];
	}
	tot=2*n;
	for(int i=1;i<=m;i++)
	{
		cin>>k;
		int v;
		for(int j=1;j<=k;j++)
		{
			cin>>u[j]>>v;
			dist[i+n][++tot]=v;
			dist[tot][i+n]=v;
			if(j!=1)
			{
				dist[tot][tot-1]=0;
				dist[tot-1][tot]=0;
			}
		}
	}
	for(int k=1;k<=tot;k++){
		for(int i=1;i<=tot;i++)
		{
			for(int j=1;j<=tot;j++)
			{
				dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
			}
		}
	}
	
	int s,t;
	for(int i=1;i<=q;i++)
	{
		cin>>s>>t;
		cout<<dist[s][t]<<'\n';
	}
}
