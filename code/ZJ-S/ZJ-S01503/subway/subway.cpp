#include<bits/stdc++.h>
using namespace std;
int shi,zhi,c,n,m,d,q,w[20005],k[505],a[505][20005],wei[505][20005],t[505][20005],num;
bool pan[20005];
void dfs(int x,int y,int cost)
{
	if(x==y)
	{
		num=min(num,cost);
		return ;
	}
	pan[x]=1;
	for(int i=1;i<=n;i++)
	{
		if(wei[i][x]!=0)
		{
			for(int j=1;j<=k[x];j++)
			{
				if(!pan[a[i][j]]) dfs(a[i][j],y,cost+t[i][wei[i][x]]+t[i][j]);
			}
		}
	}
	pan[x]=0;
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int j=1;j<=n;j++)
	{
		scanf("%d",&k[j]);
		for(int l=1;l<=k[j];l++)
		{
			scanf("%d%d",&a[j][l],&t[j][l]);
			wei[j][a[j][l]]=l;
		}
	}
	for(int i=1;i<=q;i++)
	{
		num=1e9;
		scanf("%d%d",&shi,&zhi);
		pan[shi]=1;
		dfs(shi,zhi,0);
		printf("%d\n",num+w[shi]+w[zhi]);
	}
	return 0;
}