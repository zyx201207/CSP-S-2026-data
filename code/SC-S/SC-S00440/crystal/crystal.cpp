#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -f;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
typedef long long ll;
inline ll read_ll()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -f;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write_ll(ll x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write_ll(x / 10);
	}
	putchar(x % 10 + '0');
}
typedef unsigned long long ull;
inline ull read_ull()
{
	ull x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -f;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write_ull(ull x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		write_ull(x / 10);
	}
	putchar(x % 10 + '0');
}
const int N = 5e5 + 10;
ll a[N], sum[N];
int n;
ll m;
bool check(ll mid)
{
	for (int i = 1; i + mid - 1 <= n; ++i)
	{
		int j = i + mid - 1;
		if (a[j] * mid - (sum[j] - sum[i - 1]) <= m)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read();
	m = read_ll();
	for (int i = 1; i <= n; ++i)
	{
		a[i] = read_ll();
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + a[i];		
	}
	ll l = 1, r = n, mid = 0, ans = 1;
	while (l <= r)
	{
		mid = (l + r) >> 1;
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
	write_ll(ans);
	return 0;
}