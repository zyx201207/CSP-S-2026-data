#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[500050], k[550], x[100010], y[100010], tmp, ans, dist[501050], vis[501050], s, mindis, u;
vector <int> a[510], t[510];
struct Edge
{
	int v, dis;
};
vector <Edge> to[501050];
Edge E;
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 0; j < k[i]; j++)
		{
			cin >> u;
			a[i].push_back(u);
			E.v = u;
			cin >> tmp;
			t[i].push_back(tmp);
			E.dis = tmp;
			to[m + i].push_back(E);
			E.v = m + i;
			to[u].push_back(E);
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x[i] >> y[i];
		ans = w[x[i]] + w[y[i]];
		for (int j = 1; j <= n + m; j++)
		{
			dist[j] = 1e9;
			vis[j] = 0;
		}
		for (int j = 0; j < to[x[i]].size(); j++) dist[to[x[i]][j].v] = to[x[i]][j].dis;
		dist[x[i]] = 0; vis[x[i]] = 1; 
		for (int j = 1; j <= m + n; j++)
		{
			mindis = 1e9;
			for (int ss = 1; ss <= m + n; ss++)
			{
				if (dist[ss] < mindis and not vis[ss])
				{
					s = ss;
					mindis = dist[ss];
				}
			}
			for (int ss = 0; ss < to[s].size(); ss++)
			{
				if (to[s][ss].dis + dist[s] < dist[to[s][ss].v]) dist[to[s][ss].v] = to[s][ss].dis + dist[s];
			}
			vis[s] = 1;
		}
		cout << dist[y[i]] + ans << endl;
	}
	return 0;
}
