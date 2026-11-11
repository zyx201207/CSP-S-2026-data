#include <bits/stdc++.h>
#define int long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define endl '\n'
using namespace std;
struct edge
{
	int v, w;
	friend bool operator<(edge a, edge b)
	{
		return a.w > b.w;
	}
};
int c, n, m, d, q, w[5000], k[5000], a[5000][5000], t[5000][5000], x[100005], y[100005], tim[5000];
bitset<5000> vis;
vector<edge> g[5000];//1-m mouth|m+1-2m hall|2m+1-3m plate
void init()
{
	cin >> c >> n >> m >> d >> q;
	rep(i, 1, m)
	{
		cin >> w[i];
		g[i].push_back({i + m, w[i]});
		g[i + m].push_back({i, w[i]});
	}
	rep(i, 1, n)
	{
		cin >> k[i];
		rep(j, 1, k[i])
		{
			cin >> a[i][j] >> t[i][j];
			rep(jj, 1, k[i])
			{
				g[a[i][j] + 2 * m].push_back({a[i][jj] + 2 * m, 0});
				g[a[i][jj] + 2 * m].push_back({a[i][j] + 2 * m, 0});
				g[a[i][j] + m].push_back({a[i][jj] + 2 * m, t[i][j]});
				g[a[i][jj] + 2 * m].push_back({a[i][j] + m, t[i][j]});
			}
		}
	}
	rep(i, 1, q)
		cin >> x[i] >> y[i];
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	init();
	rep(_, 1, q)
	{
		priority_queue<edge> dijk;
		memset(tim, 0x3f, sizeof tim);
		tim[x[_]] = 0;
		dijk.push({x[_], 0});
		vis.reset();
		while (!dijk.empty())
		{
			edge nn = dijk.top();
			dijk.pop();
			if (vis[nn.v])
				continue;
			vis[nn.v] = 1;
			for (edge vv : g[nn.v])
				if (tim[vv.v] > tim[nn.v] + vv.w)
				{
					tim[vv.v] = tim[nn.v] + vv.w;
					dijk.push({vv.v, tim[vv.v]});
				}
		}
		cout << tim[y[_]] << endl;
	}
	return 0;
}
//mouth->hall->plate->hall->...->plate->hall->mouth