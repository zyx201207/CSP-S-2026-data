#include<bits/stdc++.h>
using namespace std;
int C,n,m,D,Q;
int w[500005];
int to[500005][25],cnt[500005],val[500005][25];
long long dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&D,&Q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	int ki,aij,tij;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ki);
		for(int j=1;j<=ki;j++)
		{
			scanf("%d%d",&aij,&tij);
			++cnt[aij];
			to[aij][cnt[aij]]=i;
			val[aij][cnt[aij]]=tij;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int u=1;u<=cnt[i];u++)
		{
			for(int v=u+1;v<=cnt[i];v++)
			{
				int xi=to[i][u],yi=to[i][v];
				dis[xi][yi]=dis[yi][xi]=min(dis[xi][yi],(long long)val[i][u]+val[i][v]);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	int xj,yj;
	while(Q--)
	{
		scanf("%d%d",&xj,&yj);
		long long ans=1e18;
		for(int i=1;i<=cnt[xj];i++)
			for(int j=1;j<=cnt[yj];j++)
				ans=min(ans,dis[to[xj][i]][to[yj][j]]+val[xj][i]+val[yj][j]);
		printf("%lld\n",(ans+w[xj]+w[yj]));
	}
	return 0;
}
