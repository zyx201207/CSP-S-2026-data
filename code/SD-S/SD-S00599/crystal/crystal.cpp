#include <bits/stdc++.h>
using namespace std;

int n, f = 1, f2 = 1;
long long m;
long long a[500010];

bool cmp(long long a, long long b)
{
	return a > b;
}

int check(int mid)
{
	for (int i = 1;i <= n;i++)
	{
		long long s = 1, k = m;
		for (int j = i+1;j <= n;j++)
		{
			if (k < 0 || k < a[i] - a[j]) break;
			if (a[i] == a[j])
			{
				s += 1;
				continue;
			}
			if (k >= a[i] - a[j])
			{
				s += 1;
				k -= a[i] - a[j];
				continue;
			}
		}
		if (s >= mid) return 1;
	}
	return 0;
}

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		if (a[i] != i) f = 0;
		if (i != 1 && i != 2 && a[i] - a[i-1] != a[i-1] - a[i-2]) f2 = 0;
	}
	if (f == 1)
	{
		long long k = 0;
		for (int i = 1;i <= n;i++)
		{
			k += i;
			if (k == m)
			{
				cout << i + 1;
				return 0;
			}
			else if (k > m)
			{
				cout << i;
				return 0;
			}
		}
	}
	if (f2 == 1)
	{
		long long k = 0;
		for (int i = 1;i <= n;i++)
		{
			k += i * (a[2] - a[1]);
			if (k == m)
			{
				cout << i + 1;
				return 0;
			}
			else if (k > m)
			{
				cout << i;
				return 0;
			}
		}
	}
	sort(a + 1, a + n + 1, cmp);
	int l = 1, r = n;
	while (l < r)
	{
		int mid = r-(r-l)/2;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l;
	return 0;
}
