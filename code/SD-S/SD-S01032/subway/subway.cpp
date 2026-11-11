#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int c,n,m,d,q;
int k[501],w[250000001],t[501][250000001],ai[501][250000001],qs[100001],qe[100001];
int a[250000001][250000001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++)
	  scanf("%d",&w[i]);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		int g,h;
		for (int j=1;j<=k[i];j++)
		{
		  scanf("%d%d",&g,&h);
		  ai[i][g]=1;
		  t[i][g]=h;
		}
	}
	for (int i=1;i<=m;i++)
	  for (int j=1;j<=m;j++)
	  {
	  	if (i==j) a[i][j]=a[j][i]=0;
	    else a[i][j]=a[j][i]=1e9;	  	
	  }
	for (int i=1;i<=q;i++)
	  scanf("%d%d",&qs[i],&qe[i]);
	for (int l=1;l<=n;l++)
		for (int i=1;i<=m;i++)
			for (int j=1;j<=m;j++)
				if (ai[l][i]==1&&ai[l][j]==1)   a[i][j]=a[j][i]=min(a[i][j],min(a[j][i],t[l][i]+t[l][j]));
	for (int o=1;o<=m;o++)
	  for (int i=1;i<=m;i++)
	    for (int j=1;j<=m;j++)
	      a[i][j]=a[j][i]=min(a[i][j],a[i][o]+a[o][j]);
	for (int i=1;i<=q;i++)
		printf("%d\n",a[qs[i]][qe[i]]+w[qs[i]]+w[qe[i]]);
	return 0;
}
