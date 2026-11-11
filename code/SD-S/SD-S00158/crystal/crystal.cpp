#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5;
long long a[MX + 10];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, m, i, j, k, sum, ans = 0;
	bool f = true;
	cin >> n >> m;
	for (i = 1; i <= n; i ++ )
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	for (i = 2; i < n; i ++ )
	{
		if (a[i] - a[i - 1] != a[i + 1] - a[i])
		{
			f = false;
		}
	}
	if (f == true)
	{
		for (i = 1; i <= n; i ++ )
		{
			if ((a[2] - a[1]) * i * (i - 1) / 2 > m)
			{
				break;
			}
		}
		cout << i - 1 << endl;
		return 0;
	}
	for (i = 1, j = 2; i < j && j <= n; i ++ )
	{
		for ( ; i < j && j <= n; j ++ )
		{
			sum = 0;
			for (k = i; k < j; k ++ )
			{
				sum += abs(a[j] - a[k]);
			}
			if (sum > m)
			{
				break;
			}
			else
			{
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << max(ans, j - i + 1) << '\n';
	return 0;
}
