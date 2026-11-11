#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,f[1010][1010],w[1010],a[1010],t[1010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.ont","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&p);
	if(0<=c&&c<=11)//1~11
	{
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=m;i++) scanf("%d",&w[i]);
		for(int i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
			{
				scanf("%d%d",&a[j],&t[j]);
			}
			for(int j=1;j<=k;j++)
			{
				for(int l=j+1;l<=k;l++)
				{
					f[a[j]][a[l]]=min(f[a[j]][a[l]],t[j]+t[l]);
					f[a[l]][a[j]]=min(f[a[j]][a[l]],t[j]+t[l]);
				}
			}
		}
		for(int i=1;i<=m;i++) f[i][i]=0;
		for(int x=1;x<=m;x++)
		{
			for(int k=1;k<=m;k++)
			{
				for(int y=1;y<=m;y++)
				{
					f[x][y]=min(f[x][y],f[x][k]+f[k][y]);
				}
			}
		}
		while(p--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x==y) printf("0\n");
			else printf("%d\n",w[x]+w[y]+f[x][y]);
		}
	}
	
	return 0;
}
