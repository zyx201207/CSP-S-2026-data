#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e6 + 10;

int c, t, n;
ll d, x[maxn], ans, minn = 1e18l;

void dfs (int now, int ed, ll steps)
{
	//cout << now << ' ' << ed << ' ' << steps << ' ' << ans << ' ' << minn << '\n';
	if (now == ed)
	{
		if (steps < minn)
		{
			minn = steps;
			ans = 1;
		}
		else if (steps == minn)
		{
			ans++;
		}
		return;
	}
	for (int i = now + 1; i <= ed; i++)
	{
		if (x[i] - x[now] <= d)
		{
			dfs(i, ed, steps + 1);
		}
	}
}

int main ()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	cin>> c >> t;
	while (t--)
	{
		cin >> n >> d;
		ll res = 0;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				ans = 0, minn= 1e18l;
				dfs(i, j, 0);
				if (ans == 2) res++;
				//cout << '\n' << i << ' ' << j << ' ' << res << "\n\n";
			}
		}
		cout << res << '\n';
	}
	return 0;
}

