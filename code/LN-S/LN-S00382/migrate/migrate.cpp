#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int c,t;
	cin >> c >> t;
	while (t--)
	{
		int n,d,x[5005],ans = 0;
		cin >> n >> d;
		if (n <= 3)
		{
			cout << 0;
			continue;
		}
		for (int i = 1;i <= n;i++) cin >> x[i];
		int di = x[2] - x[1];
		bool flag = 1;
		for (int i = 1;i < n;i++)
		{
			if (di != x[i + 1] - x[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			if (d >= 2 * di && d < 3 * di) cout << n - 3;
			else cout << 0;
			cout << '\n';
		}
		else
		{
			for (int i = 1;i <= n - 3;i++)
			{
				if (x[i + 2] - x[i] <= d && x[i + 3] - x[i + 1] <= d && x[i + 3] - x[i] > d)
				{
					ans++;
				}
			}
			cout << ans << '\n';
		}
	}
	return 0;
}
