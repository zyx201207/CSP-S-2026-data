#include<bits/stdc++.h>
using namespace std;
struct step
{
	int a, t;
};
int c, n, m, d, Q, w[500002], k[502], ans, dis[500002];
vector<step> g[502];
vector<int> e[500002];
bool vis[500002];
void dijkstra(int st, int ed)
{
	priority_queue<pair<int, int> > q;
	q.push(make_pair(0, st));
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	dis[st] = 0;
	while(q.size())
	{
		int l = -q.top().first, p = q.top().second;
		q.pop();
		if(vis[p]) continue;
		vis[p] = true;
		for(int i = 0; i < e[p].size(); i++)
		{
			int u = e[p][i];
			int pos;
			for(pos = 0; pos < k[u]; pos++)
			{
				if(g[u][pos].a == p)
				{
					break;
				}
			}
			for(int j = 0; j < k[u]; j++)
			{
				step v = g[u][j];
				if(dis[v.a] > dis[p] + v.t + g[u][pos].t)
				{
					dis[v.a] = dis[p] + v.t + g[u][pos].t;
//					printf("%d (dis[%d])%d+%d+(%d, %d)%d=%d\n", v.a, p, dis[p], v.t, u, pos, g[u][pos].t, dis[v.a]);
//					cout << v.a << ' ' <<dis[v.a] << '\n';
					q.push(make_pair(-dis[v.a], v.a));
				}
			}
		}
	}
	ans = dis[ed];
}
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++)
		{
			step s;
			cin >> s.a >> s.t;
			g[i].push_back(s);
			e[s.a].push_back(i);
		}
	}
	for(; Q--; )
	{
		int x, y;
		cin >> x >> y;
		ans = 1e+009;
		dijkstra(x, y);
		cout << w[x] + w[y] + ans << '\n';
//		cout << "114514\n";
	}
	return 0;
}