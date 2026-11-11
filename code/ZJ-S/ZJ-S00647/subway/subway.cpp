#include <bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int c,n,m,d,q;
int val[M];
struct edge
{
	int v;
	long long w;
};
vector<edge>mp[M];
long long p[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&val[i]);
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a,t;
			scanf("%d %d",&a,&t);
			mp[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) 
		{
			if(i==j) continue;
			p[i][j]=9e9;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<mp[i].size();j++)
		{
			for(int k=j+1;k<mp[i].size();k++)
			{
				int x=mp[i][j].v,y=mp[i][k].v;
				long long ww=mp[i][j].w+mp[i][k].w;
				p[x][y]=min(p[x][y],ww);
				p[y][x]=p[x][y];
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(p[i][j]>p[i][k]+p[k][j])
				{
					p[i][j]=p[i][k]+p[k][j];
				}
			}
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		long long ans=LLONG_MAX;
		for(int i=0;i<mp[x].size();i++)
		{
			for(int j=0;j<mp[y].size();j++)
			{
				int u1=mp[x][i].v,v1=mp[y][j].v;
				ans=min(ans,val[x]+mp[x][i].w+p[u1][v1]+mp[y][j].w+val[y]);
			}
		}
		printf("%lld\n",ans);
	}
}