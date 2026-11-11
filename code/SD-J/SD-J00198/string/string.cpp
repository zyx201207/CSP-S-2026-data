#include <bits/stdc++.h>
using namespace std;

const int MX = 2e5;
long long a[MX + 10];
char c[MX + 10];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, i, j, t, ans = 0;
	cin >> n;
	for (i = 1; i <= n; i ++ )
	{
		cin >> a[i] >> c[i];
	}
	for (i = 1, j = n; i < j; )
	{
		t = min(a[i], a[j]);
		a[i] -= t;
		a[j] -= t;
		if (c[i] != c[j])
		{
			ans += t;
		}
		if (a[i] == 0)
		{
			i ++ ;
		}
		if (a[j] == 0)
		{
			j -- ;
		}
	}
	cout << ans << '\n';
	return 0;
}
