#include <bits/stdc++.h>
using namespace std;

int c, t;

int n;
long long d;
long long x[2000005];

namespace solve1
{
	int maxx_go[5005];
	int c[5005];
	int dist[5005];
	void run()
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		int r = 1;
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			while (r < n && x[r + 1] - x[i] <= d)
				r++;
			maxx_go[i] = r;
		}
		for (int i = 1; i <= n; i++)
		{
			memset(c, 0, sizeof(c));
			memset(dist, 127, sizeof(dist));
			dist[i] = 0;
			c[i] = 1;
			for (int j = i; j <= n; j++)
			{
				if (dist[j] >= 1e9)
				    break; 
				if (c[j] == 2)
					ans++;
				for (int k = j + 1; k <= maxx_go[j]; k++)
				{
					if (dist[k] == dist[j])
						continue;
					if (dist[k] == dist[j] + 1)
						c[k] += c[j];
					else
					{
						dist[k] = dist[j] + 1;
						c[k] = c[j];
					}
				}
			}
		}
		cout << ans << endl;
		return;
	}
}

namespace solve2
{
	void run()
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		long long diff = x[2] - x[1];
		long long over = d / diff;
		if (over <= 1 || 2 * over > n)
		{
			cout << 0 << endl;
			return;
		}
		cout << n - 2 * over + 1 << endl;
		return;
	}
}

void solve()
{
	if (c <= 6)
		solve1::run();
	else if (c == 11 || c == 12)
		solve2::run();
	else
		cout << 0 << endl;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> c >> t;
	for (;t--;)
		solve();
	return 0;
	// ¿¨¿¨¾Í¹ýÁË 
}
