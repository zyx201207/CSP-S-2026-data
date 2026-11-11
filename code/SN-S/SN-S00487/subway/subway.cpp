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
	const int MAXM = 500005;
	int c, n, m, d, q, k, a, t, ans, x, y, w[500005], hc[500005], xx[25][500005], *th[505], tt[505][505];
	inline void init()
	{
		IO::read(c), IO::read(n), IO::read(m), IO::read(d), IO::read(q);
		for (int i = 1; i <= n + 4; i++)
			th[i] = new int[m + 5]{};
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				tt[i][j] = 1LL << 60; //初始化最大 
		for (int i = 1; i <= m; i++)
			IO::read(w[i]);
		for (int i = 1; i <= n; i++)
		{
			IO::read(k);
			for (int j = 1; j <= k; j++)
				IO::read(a), IO::read(t), th[i][a] = t, xx[++hc[a]][a] = i; //th为换乘时间，xx为换乘线路 
		}
		for (int i = 1; i <= m; i++)
			for (int p = 1; p < hc[i]; p++)
				for (int q = p + 1; q <= hc[i]; q++)
				{
					tt[p][q] = tt[q][p] = min(th[p][i] + th[q][i], tt[p][q]); //存储p线路直接换乘至q线路的最短时间
					for (int i = 1; i <= n; i++)
						tt[p][n] = min(tt[p][q] + tt[q][n], tt[p][n]), tt[q][n] = min(tt[q][p] + tt[p][q], tt[q][n]);
				} 
		for (int i = 1; i <= n; i++)
			tt[i][i] = 0;
	}
	inline void solve()
	{
		init();
		while (q--)
		{
			IO::read(x), IO::read(y), ans = tt[xx[1][x]][xx[1][y]] + th[xx[1][x]][x] + th[xx[1][y]][y];
			for (int i = 1; i <= hc[x]; i++)
				for (int j = 1; j <= hc[y]; j++)
					ans = min(ans, tt[xx[i][x]][xx[i][y]] + th[xx[i][x]][x] + th[xx[i][y]][y]);
			IO::writeln(ans + w[x] + w[y]);
		}
		return;
	}
}

signed main()
{
	 freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
//	freopen("subway2.in", "r", stdin), freopen("subway2.out", "w", stdout);
	Problem::solve();
	return 0;
}
