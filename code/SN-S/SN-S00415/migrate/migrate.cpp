#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--)
	{
		int n, d, ans = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= n; y++)
			{
				int s = 0;
				for (int k = x + 1; k < y && k <= n; k++)
				{
					if ((a[x] - a[k]) <= d && (a[k] - a[y]) <= d)
						s++;
				}
				if (s == 2)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
