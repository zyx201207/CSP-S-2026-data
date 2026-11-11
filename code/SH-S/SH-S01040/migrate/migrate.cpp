#include <bits/stdc++.h>
using namespace std;

int c, t, n, m, cnt;
long long a[1500010];

void dfs(int step, int l, int r, int minn)
{
	if (step > minn || l > r)
		return;
	if (step == minn && l == r)
	{
		cnt++;
		return;
	}
	for (int i = 1; i <= m; i++)
		dfs(step + 1, l + i, r, minn);
}

bool check(int l, int r)
{
	int minn = (r - l) / m + 1;
	if ((r - l) % m == 0)
		return 0;
	cnt = 0;
	dfs(0, l, r, minn);
	if (cnt == 2)
		return 1;
	return 0;
}

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		long long x = 0;
		cin >> n >> m;
		int p = n;
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (i == 1)
				x = a[i];
			a[i] -= x;
			if (i > 2)
			{
				if (a[i - 1] - a[i - 2] > m && a[i] - a[i - 1] > m)
					a[i - 1] = a[i], n--, i--;
			}
		}
		if (a[n] - a[n - 1] > m)
			a[n - 1] = a[n], n--;
		int ans = 0;
			
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
			{
				ans += check(i, j);
			}
		cout << ans << '\n';
	}
	return 0;
}
