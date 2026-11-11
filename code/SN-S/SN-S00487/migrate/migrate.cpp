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
		if (!x)
			return;
		write(x / 10), putchar(48 ^ (x % 10));
		return;
	}
	template <typename T>
	inline void writesp(T x)
	{
		write(x), putchar(' ');
	}
	template <typename T>
	inline void writeln(T x)
	{
		write(x), putchar('\n');
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
		if (!x)
			return;
		write(x / 10), putchar(48 ^ (x % 10));
		return;
	}
	inline void writesp(i128 x)
	{
		write(x), putchar(' ');
	}
	inline void writeln(i128 x)
	{
		write(x), putchar('\n');
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
	}
	inline void writeln(string x)
	{
		write(x), putchar('\n');
	}
}

namespace Problem
{
	inline void solve()
	{
		return;
	}
}

signed main()
{
	freopen("migrate.in", "r", stdin), freopen("migrate.out", "w", stdout);
	Problem::solve();
	return 0;
}
