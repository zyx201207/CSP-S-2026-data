#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
int w[M];
int k[N];
struct Node
{
	int id,t;
}a[N][M];
struct Edge
{
	int to,next,cost;
}x[M*N*2];
int pre[N],cnt;
void add(int u,int v,int time)
{
	x[++cnt]={v,pre[u],time};
	pre[u]=cnt;
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
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j].id,&a[i][j].t);
			if(j>1)
			{
				add(a[i][j].id,a[i][j-1].id,0);
				add(a[i][j-1].id,a[i][j].id,0);
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int t1=1;t1<=k[i];t1++)
			{
				for(int t2=1;t2<=k[i];t2++)
				{
					if(a[i][t1].id==a[i][t2].id)
					{
						add(a[i][t1].id,a[i][t2].id,a[i][t1].t+a[i][t2].t);
					}
				}
			}
		}
	}
	return 0;
}
