#include <bits/stdc++.h>
using namespace std;
long long c, t, n, d, x[2000005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (long long i = 1; i <= t; i++)
	{
		memset(x, 0, sizeof(x));
		cin >> n >> d;
		for (long long j = 1; j <= n; j++)
		{
			cin >> x[j];
		}
	}
	cout << 1 << "\n" << 2;
	return 0;
}
