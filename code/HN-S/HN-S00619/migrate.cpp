#include <bits/stdc++.h>
#define PREWORK
#define tests
#define filetestin
#define filetestout
using i64 = long long;
using ui64 = unsigned long long;
const int N = 2e6 + 5;
int T = 1, cid;
int n;
i64 x[N], d;
struct brute_force
{
	std::vector <int> e[N];
	void init ()
		{for (int i = 1; i <= n; ++ i) e[i].clear ();}
	void build ()
	{
		for (int i = 1; i <= n; ++ i)
			for (int j = i + 1; j <= n; ++ j)
				if (x[j] - x[i] <= d)
					e[i].push_back (j);
				else
					break;
	}
	int dep[N];
	i64 f[N];
	void Main ()
	{
		init ();
		build ();
		i64 res = 0;
		for (int i = 1; i <= n; ++ i)
		{
			std::queue <int> q;
			while (q.size ())
				q.pop ();
			q.push (i);
			for (int j = i; j <= n; ++ j)
				dep[j] = -1,
				f[j] = 0;
			dep[i] = 0;
			f[i] = 1;
			while (q.size ())
			{
				int u = q.front ();
				q.pop ();
				for (int v : e[u])
					if (dep[v] == -1)
						dep[v] = dep[u] + 1,
						f[v] = f[u],
						q.push (v);
					else if (dep[v] == dep[u] + 1)
						f[v] += f[u];
			}
			for (int j = i + 1; j <= n; ++ j)
				if (f[j] == 2)
					++ res;
		}
		std::cout << res << '\n';
	}
}p1;
// 20111019 x 20120217
struct yzqlyh
{
	bool check ()
	{
		i64 xx = x[2] - x[1];
		for (int i = 2; i < n; ++ i)
			if (x[i + 1] - x[i] != xx)
				return 0;
		return 1;
	}
	void Main ()
	{
		i64 xx = x[2] - x[1];
		i64 dd = std::min (1ll * n, d / xx);
		if (dd * 2 > n || dd <= 1)
			return std::cout << "0\n", void ();
		std::cout << n + 1 - dd * 2 << '\n';
	}
}p2;
void prework ()
{
	std::cin >> cid;
}
void solve ()
{
	std::cin >> n >> d;
	for (int i = 1; i <= n; ++ i)
		std::cin >> x[i];
	if (p2.check ())
		return p2.Main ();
	return p1.Main ();
}
void clear ()
{
}
signed main ()
{
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
#ifdef filetestin
	freopen ("migrate.in", "r", stdin);
#endif
#ifdef filetestout
	freopen ("migrate.out", "w", stdout);
#endif
#ifdef PREWORK
	prework ();
#endif
#ifdef tests
	std::cin >> T;
#endif
	while (T --)
		solve (),
		clear ();
	return 0;
}
/*
#include <bits/stdc++.h>
#define PREWORK
#define tests
//#define filetestin
#define filetestout
using i64 = long long;
using ui64 = unsigned long long;
const int N = 2e6 + 5;
int T = 1, cid;
int n;
i64 x[N], d;
struct brute_force
{
	std::vector <int> e[N];
	void init ()
		{for (int i = 1; i <= n; ++ i) e[i].clear ();}
	void build ()
	{
		for (int i = 1; i <= n; ++ i)
			for (int j = i + 1; j <= n; ++ j)
				if (x[j] - x[i] <= d)
					e[i].push_back (j);
				else
					break;
	}
	int dep[N];
	i64 f[N];
	void Main ()
	{
		init ();
		build ();
		i64 res = 0;
		for (int i = 1; i <= n; ++ i)
		{
			std::queue <int> q;
			while (q.size ())
				q.pop ();
			q.push (i);
			for (int j = i; j <= n; ++ j)
				dep[j] = -1,
				f[j] = 0;
			dep[i] = 0;
			f[i] = 1;
			while (q.size ())
			{
				int u = q.front ();
				q.pop ();
				for (int v : e[u])
					if (dep[v] == -1)
						dep[v] = dep[u] + 1,
						f[v] = f[u],
						q.push (v);
					else if (dep[v] == dep[u] + 1)
						f[v] += f[u];
			}
			for (int j = i + 1; j <= n; ++ j)
				if (f[j] == 2)
					++ res;
		}
		std::cout << res << '\n';
	}
}p1;
// 20111019 x 20120217
struct yzqlyh
{
	bool check ()
	{
		i64 xx = x[2] - x[1];
		for (int i = 2; i < n; ++ i)
			if (x[i + 1] - x[i] != xx)
				return 0;
		return 1;
	}
	void Main ()
	{
		i64 xx = x[2] - x[1];
		i64 dd = std::min (1ll * n, d / xx);
		if (dd * 2 > n || dd <= 1)
			return std::cout << "0\n", void ();
		std::cout << n + 1 - dd * 2 << '\n';
	}
}p2;
int l[N], r[N];
struct node{int a, b, pos;}ycy[N];
void prework ()
{
	std::cin >> cid;
}
void solve ()
{
	std::cin >> n >> d;
	for (int i = 1; i <= n; ++ i)
		std::cin >> x[i];
	//if (p2.check ())
	//	return p2.Main ();
	//if (n <= 5000)
	//	return p1.Main ();
	int j = 1;
	for (int i = 1; i <= n; ++ i)
	{
		while (x[j] - x[i] > d)
			++ j;
		l[i] = j;
	}
	j = n;
	for (int i = n; i; -- i)
	{
		while (x[j] - x[i] > d)
			-- j;
		r[i] = j;
	}
	int m = 1;
	ycy[1] = {l[3], r[2], 2};
	for (int i = 2; i < n; ++ i)
		if (l[i] != l[i + 1] && r[i] != r[i - 1])
			ycy[++ m] = {l[i + 1], r[i], i};
	i64 res = 0;
	for (int i = 1; i <= m; ++ i)
		res += 1ll * (ycy[i].pos - ycy[i].a) * (ycy[i].b - ycy[i].pos - 1);
	std::cout << res << '\n';
}
void clear ()
{
}
signed main ()
{
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
#ifdef filetestin
	freopen ("migrate.in", "r", stdin);
#endif
#ifdef filetestout
	freopen ("migrate.out", "w", stdout);
#endif
#ifdef PREWORK
	prework ();
#endif
#ifdef tests
	std::cin >> T;
#endif
	while (T --)
		solve (),
		clear ();
	return 0;
}
*/