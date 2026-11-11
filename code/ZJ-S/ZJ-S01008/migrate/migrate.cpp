#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

const int inf = 1e9;

void solve()
{
	int n;
	i64 d;
	cin >> n >> d;
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	auto bfs = [&](int start) -> i64
	{
		vector<int> dis(n + 1, inf);
		dis[start] = 0;
		int cur = start, x = 0;
		for (int i = start; i < n; i++)
		{
			if (a[i + 1] - a[cur] > d)
			{
				if (cur == i) break;
				x++;
				for (int j = cur + 1; j <= i; j++)
				{
					dis[j] = x;
				}
				cur = i;
			}
		}
		for (int i = cur + 1; i <= n; i++)
		{
			if (a[i] - a[cur] <= d)
			{
				dis[i] = dis[cur] + 1;
			}
		}
		queue<int> q;
		vector<bool> vis(n + 1, 0);
		vector<i64> cnt(n + 1, 0);
		vis[start] = 1;
		cnt[start] = 1;
		q.push(start);
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			
			for (int i = u + 1; i <= n; i++)
			{
				if (a[i] - a[u] > d)
				{
					break;
				}
				if (dis[i] == dis[u] + 1)
				{
					cnt[i] += cnt[u];
				}
				if (!vis[i])
				{
					vis[i] = 1;
					q.push(i);
				}
			}
		}
		i64 ans = 0;
		for (int i = start; i <= n; i++)
		{
			if (cnt[i] == 0) break;
			if (cnt[i] == 2)
			{
				ans++;
			}
		}
		return ans;
	};
	i64 ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += bfs(i);
	}
	cout << ans << "\n";
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
