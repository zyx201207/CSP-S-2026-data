#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
const ll inf = 1e18;
int n, m, q;
ll w[M];
ll ans;
vector< ll > dis[N];
vector< pair< int, ll > > G[M + N];
void Dijkstra(int s)
{
	priority_queue< pair< int, ll >, vector< pair< int, ll > >, greater< pair< int, ll > > > pq;
	for (int i = 1; i <= m + n; i++)
	{
		dis[s][i] = inf;
	}
	dis[s][s + m] = 0;
	pq.push({s + m, 0});
	while (!pq.empty())
	{
		int u = pq.top().first;
		pq.pop();
		for (auto i : G[u])
		{
			ll v = i.first, t = i.second;
			if (dis[s][v] > dis[s][u] + t)
			{
				dis[s][v] = dis[s][u] + t;
				pq.push({ v, dis[s][v] });
			}
		}
	}
}
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
	int Case, d;
	cin >> Case >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; i++)
	{
		cin >> k;
		for (int j = 1, a, t; j <= k; j++)
		{
			cin >> a >> t;
			G[i + m].push_back({ a, t });
			G[a].push_back({ i + m, t });
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dis[i].resize(m + n + 5);
		Dijkstra(i);
	}
	while (q--)
	{
		int x, y;
		ans = inf;
		cin >> x >> y;
		for (int i = 1; i <= n; i++)
		{
			ans = min(ans, dis[i][x] + dis[i][y]);
		}
		ans += w[x] + w[y];
		cout << ans << "\n";
	}
    return 0;
}
