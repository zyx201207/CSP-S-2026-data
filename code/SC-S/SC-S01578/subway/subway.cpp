#include <bits/stdc++.h>
using namespace std;
#define int long long
#define eb emplace_back
#define ep emplace
#define pii pair <int, int>
#define fi first
#define se second
#define endl '\n'
constexpr int MAXN = 500005 + 505;
int c, n, m, d, q;
vector <pii> adj[MAXN];
int w[MAXN];
bitset <MAXN> vis;
auto cmp = [](const auto& A, const auto& B)
{
	return A.se > B.se;
};
int dijkstra (int st, int en)
{
	vis.reset();
	priority_queue <pii, vector <pii>, decltype(cmp)> pq(cmp);
	pq.ep(st, 0);
	vis.set(st);
	while (not pq.empty())
	{
		auto u = pq.top().fi, cost = pq.top().se;
		if (u == en)
		{
			return cost;
		}
		pq.pop();
		for (auto it : adj[u])
		{
			
			if (not vis[it.fi])
			{
				pq.ep(it.fi, cost + it.se);
				vis.set(it.fi);
			}
		}
	}
	return -1;
} 
signed main ()
{
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i ++)
	{
		cin >> w[i];
	}
	for (int i = 1 ; i <= n ; i ++)
	{
		int k;
		cin >> k;
		int new_node = m + i;
		for (int j = 1 ; j <= k ; j ++)
		{
			int a, t;
			cin >> a >> t;
			adj[new_node].eb(a, t);
			adj[a].eb(new_node, t);
		}
	}
	while (q --)
	{
		static int x, y;
		cin >> x >> y;
		cout << w[x] + dijkstra(x, y) + w[y] << endl;
	}
	return 0;
}
//什么雷霆题目，60pts，15：50