#include<bits/stdc++.h>
#define M 500005
#define N 505
using namespace std;
int c,n,m,d,q,w[M];
struct MyPair
{
	int x,y;
};
vector<vector<MyPair> > a;
long long dis[N][N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)	scanf("%d",&w[i]);
//	cout<<"T\n";
	a.resize(m+5);
//	cout<<"F\n";
	for(int i=1,k,v,t;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&v,&t);
			a[v].push_back({i,t});
		}
	}
//	cout<<"A\n";
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++)	dis[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int len=a[i].size();
		for(int j=0;j<len;j++)
		{
			for(int k=0;k<len;k++)
			{
				if(j==k)	continue;
				dis[a[i][j].x][a[i][k].x]=min(dis[a[i][j].x][a[i][k].x],1LL*a[i][j].y+a[i][k].y);
			}
		}
	}
//	cout<<"B\n";
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)	continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	int u,v;
	while(q--)
	{
		scanf("%d%d",&u,&v);
		long long ans=dis[0][0];
		for(MyPair &i:a[u])
		{
			for(MyPair &j:a[v])
			{
				ans=min(ans,dis[i.x][j.x]+i.y+j.y);
			}
		}
		printf("%lld\n",ans+w[u]+w[v]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

