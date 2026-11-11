#include <bits/stdc++.h>
#include <cstdio>
#include <stdio.h>
const long long N=500,M=5*(1e5)+5,S=1e5+5;
long long w[N],k[N],a[N][M],t[N][M],x[S],y[S],tot[S];
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&x[i],&y[i]);
	}
	for(int i=1;i<=q;i++)
	{
		printf("%d",tot[i]);
	}
	return 0;
}
