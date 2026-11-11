#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 100010
int c,t;
int n,k;

int Fa[N][20];

int tot=-1;
int head[N];
int ver[M];
int Next[M];

int Dep[N];

void Add(int u,int v)
{
	tot++;
	Next[tot]=head[u];
	head[u]=tot;
	ver[tot]=v;
	return;
}

int Lca(int x,int y)
{
	if(Dep[x]<Dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
	{
		if(Fa[x][i]==-1)continue;
		if(Dep[Fa[x][i]]<=Dep[y])x=Fa[x][i];
	}
	for(int i=20;i>=1;i--)
	{
		if(Fa[x][i]==-1)continue;
		if(Fa[x][i]==Fa[y][i])continue;
		x=Fa[x][i];
		y=Fa[y][i];
	}
	return 2;
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			Add(u,v);
			Add(v,u);
		}
//		Q.push(1);
//		Fa[1][0]=-1;
//		Dep[1]=1;
//		while(!Q.empty())
//		{
//			int x=Q.front();Q.pop();
//			for(int i=head[x];~i;i=Next[i])
//			{
//				int y=ver[i];
//				if(Fa[x][0]==y)continue;
//				Fa[y][0]=x;
//				Q.push(y);
//				Dep[y]=Dep[x]+1;
//			}
//		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=20;j++)
//			{
//				Fa[i][j]=Fa[i][j-1]+Fa[Fa[i][j-1]][j-1];
//			}
//		}
//		queue<int>Q;
		printf("%d\n",(k+1)/2);
	}
	return 0;
}
