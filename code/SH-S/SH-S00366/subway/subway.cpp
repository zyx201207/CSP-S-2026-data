#include<bits/stdc++.h>
using namespace std;
struct node{long long x,y;
};
vector<node> a1[500001];
long long a[501][501],w[500001];
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int ki;
		scanf("%d",&ki);
		for(int j=1;j<=ki;j++)
		{
			long long x,y;
			scanf("%lld%lld",&x,&y);
			a1[x].push_back({i,y});
		}
	}
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++) a[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<a1[i].size();j++)
		{
			for(int l=0;l<a1[i].size();l++)
			{
				node x=a1[i][j],y=a1[i][l];
				a[x.x][y.x]=min(a[x.x][y.x],x.y+y.y);
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		long long ans=100000000000000000;
		scanf("%d%d",&x,&y);
		for(int j=0;j<a1[x].size();j++)
		{
			for(int l=0;l<a1[y].size();l++)
			{
				ans=min(ans,a[a1[x][j].x][a1[y][l].x]+a1[x][j].y+a1[y][l].y);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0; 
}
