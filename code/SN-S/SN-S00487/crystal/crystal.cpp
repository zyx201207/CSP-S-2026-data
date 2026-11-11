#include <bits/stdc++.h>
#define int long long
using namespace std;
using i128 = __int128;
using ld = long double;
using pii = pair <int, int>;

namespace IO
{
	template <typename T>
	inline void read(T &x)
	{
		x = 0;
		char c;
		bool f = false;
		while (c = getchar(), !isdigit(c) && c != EOF)
			if (c == '-')
				f = true;
		while (isdigit(c) && c != EOF)
			x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
		if (f)
			x = -x;
		return;
	}
	template <typename T>
	inline void write(T x)
	{
		if (x < 0)
			putchar('-'), x = -x;
		if (!(x / 10))
		{
			putchar(48 ^ (x));
			return;
		}
		write(x / 10), putchar(48 ^ (x % 10));
		return;
	}
	template <typename T>
	inline void writesp(T x)
	{
		write(x), putchar(' ');
		return;
	}
	template <typename T>
	inline void writeln(T x)
	{
		write(x), putchar('\n');
		return;
	}
	inline void read(i128 &x)
	{
		x = 0;
		char c;
		bool f = false;
		while (c = getchar(), !isdigit(c) && c != EOF)
			if (c == '-')
				f = true;
		while (isdigit(c) && c != EOF)
			x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
		if (f)
			x = -x;
		return;
	}
	inline void write(i128 x)
	{
		if (x < 0)
			putchar('-'), x = -x;
		if (!(x / 10))
		{
			putchar(48 ^ (x));
			return;
		}
		write(x / 10), putchar(48 ^ (x % 10));
		return;
	}
	inline void writesp(i128 x)
	{
		write(x), putchar(' ');
		return;
	}
	inline void writeln(i128 x)
	{
		write(x), putchar('\n');
		return;
	}
	inline void read(string &x)
	{
		x = "";
		char c;
		while (c = getchar(), isspace(c) && c != EOF);
		while (!isspace(c) && c != EOF)
			x += c, c = getchar();
		return;
	}
	inline void write(string x)
	{
		for (char c : x)
			putchar(c);
		return;
	}
	inline void writesp(string x)
	{
		write(x), putchar(' ');
		return;
	}
	inline void writeln(string x)
	{
		write(x), putchar('\n');
		return;
	}
}

namespace Problem
{
	int n, m, *a = NULL, *d = NULL, *s = NULL, t, ans;
	int ansi, anst;
	inline calc(int a, int b)
	{
		return d[a] * (a - b) - s[a - 1] + s[b - 1];
	}
	inline void solve()
	{
		IO::read(n), IO::read(m), a = new int[n + 10]{}, d = new int[n + 5]{}, s = new int[n + 5]{}, ans = 0, t = 1;
		for (int i = 2; i <= n + 1; i++)
			IO::read(a[i]);
		sort (a + 2, a + n + 2);
		for (int i = 2; i <= n + 1; i++)
			d[i] = a[i] - a[2], s[i]= s[i - 1] + d[i];
		for (int i = 2; i <= n + 1; i++)
		{
			while (calc(i, t) > m)
				t++;
			if (i - t > ans)
				ans = i - t, ansi = i, anst = t;
		}
		IO::writeln(++ans);
		delete[] a, delete[] d, delete[] s;
		return;
	}
}

signed main()
{
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	Problem::solve();
	return 0;
}
