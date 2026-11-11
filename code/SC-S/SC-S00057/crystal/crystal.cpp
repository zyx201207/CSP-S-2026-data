# include <bits/stdc++.h>
# define abs fjdksl
//# include <windows.h>
using namespace std;
int n, m;
long long a[100012];
const long long MIN = -1e12 - 1;
const long long MAX = 1e12 + 1;
long long abs (long long x)
{
	if (x < 0) return -x;
	return x;
}
int check (long long mid)
{
	int x = n, now = n, cnt = m;
	while (a[now] > mid and now >= 1) now --; x = now;
	while (a[x] >= mid and x >= 1) x --;
	while (cnt and x >= 1)
	{
//		if (mid == 4) cout << cnt << ' ' << x << ' ' << a[x] << endl;
		if (cnt >= abs (mid - a[x]))
		{
			x --, cnt -= abs (mid - a[x + 1]);
		}
		else break;
	}
//	cout << "check : " << mid << " : " << now << ' ' << x << endl;
	return now - x;
}
int main ()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	ios :: sync_with_stdio (NULL);
	cin.tie (0x0), cout.tie (0x0);
	cin >> n >> m;
	long long mx = LONG_LONG_MIN;
	for (int i = 1; i <= n; i ++)
	{
		mx = max (mx, a[i]); 
		cin >> a[i];
	}
	sort (1 + a, 1 + a + n);
	long long x = a[1], z = a[n];
	long long y = x + z >> 1, m1, m2;
	while (x <= y)
	{
		m1 = x + y >> 1, m2 = y + z >> 1;
		int aa = check (m1), bb = check (m2);
		if (aa == bb) break;
		else if (aa < bb)
		{
			x = y, y = m2;
		}
		else
		{
			z = y, y = m1;
		}
	}
	long long fir = min (m1, min (m2, min (x, min (y, z))));
	long long sec = max (m1, max (m2, max (x, max (y, z))));
	int ans = 0;
	long long up = 1;
	for (int i = fir - 100000; i <= fir; i += 100)
	{
		up = i;
		if (ans > check (i)) break;
		ans = max (ans, check (i));
	}
	for (int i = up - 1000; i <= up + 1000; i ++)
	{
		ans = max (ans, check (i));
	}
	for (int i = fir; i <= sec; i ++) ans = max (ans, check (i));
	long long down = 1;
	for (int i = sec; i <= sec + 100000; i += 100)
	{
		down = i;
		if (ans > check (i)) break;
		ans = max (ans, check (i));
	}
	for (int i = down - 1000; i <= down + 1000; i ++)
	{
		ans = max (ans, check (i));
	}
	cout << ans << endl;
	return 0;
}
/*
5 5
1 2 4 8 9

*/