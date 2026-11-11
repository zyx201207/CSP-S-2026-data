#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, x, y, a[505], d[505][505], vis[505], u;
struct xy
{
	int x, y;
	bool operator< (const xy k) const{
		return x < k.x;
	}
} ;
vector <xy> e[505];
priority_queue <xy> q;
void o(int x)
{
	memset(vis, 0, sizeof(vis));
	q.push({0, x});
	d[x][x] = 0;
	while (q.size())
	{
		xy u = q.top();
		q.pop();
		if (vis[x])
		{
			continue;
		}
		vis[x]++;
		for (int i = 0; i < n; i++)
		{
			::u = 0;
			for (xy v : e[i])
			{
				if (v.x == u.y)
				{
					::u = 1;
				}
			}
			if (::u)
			{
				for (xy v : e[i])
				{
					if (d[x][v.x] > d[x][u.y] + v.y)
					{
						d[x][v.x] = d[x][u.y] + v.y;
						q.push({d[x][v.x], v.x});
					}
				}
			}
		}
	}
}
int main()
{
	freopen ("subway.in", "r", stdin);
//	freopen ("subway.out", "w", stdout);
	cin >> x >> n >> m >> y >> t;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> x >> y;
			e[i].push_back({x, y});
		}
	}
	memset(d, 0x3f, sizeof(d));
	for (int i = 1; i <= m; i++)
	{
		sort(e[i].begin(), e[i].end());
		o(i);
	}
	while (t--)
	{
		cin >> x >> y;
		cout << d[x][y] + a[x] + a[y] << "\n";
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}
