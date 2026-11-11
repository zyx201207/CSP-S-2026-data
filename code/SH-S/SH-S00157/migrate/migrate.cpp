#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
long long c, t, n;
long long d;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		cin >> d;
		long long x, l, ans;
		for (int j = 1; j <= n; j++)
		{
			cin >> a[j];
		}
		x = a[2] - a[1];
		l = d / x;
		if (d < x * 2 || l * 2 > n) 
		{
			cout << 0 << "\n";
			continue;
		}
		else
		{
			long long s = 2 * l - 1;
			ans = n - s;
			cout << ans << "\n";
		}
	}
	return 0;
 } 
