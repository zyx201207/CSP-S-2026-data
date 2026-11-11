#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int p;
	long long cnt;
};
int w[500005],k[505];
long long dis[505],DIS[500005];
map<int,int>t[505],a[505],T[505];
vector<int>g[500005];
queue<Edge>q;
long long ans=0;
int x,y;
void bfs()
{
	q.push({x,0ll});
	while(!q.empty())
	{
		int p=q.front().p;
		long long cnt=q.front().cnt;
		q.pop();
		if(p==y)
		{
			ans=cnt;
			continue;
		}
		for(int x:g[p])
		{
			if(cnt+T[x][p]<dis[x])
			{
				dis[x]=cnt+T[x][p];
				for(int i=1;i<=k[x];i++)
					if(cnt+T[x][p]+t[x][i]<DIS[a[x][i]])
					{
						DIS[a[x][i]]=cnt;
						q.push({a[x][i],cnt+T[x][p]+t[x][i]});
					}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++)
		{
			scanf("%d%d",&a[i][j],&t[i][j]);
			g[a[i][j]].push_back(i);
			T[i][a[i][j]]=t[i][j];
		}
	}
	while(q--)
	{
		ans=9e18;
		for(int i=1;i<=n;i++)
			dis[i]=9e18;
		for(int i=1;i<=m;i++)
			DIS[i]=9e18;
		scanf("%d%d",&x,&y);
		bfs();
		printf("%lld\n",ans+w[x]+w[y]);
	}
}