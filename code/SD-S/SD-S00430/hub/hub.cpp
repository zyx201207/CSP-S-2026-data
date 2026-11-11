#include<bits/stdc++.h>
#define N 1005
using namespace std;
int n,k,dis[N][N],fa[N],c[N];
bool b[N][N],fb[N];
int findfa(int u)
{
	return u==fa[u]?u:fa[u]=findfa(fa[u]);
}
void solve()
{
	scanf("%d%d",&n,&k);
	memset(dis,0x3f,sizeof(dis));
	int ans=dis[0][0];
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)	dis[i][i]=0;
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		dis[u][v]=dis[v][u]=1;
		b[u][v]=b[v][u]=1;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)	continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(int i=n;i>=n-k+1;i--)	c[i]=1;
	do
	{
		for(int j=1;j<=n;j++)	fa[j]=j,fb[j]=0;
		for(int j=1;j<=n;j++)
		{
			if(c[j])
			{
				for(int k=1;k<=n;k++)
				{
					if(b[j][k]&&c[k])
					{
						fa[findfa(j)]=findfa(k);
					}
				}
			}
		}
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(!c[j])	continue;
			int x=findfa(j);
			if(!fb[x])
			{
				fb[x]=1;
				cnt++;
			}
		}
		if(cnt<=2)
		{
			int res=0;
			for(int j=1;j<=n;j++)
			{
				if(c[j])	continue;
				int rres=dis[0][0];
				for(int k=1;k<=n;k++)
				{
					if(c[k])	rres=min(rres,dis[j][k]);
				}
				res=max(res,rres);
			}
			ans=min(ans,res);
		}
	}
	while(next_permutation(c+1,c+n+1));
	printf("%d\n",ans);
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)	solve();
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9
*/
