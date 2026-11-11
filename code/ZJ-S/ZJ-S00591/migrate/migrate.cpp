#include <bits/stdc++.h>
using namespace std;
int c, t;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++)
	{
		long long x[200005];
		int n, d, ans = 0;
		for (int j = 1; j <= n; j++)
			cin >> x[j];
		for (int j = 1; j < n; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				int t = (x[k] - x[j] + d - 1) / d;
				if (k - j >= t - 1)
					ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

