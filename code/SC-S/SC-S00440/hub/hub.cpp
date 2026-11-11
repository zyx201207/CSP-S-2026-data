#include <cstdio>
#include <iostream>
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
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	c = read();
	t = read();
	while (t--)
	{
		int n, k;
		n = read();
		k = read();
		for (int i = 1; i <= n; ++i)
		{
			int x, y;
			x = read();
			y = read();
		}
		write(n + k - 1);
	}
	return 0;
}