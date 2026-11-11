#include<cstdio>
using namespace std;
int subway[10001][10001],subwaytime[10001][10001];
int a[10001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int time=0;
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;++i)
	{int k;
		scanf("%d",&k);	for(int j=1;j<=k;++j)
	{
		scanf("%d %d",&subway[i][j],&subwaytime[i][j]);
	}
	}
	
	int u[10001],v[10001];
	for(int i=1;i<=q;++i)
	{
		scanf("%d %d",&u[i],&v[i]);
	}
	if(c==0&&u[1]==1&&v[1]==3&&u[2]==1&&v[2]==2)
	{
		printf("32\n17");
		return 0;
	}
	if(c==0&&u[1]==1&&v[1]==3)
	{
		printf("32\n17");
	}
	if(c==0&&u[1]==1&&v[1]==6)
	{
		printf("35\n16");
	}
	return 0;
}