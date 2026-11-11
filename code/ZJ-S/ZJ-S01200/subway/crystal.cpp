#include<bits/stdc++.h>
using namespace std;
const int N = 510,M = 500010;
int c,n,m,d,t,w[M],k[N],cnt,top[N],dis[N];
bool vis[M];
struct Edge
{
	int v,w;
};
vector<Edge> a[M];
struct point
{
	int u,dis,nxt,to;
};
point b[M];
struct node
{
	int dis,pos;
	bool operator <(const node &x)const
	{
		return x.dis < dis;
	}
};
priority_queue<node> q;
void add (int u,int v,int w)
{
	cnt++;
	b[cnt].dis = w;
	b[cnt].to = v;
	b[cnt].nxt = top[u];
	top[u] = cnt;
};
void dijkstra (int s)
{
	dis[s] = 0;
	q.push({0,s});
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		int u = x.pos,w = x.dis;
//		cout << u << " " << w << endl;
		if (vis[u] == 1)
		{
			continue;
		}
		vis[u] = 1;
		for (int i=top[u];i;i=b[i].nxt)
		{
//			cout << i << endl;
			int v = b[i].to;
			if (dis[v] > dis[u]+b[i].dis)
			{
				dis[v] = dis[u]+b[i].dis;
				q.push({dis[v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> t;
	for (int i=1;i<=m;i++)
	{
		cin >> w[i];
	}
	for (int i=1;i<=n;i++)
	{
		cin >> k[i];
		for (int j=1;j<=k[i];j++)
		{
			int x,y;
			cin >> x >> y;
			a[x].push_back({i,y});
//			a[y].push_back({i,x});
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<a[i].size();j++)
		{
			for (int k=0;k<a[i].size();k++)
			{
//				cout << j << " " << k << endl;
				if (j == k)
				{
					continue;
				}
				add(a[i][j].v,a[i][k].v,a[i][j].w+a[i][k].w);
				add(a[i][k].v,a[i][j].v,a[i][j].w+a[i][k].w);
			}
		}
	}
	for (int i=1;i<=t;i++)
	{
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));
		int x,y;
		cin >> x >> y;
//		cout << a[x].size() << " " << a[y].size() << endl;
		for (int j=0;j<a[x].size();j++)
		{
//			cout << a[x][j].v << " " << a[x][j].w << endl;
			add(n+1,a[x][j].v,w[x]+a[x][j].w);
		}
//		cout << endl;
		for (int j=0;j<a[y].size();j++)
		{
//			cout << a[y][j].v << " " << a[y][j].w << endl;
			add(a[y][j].v,n+2,w[y]+a[y][j].w);
		}
//		for (int j=1;j<=cnt;j++)
//		{
//			cout << j << " " << b[j].u << " " << b[j].dis << " " << b[j].nxt << " " << b[j].to << endl;
//		}
		dijkstra(n+1);
//		for (int j=1;j<=n+2;j++)
//		{
//			cout << dis[i] << " ";
//		}
		cout << dis[n+2] << endl;
		top[n+1] = 0;
		top[n+2] = 0;
		cnt-=a[x].size();
		cnt-=a[y].size();
	}
	return 0;
}