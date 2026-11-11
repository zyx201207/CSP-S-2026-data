#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500050], l, r, mid, ans, tmp, flag = 1, d;
bool ok(int x)
{
	ans = 1e18;
	for (int j = 0; j <= n - x; j++)
	{
		tmp = 0;
		for (int i = 1; i <= x; i++) tmp += a[x + j] - a[i + j];
		ans = min(ans, tmp);
	}
	return ans <= m;
}
bool ok1(int x)
{
	ans = 1e18;
	for (int j = 0; j <= n - x; j++)
	{
		tmp = 0;
		for (int i = 1; i <= x; i++) tmp += (x - i) * d;
		ans = min(ans, tmp);
	}
	return ans <= m;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n < 5000)
	{	
		l = 1; r = n;
		while (l + 1 < r)
		{
			mid = (l + r) / 2;
			if (ok(mid)) l = mid;
			else r = mid - 1;
		}
		if (ok(r)) l = r;
		cout << l;
		return 0;
	}
	for (int i = 2; i < n; i++) if (a[i + 1] - a[i] != a[i] - a[i - 1]) flag = 0;
	if (flag)
	{
		d = a[2] - a[1];
		l = 1; r = n;
		while (l + 1 < r)
		{
			mid = (l + r) / 2;
			if (ok(mid)) l = mid;
			else r = mid - 1;
		}
		if (ok(r)) l = r;
		cout << l;
	}
	return 0;
}
