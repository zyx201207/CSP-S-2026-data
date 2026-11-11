#include<bits/stdc++.h>
using namespace std;
int weight[500005],len[500005];
long long dist[505][505];
int to[500005][22][2];
void floyd(int n)
{
	int i,j,k;
	for(i=1;i<=n;++i)
		for(j=i+1;j<=n;++j)
			for(k=1;k<=n;++k)
			{
				if(i==k||j==k)
					continue;
				dist[i][j]=dist[j][i]=min(dist[i][j],dist[i][k]+dist[j][k]);
			}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int C,n,m,D,Q,u,v,i,j,k;
	long long ans;
	scanf("%d %d %d %d %d",&C,&n,&m,&D,&Q);
	for(i=1;i<=m;++i)
		scanf("%d",&weight[i]);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&k);
		for(j=1;j<=k;++j)
		{
			scanf("%d %d",&u,&v);
			to[u][++len[u]][0]=i;
			to[u][len[u]][1]=v;
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(i=1;i<=m;++i)
	{
		for(j=1;j<=len[i];++j)
		{
			for(k=1;k<=len[i];++k)
			{
				if(j==k)
					continue;
				dist[to[i][j][0]][to[i][k][0]]=dist[to[i][k][0]][to[i][j][0]]=min(dist[to[i][j][0]][to[i][k][0]],(long long)to[i][j][1]+to[i][k][1]);
			}
		}
	}
	for(i=1;i<=n;++i)
		dist[i][i]=0;
	floyd(n);
	while(Q--)
	{
		scanf("%d %d",&u,&v);
		ans=LONG_LONG_MAX;
		for(i=1;i<=len[u];++i)
			for(j=1;j<=len[v];++j)
				ans=min(ans,weight[u]+weight[v]+dist[to[u][i][0]][to[v][j][0]]+to[u][i][1]+to[v][j][1]);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}
