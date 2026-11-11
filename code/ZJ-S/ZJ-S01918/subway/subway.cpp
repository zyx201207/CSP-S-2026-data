#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,a,x,y;
struct S
{
	int a;
	long long t;
};
vector<S> b[500005];
long long w[500005],t,dis[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%lld",&a,&t);
			b[a].push_back((S){i,t});
		}
		dis[i][i]=0;
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<b[i].size()-1;j++)
			for(int k=j+1;k<b[i].size();k++)
			{
				dis[b[i][j].a][b[i][k].a]=min(dis[b[i][j].a][b[i][k].a],b[i][j].t+b[i][k].t);
				dis[b[i][k].a][b[i][j].a]=min(dis[b[i][k].a][b[i][j].a],b[i][j].t+b[i][k].t);
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		scanf("%d%d",&x,&y);
		long long ans=1e18;
		for(int i=0;i<b[x].size();i++)
			for(int j=0;j<b[y].size();j++)
				ans=min(ans,b[x][i].t+b[y][j].t+dis[b[x][i].a][b[y][j].a]);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}