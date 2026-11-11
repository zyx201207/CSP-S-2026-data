#include <algorithm>
#include <iostream>
#include <cstdio> 
#include <vector>
#include <map>
#define ll long long
using namespace std;

struct Node
{
	ll line, time;
};
struct Edge
{
	ll v, w;
};

ll w[500010];
ll f[510][510];
ll df[510][510];
vector <Node> e[500010];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++)
	{
		ll k;
		cin >> k;
		for (ll j = 1; j <= k; j++)
		{
			ll x, t;
			cin >> x >> t;
			e[x].push_back({i, t});
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			f[i][j] = 1e18;
		}
	}
	for (ll i = 1; i <= m; i++)
	{
		if (e[i].size() >= 2)
		{
			for (Node t1 : e[i])
			{
				for (Node t2 : e[i])
				{
					if (t1.line != t2.line)
					{
						f[t1.line][t2.line] = min(t1.time + t2.time, min(f[t1.line][t2.line], f[t2.line][t1.line]));
						f[t2.line][t1.line] = f[t1.line][t2.line];
					}
				}
			}
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= n; j++)
		{
			df[i][j] = f[i][j];
		}
	}
	for (ll k = 1; k <= n; k++)
	{
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= n; j++)
			{
				df[i][j] = min(df[i][j], df[i][k] + df[k][j]);
			}
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		df[i][i] = 0;
	}
	for (ll i = 1; i <= q; i++)
	{
		ll x, y;
		cin >> x >> y;
		ll ans = w[x] + w[y];
		bool f = false;
		ll minn = 1e18;//ll
		for (Node t1 : e[x])
			{
				for (Node t2 : e[y])
				{
					minn = min(minn, t1.time + t2.time + df[t1.line][t2.line]);
				}
			}
		cout << ans + minn << '\n';
	}
//	for (ll i = 1; i <= n; i++)
//		{
//			for (ll j = i + 1; j <= n; j++)
//			{
//				cout << i << ' ' << j << ' ' << df[i][j] << '\n';
//			}
//		}
	return 0;
}
//0 3 7 20 2
// 8 3 6 1 7 2 9
// 3 1 4 2 5 5 100
// 3 2 6 3 1 7 2
// 4 3 2 5 100 4 6 6 7
