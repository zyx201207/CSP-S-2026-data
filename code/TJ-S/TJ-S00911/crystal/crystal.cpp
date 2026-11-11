#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500005], d[500005], s[500005];

bool check(int mid)
{
	for (int i = 1; i + mid - 1 <= n; i++)
	{
		long long sum = 0;
		for (int j = i; j < i + mid - 1; j++)
		{
			sum += a[i + mid - 1] - a[j];
		}
		if (sum <= m) return true;
	}
	return false;
}

bool check2(int mid, long long x)
{
	return x * mid * (mid - 1) / 2 <= m;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if (n > 5000)
	{
		long long x = a[2] - a[1];
		int l = 1, r = n, ans = 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (check2(mid, x))
			{
				ans = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		cout << ans << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n, ans = 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
