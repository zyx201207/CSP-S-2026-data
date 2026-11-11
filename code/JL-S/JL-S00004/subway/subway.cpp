#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];//地铁口到站台
int k[505];//第 i 条线路经过的地铁站数
struct node
{
	int to,val;
	bool operator < (const node &a) const
	{
		return val>a.val;
	}
};
int ans[1505];
int ass[1505][1505];
vector<node>g[1505];
int vis[1505];
void bfs(int s,int t)
{
	priority_queue <node> q;
	q.push({s,0});
	while(!q.empty())
	{
		auto tp=q.top();
		q.pop();
		int u=tp.to;
		int val=tp.val;
		if(vis[u])continue;
		vis[u]=1;
		ass[s][u]=ass[u][s]=val;
		ans[u]=val;
		if(u==t)break;
		for(auto x:g[u])
		{
			int v=x.to;
			int w=x.val;
			if(!vis[v])
			{
				q.push({v,val+w});
			}
		}
	}
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
		for(int j=1;j<=k[i]*2;j+=2)
		{
			int v,w;
			scanf("%d%d",&v,&w);
			g[i].push_back({v+n,w});
			g[v+n].push_back({i,w});
		}
	}
	// if(q<=505)
	// {
	while(q--)
	{
		int s,t;
		scanf("%d%d",&s,&t);
		if(ass[s+n][t+n])
		{
			printf("%d\n",ass[s+n][t+n]+w[s]+w[t]);
			continue;
		}
		bfs(s+n,t+n);
		for(int i=1;i<=n+m;i++)vis[i]=0;
		printf("%d\n",ans[t+n]+w[s]+w[t]);
	}
}
		
// }
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/