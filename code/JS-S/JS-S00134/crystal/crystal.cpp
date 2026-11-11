#include <bits/stdc++.h>
#define int long long
using namespace std;

__int128 d[500005], sd[500005];
int n, m, a[500005];

inline void print (__int128 x)
{
	if (x < 0)
	{
		x = -x;
		putchar ('-');
	}
	if (x > 9)
		print (x / 10);
	putchar (x % 10 + '0');
}

int check (int x)
{
	__int128 jsp = 0;
	for (int i = 1; i <= x; i++)
		jsp += d[i] * i;
	if (jsp <= m)
		return 1;
	for (int i = 2; i + x <= n; i++)
	{
		jsp -= sd[i + x - 2] - sd[i - 2];
		jsp += d[i + x - 1] * x;
		if (jsp <= m)
			return 1;
	}
	return 0;
}

signed main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n - 1; i++)
		d[i] = a[i + 1] - a[i];
	for (int i = 1; i <= n - 1; i++)
		sd[i] = sd[i - 1] + d[i];

	int l = 0, r = n, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check (mid - 1))
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans << "\n";
	return 0;
}
