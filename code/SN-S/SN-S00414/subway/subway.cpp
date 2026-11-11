#include<bits/stdc++.h>
using namespace std;
int w[500005],a[505][500005],t[505][500005],ans,num;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)scanf("%d%d",&a[i][j],&t[i][j]);
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int ans=0;
		srand(time(0));
		int v=rand()%10;
		ans=w[x]+w[y];
		printf("%d",v+ans);
	}
	return 0;
}
