#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,w[N];
vector<int> ve[N],vl[N];
ll f[505][505];
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
		for(int j=1;j<=n;j++) f[i][j]=1e18;
		f[i][i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int k,x,t;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&x,&t);
			for(int l=0;l<ve[x].size();l++)
			{
				int y=ve[x][l],v=vl[x][l];
				f[i][y]=min(f[i][y],1ll*v+t);
				f[y][i]=min(f[y][i],1ll*v+t);
			}
			ve[x].push_back(i),vl[x].push_back(t);
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++) printf("%lld ",f[i][j]);
//		printf("\n");
//	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ll ans=1e18;
		for(int i=0;i<ve[x].size();i++)
		{
			for(int j=0;j<ve[y].size();j++)
			{
				int u=ve[x][i],v=ve[y][j];
				ans=min(ans,f[u][v]+vl[x][i]+vl[y][j]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
