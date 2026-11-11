#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[505][500005],t[505][500005],k[500005],x[100005],y[100005];

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
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	for(int r=1;r<=q;r++)
	{
		scanf("%d%d",&x[r],&y[r]);
	}
	for(int i=1;i<=q;i++)
	{
		
	}
	return 0;
 } 
