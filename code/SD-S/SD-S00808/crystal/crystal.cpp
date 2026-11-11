#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int N = 500005;
constexpr long long inf = 1000000000000000000;
long long read();
long long a[N], sum[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = read();
	long long m = read(), l = 1, r = n, mid, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		r = max(r, a[i]);
		l = min(l, a[i]);
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		sum[i] = a[i] + sum[i - 1];
	}
	auto check = [&](long long x)
	{
		long long tot = inf;
		for (int i = x; i <= n; i++)
		{
//			cout << a[i] * x - (sum[i] - sum[i - x]) << " ";
			tot = min(tot, (a[i] * x - (sum[i] - sum[i - x])));
		}
//		cout << " tot: " << tot << "\n";
		return tot <= m;
	};
	while (l <= r)
	{
		mid = (l + r) >> 1;
//		cout << mid << ": ";
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
	cout << ans << "\n";
	return 0;
}
long long read()
{
	long long res = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res * f;
}

/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/
