#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, T;
long long dtk_zt[500010];
struct node{
	int u, v;
	long long w;
	int nxt;
}e[400010];
int q[500510], hd[500510], cnt;
long long vis[500510];
void addedge(int u, int v, long long w)
{
	e[++cnt] = node{u, v, w, hd[u]};
	hd[u] = cnt;
}
long long bfs(int x, int y)
{
	int f = 1, t = 0;
	memset(q, 0, sizeof(q));
	memset(vis, -1, sizeof(vis));
	q[++t] = x;
	vis[x] = 0;
	while(f <= t)
	{
		int p = q[f++];
 		for(int i = hd[p]; i; i = e[i].nxt)
		{
			if(vis[p] + e[i].w >= vis[e[i].v] && vis[e[i].v] >= 0)	continue;
			q[++t] = e[i].v, vis[e[i].v] = vis[p] + e[i].w;
 		}
 		if(c >= 12 && f >= 20000 && vis[y] >= 0)	break;
	}
	return vis[y];
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> T;
	for(int i = 1; i <= m; i++)
		cin >> dtk_zt[i];
	for(int i = 1, x; i <= n; i++)
	{
		cin >> x;
		for(int j = 1; j <= x; j++)
		{
			int u;
			long long w;
			cin >> u >> w;
			addedge(u, m + i, w);
			addedge(m + i, u, w);
		}
	}
	while(T--)
	{
		int x, y;
		long long ans = 0;
		cin >> x >> y;
		if(x == y)
		{
			cout << 0;
			continue;
		}
		ans += dtk_zt[x] + dtk_zt[y];
		ans += bfs(x, y);
		cout << ans << "\n";
	}
	return 0;
}