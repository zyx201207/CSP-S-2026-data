#include<stdio.h>
#define MAXM 200005
using namespace std;
int c,n,m,d,q;
int t[505][MAXM],w[MAXM];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int a,k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
			scanf("%d%d",&a,&t[i][j]);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		long long ans=w[x]+w[y];
		printf("%lld\n",ans+t[x][x]+t[x][y]);
	}
	return 0;
}
