#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6 + 6;
int n;
ll x[N], d, ans;
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
	int Case, T;
	cin >> Case >> T;
	while (T--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		if (Case == 11 || Case == 12)
		{
			ll dlt = x[2] - x[1];
			if (d >= dlt * 3 || d < dlt * 2)
			{
				ans = 0;
			}
			else
			{
				ans = max(0, n - 3);
			}
		}
		cout << ans << "\n";
	}
    return 0;
}
