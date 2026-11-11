#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010],dis[1510][1510],t;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout); 
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int v,w;t++;
			scanf("%d%d",&v,&w);
			dis[t+m][v]=min(w,dis[t+m][v]);
			dis[v][t+m]=min(w,dis[v][t+m]);
		}
	}
	int s=m+t;
	for(int i=1;i<=s;i++) dis[i][i]=0;
	for(int k=1;k<=s;k++)
		for(int i=1;i<=s;i++)
			for(int j=1;j<=s;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dis[x][y]+w[x]+w[y]);
	}
	return 0;
}