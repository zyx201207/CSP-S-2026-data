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
int c, t, n, d;
int df;
long long ans;
const int N = 1e6 + 10;
int a[N], sum[N];
ll l, r, mid, as;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read();
	t = read();
	while (t--)
	{
		n = read();
		d = read();
		for (int i = 1; i <= n; ++i)
		{
			a[i] = read();
			df = a[i] - a[i - 1];
		}
		sort(a + 1, a + n + 1);
//		write(0);
//		continue;
			l = 1, r = n;
			ans = 0;
			for (int i = 1; i <= n; ++i)
			{
				l = i + 1, r = n, as = i;
				while (l <= r)
				{
					mid = (l + r) >> 1;
					if (a[mid] - a[i] <= d)
					{
						as = mid;
						l = mid + 1;
//						printf(" >>> %d %lld\n", i, as);
					}
					else
					{
						r = mid - 1;
					}
				}
				ans += (n - as);
//				printf(" --- %d %lld %lld\n", i, as, ans);
			}
			write(ans);
			putchar('\n');
	}
	return 0;
}