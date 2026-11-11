#include <bits/stdc++.h>
using namespace std;

#define int long long

int minn = 0x3f3f3f3f3f3f3f3f, num = 0;
int rt[2000005], x[2000005];

void dfs(int x, int y, int st)
{
	if (x == y)
	{
		if (minn == st) num++;
		else if (minn > st)
		{
			num = 1;
			minn = st;
		}
		return;
	}
	for (int i = x + 1; i <= rt[x]; i++)
	{
		if (st + 1 > minn) continue;
		if (i > y) continue;
		dfs(i, y, st + 1);
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n, d, j = 1;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		x[n + 1] = 0x3f3f3f3f3f3f3f3f;
		for (int i = 1; i <= n; i++)
		{
			for (j; j <= n + 1; j++)
			{
				if (x[j] - x[i] > d)
				{
					j--;
					break;
				}
			}
			rt[i] = j;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				minn = 0x3f3f3f3f3f3f3f3f, num = 0;
				dfs(i, j, 0);
				if (num == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
