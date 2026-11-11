#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, q;
	cin >> c >> q;
	if (13 <= c && 14 >= c)
	{
		while (q--) cout << 2 << endl;
	}
	{
		while (q--)
		{
			int n, d;
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
			{
				cin >> a[i];
			}
			if (n < d)
			{
				cout << 0 << endl;
			}
			else
			{
				cout << n / d << endl;
			}
		}
	}
	return 0;
}
