#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, T, a[2000005], cnt[2000005];

signed main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	cin >> c >> T;
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		int l, r = 0, ans = 0;
		for (int i = 2; i <= n + 1; i++)
		{
			if (a[i] - a[i - 1] <= m && i != n + 1)
				continue;
			l = r + 1, r = i - 1;
			if (r - l <= 2)
				continue;
			for (int j = l; j + 2 < r; j++)
			{
				for (int j = l; j <= r; j++)
					cnt[j] = 0;
				int last = j;
				for (int k = 1 + j; k <= r; k++)
				{
					if (a[k] - a[last] > m)
						last = k - 1;
					cnt[k] = cnt[last] + 1;
				}
				for (int k = j; k <= r; k++)
				{
					if (cnt[k] > cnt[k - 1] && a[k] - a[k - 2] <= m)
					{
						ans++;
						int point = k + 1;
						while (cnt[k] == cnt[point] && point <= r && a[point] - a[k - 2] <= m)
							ans++, point++;
						k = point - 1;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
