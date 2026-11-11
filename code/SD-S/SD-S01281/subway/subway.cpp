#include<bits/stdc++.h>
using namespace std;
const int N=510,M=6e5;
int dist[N],g[N][N],n,m;
bool st[N];
int c,d,q,w[M],k[N];
int t[N][N],a[N][N];
int di(int x,int y)
{
	memset(dist,0x3f,sizeof dist);
	dist[x]=0;
	for (int i=1;i<=m;i++)
	{
		int t=-1;
		for (int j=1;j<=m;j++)
		{
			if (!st[j] && (t==-1 || dist[t]>dist[j])) t=j;
		}
		for (int j=1;j<=m;j++)
		{
			dist[j]=min(dist[j],dist[t]+g[t][j]);
		}
		st[t]=1;
	}
	if (dist[y]==0x3f3f3f3f) return -1;
	return dist[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(g,0x3f,sizeof g);
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++) cin>>w[i];
	for (int i=1;i<=n;i++)
	{
		cin>>k[i];
		for (int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		 } 
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=k[i];j++)
		{
			for (int tt=1;tt<=k[i];tt++)
			{
				g[a[i][j]][a[i][tt]]=min(g[a[i][j]][a[i][tt]],t[i][j]+t[i][tt]);
			}
		} 
	}
	for (int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		if (g[x][y]!=0x3f3f3f3f) cout<<g[x][y]+w[x]+w[y]<<"\n";
		else cout<<di(x,y)+w[x]+w[y]<<"\n";
	}
	return 0; 
}
