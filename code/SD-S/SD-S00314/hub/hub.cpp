#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 2e6 + 5;
int dis[N],c,t,head[N],cnt,fa[N][25],n,k;
int tot,p[N],an = (1 << 30);
bool is_p[N],is_fixed[N];
struct edge
{
	int to,nxt; 
}e[M];
void addedge(int x,int y)
{
	e[++cnt].to = y;
	e[cnt].nxt = head[x];
	head[x] = cnt;
}
int lca(int x,int y)
{
	if(dis[x] < dis[y]) swap(x,y);
	for(int i = 20;i >= 0;i--) if(dis[fa[x][i]] >= dis[y]) x = fa[x][i];
	for(int i = 20;i >= 0;i--)
	{
		if(fa[x][i] != fa[y][i])
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return (x == y ? x : fa[x][0]);
}
int dist(int x,int y)
{
	return (dis[x] + dis[y] - 2 * dis[lca(x,y)]);
}
void dfs1(int x)
{
	for(int i = head[x];i;i = e[i].nxt)
	{
		if(e[i].to == fa[x][0]) continue;
		fa[e[i].to][0] = x;
		dis[e[i].to] = dis[x] + 1;
		dfs1(e[i].to);
	}
}
void dfs3(int x)
{
	is_fixed[x] = true;
	for(int i = head[x];i;i = e[i].nxt)
	{
		if(!is_p[e[i].to]) continue;
		if(is_fixed[e[i].to]) continue;
		dfs3(e[i].to);
	}
}
void dfs2(int x)
{
	if(tot > k) return;
	if(x == n + 1)
	{
		if(tot < k) return;
		for(int i = 1;i <= n;i++) is_fixed[i] = false;
		int ans = 0;
		for(int i = 1;i <= n;i++)
		{
			if(!is_p[i]) continue;
			if(is_fixed[i]) continue;
			ans++;
			dfs3(i);
		}
		if(ans > 2) return;
		int q = 0;
		for(int i = 1;i <= n;i++)
		{
			int sum = (1 << 30);
			for(int j = 1;j <= tot;j++) sum = min(sum,dist(i,p[j]));
			q = max(q,sum);
		}
		an = min(an,q);
		return;
	}
	dfs2(x + 1);
	p[++tot] = x; 
	is_p[x] = true;
	dfs2(x + 1);
	is_p[x] = false;
	tot--;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		an = 1 << 30;
		cnt = 0;
		memset(head,0,sizeof(head));
		memset(e,0,sizeof(e));
		memset(dis,0,sizeof(dis));
		scanf("%d%d",&n,&k);
		for(int i = 1;i < n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		fa[1][0] = 1;
		dfs1(1);
		for(int j = 1;j <= 20;j++)
		{
			for(int i = 1;i <= n;i++)
			{
				fa[i][j] = fa[fa[i][j - 1]][j - 1];
			}
		}
		dfs2(1);
		printf("%d\n",an);
	}
	return 0;
} 
