#include <bits/stdc++.h> 
using namespace std;
int c,n,m,d,q;
#define N 500005
#define M N*2
int w[N],k;
int head[N],ver[M],Next[M],edge[M],tot;
void ADD(int x,int y,int z)
{
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);//从每个地铁站的地铁口走到站厅的时间 
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d %d",&x,&y);
			ADD()
		}
	}
	return 0;
}
