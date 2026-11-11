#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 5e2 + 5, M = 5e5 + 5;
ll w[M], k[N];
vector<int> tu[M];
vector<ll> t[N];
vector<pair<int, int>> g[405];
ll dis[405][405][205];
int num[405][205];
bool vis[405][405][205];
void dijkstra(int st)
{
	priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
	for (int i : tu[st])
	{
		dis[st][st][i] = w[st] + t[i][num[st][i] - 1];
		pq.push({w[st] + t[i][num[st][i] - 1], {st, i}});
	}
	while (!pq.empty())
	{
		int x = pq.top().se.fi, y = pq.top().se.se;
		pq.pop();
		if (vis[st][x][y])
			continue;
		vis[st][x][y] = 1;
		for (pair<int, int> i : g[x])
		{
			int v = i.first, w = i.second;
			if (w != y)
			{
				if (dis[st][v][w] > dis[st][x][y] + t[y][num[x][y] - 1] + t[w][num[x][w] - 1])
				{
					dis[st][v][w] = dis[st][x][y] + t[y][num[x][y] - 1] + t[w][num[x][w] - 1];
					pq.push({dis[st][v][w], {v, w}});
				}
			}
			else
			{
				if (dis[st][v][w] > dis[st][x][y])
				{
					dis[st][v][w] = dis[st][x][y];
					pq.push({dis[st][v][w], {v, w}});
				}
			}
		}
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof dis);
	int c, n, m, d, q, fl = 1;
	cin >> c >> n >> m >> d >> q;
	if (c && c <= 8)
	{
		for (int i = 1; i <= m; i++)
			cin >> w[i];
		for (int i = 1; i <= n; i++)
		{
			cin >> k[i];
			int lst = 0;
			for (int j = 1; j <= k[i]; j++)
			{
				int x, y;
				cin >> x >> y;
				t[i].push_back(y);
				tu[x].push_back(i);
				num[x][i] = j;
				if (lst)
				{
					g[lst].push_back({x, i});
					g[x].push_back({lst, i});
				}
				lst = x;
			}
		}
		for (int i = 1; i <= m; i++)
			dijkstra(i);
		while (q--)
		{
			int x, y;
			ll ans = 1e18;
			cin >> x >> y;
			for (int i = 1; i <= n; i++)
				ans = min(ans, dis[x][y][i] + t[i][num[y][i] - 1] + w[y]);
			cout << ans << '\n';
		}
	}
	return 0;
}
