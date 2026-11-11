#include <bits/stdc++.h>
using namespace std;

vector<int> x;
bitset<static_cast<int>(2e6 + 5)> vis;
int n, d;

int cnt = 0;
void dfs(int from, int now, int aim, int &mind, int deep, int fa, int &ways)
{
	if (vis[now])
		return;
	if (from == 1 && aim == 4)
		// clog << from << " "<< fa << " " << now << " "<< aim << "  "<< mind<< endl;
		if (now == aim)
		{
			if (deep == mind)
				return void(ways++);
			if (deep < mind)
			{
				mind = deep;
				ways = 1;
			}
		}
	if (deep > n)
		return;
	vis[now] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (abs(x[now] - x[i]) > d)
			continue;
		if (i == fa || i == now)
			continue;
		// clog << cnt++;
		dfs(from, i, aim, mind, deep + 1, now, ways);
	}
	vis[now] = 0;
}

signed main()
{
#ifndef DEBUG
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);

	int c, t;
	cin >> c >> t;
	while (t--)
	{
		vis.reset();
		int ans = 0;
		cin >> n >> d;
		if (n > 15)
		{
			cout << 0 << "\n";
			continue;
		}
		x.assign(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				// cerr << i << j;
				int ways = 0, mind = 0x3f3f3f3f;
				dfs(i, i, j, mind, 0, i, ways);
				// clog << ways << "! ";
				if (ways == 2)
					ans++;
			}
			// clog << "\n";
		}
		cout << ans << "\n";
	}
	cout << endl;

	return 0;
}