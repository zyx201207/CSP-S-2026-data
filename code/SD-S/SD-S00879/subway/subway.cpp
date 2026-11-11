#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int INF=1e9;
int dist[N][N];
int w[N];
int a[N][N],t[N][N];
int same[N][N];
int c,n,m,d,q;
void floyd()
{
	for (int k=1;k<=m;k++)
	{
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=m;j++)
			{
				if ((!same[i][k] || !same[k][j])) continue;
				if (same[i][j])
				{
					dist[i][j]=min(dist[i][j],t[i][same[i][j]]+t[j][same[i][j]]);
				}
				int ii=t[i][same[i][k]];
				int kk=t[k][same[i][k]]+t[k][same[k][j]];
				int jj=t[j][same[k][j]];
				dist[i][j]=min(dist[i][j],ii+kk+jj);
			}
		}
	}
	for (int k=1;k<=m;k++)
	{
		for (int i=1;i<=m;i++)
		{
			for (int j=1;j<=m;j++)
			{
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) scanf("%d",&w[i]);
	memset(same,0,sizeof(same));
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=m;j++) dist[i][j]=INF;
		dist[i][i]=0;
	}
	for (int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j++)
		{
			scanf("%d",&a[i][j]);
			int tt;
			scanf("%d",&tt);
			t[a[i][j]][i]=tt;
		}
		for (int j=1;j<=k;j++)
		{
			for (int p=1;p<=k;p++)
			{
				same[a[i][j]][a[i][p]]=i;
			}
		}
	}
	floyd();
	for (int i=1;i<=q;i++)
	{
		int st,ed;
		scanf("%d%d",&st,&ed);
		printf("%d\n",w[st]+w[ed]+dist[st][ed]);
	}
	return 0;
}
