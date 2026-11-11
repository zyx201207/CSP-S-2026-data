#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int x[2000010], c, t, n, d;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		if(c == 11 || c == 12)
		{
			d /= x[2] - x[1];
			if(d == 1)
				cout << 0 << endl;
			else
				cout << n - (2 * d - 1) << endl;
		}
		if(c == 13 || c == 14)
		{
			int l = lower_bound(x + 1, x + n + 1, x[n] - d) - x;
			int r = upper_bound(x + 1, x + n + 1, x[1] + d) - x - 1;
			if(r - l > 1)
			{
				cout << 0 << endl;
				continue;
			}
			if(r == l + 1)
			{
				long long ans = 0;
				for(int i = 1; i < n; i++)
				{
					ans += n - (upper_bound(x + 1, x + n + 1, x[i] + d) - x) + 1;
				}
				cout << ans << endl;
				continue;
			}
		}
	}
	return 0;
}
