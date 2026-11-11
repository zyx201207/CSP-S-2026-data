#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 5e2 + 10;
const long long INF = 1e18;
int n,m,d,Q;
long long a[N];
int k[M];
struct Edge
{
	int to;
	long long w;
};
vector < Edge > g[N];
vector < Edge > g2[M];
struct node
{
	int id;
	long long step;
	bool operator < (const node &cmp) const
	{
		return step > cmp.step;
	}
};
int vis[M];
long long dis[M][M];
priority_queue < node > q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int cs;
	scanf("%d %d %d %d %d",&cs,&m,&n,&d,&Q);
	for(int i = 1;i <= n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i = 1;i <= m;i++)
	{
		scanf("%d",&k[i]);
		for(int j = 0;j < k[i];j++)
		{
			int x;
			long long w;
			scanf("%d %lld",&x,&w);
			Edge tmp;
			tmp.to = i;
			tmp.w = w;
			g[x].push_back(tmp);
		}
	}
	for(int i = 1;i <= n;i++)
	{
		int u,v;
		long long wa,wb;
		Edge tmp;
//		printf("%d: ",i);
		int sz = g[i].size();
		for(int j = 0;j < sz;j++)
		{
			u = g[i][j].to;
			wa = g[i][j].w;
//			printf("%d ",u);
			for(int q = j + 1;q < sz;q++)
			{
				v = g[i][q].to;
				wb = g[i][q].w;
//				printf("%d: %d %d\n",i,u,v);
				tmp.to = v;
				tmp.w = wa + wb;
				g2[u].push_back(tmp);
				tmp.to = u;
				g2[v].push_back(tmp);
			}
		}
//		printf("\n");
	}
	for(int i = 1;i <= m;i++)
	{
//		for(int j = 0;j < g2[i].size();j++)
//		{
//			printf("%d %d %lld\n",i,g2[i][j].to,g2[i][j].w);
//		}
		while(!q.empty()) q.pop();
		for(int j = 1;j <= m;j++) vis[j] = 0;
		for(int j = 1;j <= m;j++) dis[i][j] = INF;
		node x;
		x.id = i;
		x.step = 0;
		dis[i][i] = 0;
		q.push(x);
		while(!q.empty())
		{
			node x = q.top();
			q.pop();
			if(vis[x.id]) continue;
			if(x.step > dis[i][x.id]) continue;
			vis[x.id] = 1;
			int sz = g2[x.id].size();
			int v;
			long long w;
			node nw;
			for(int j = 0;j < sz;j++)
			{
				v = g2[x.id][j].to;
				w = g2[x.id][j].w;
//				printf("!!!%d: %d\n",x.id,v);
				if(vis[v]) continue;
				if(dis[i][x.id] + w < dis[i][v])
				{
					dis[i][v] = dis[i][x.id] + w;
					nw.id = v;
					nw.step = dis[i][v];
					q.push(nw);
				}
			}
		}
//		for(int j = 1;j <= m;j++)
//		{
//			printf("%lld ",dis[i][j]);
//		}
//		printf("\n");
	}
	for(int i = 1;i <= Q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int u,v;
		long long res = INF;
		long long wa,wb,w;
		int sza = g[x].size();
		int szb = g[y].size();
		for(int j = 0;j < sza;j++)
		{
			u = g[x][j].to;
			wa = g[x][j].w;
			for(int q = 0;q < szb;q++)
			{
				v = g[y][q].to;
				wb = g[y][q].w;
				w = dis[u][v] + wa + wb;
				res = min(res,w);
			}
		}
		res = res + a[x] + a[y];
		printf("%lld\n",res);
	}
	return 0;
}
