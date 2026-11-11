#include <cstdio>
#include <algorithm>
namespace FastIn
{
	const int S = 4e6 + 7;
	char *p1, *p2, buf[S];
	#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, S, stdin), p1 == p2) ? EOF : *p1++)
	template <typename _T>
	inline void read(_T &x)
	{
		x = 0;
		char c = gc();
		bool isneg = false;
		for (; c < '0' || c > '9'; c = gc())
			isneg |= c == '-';
		for (; c >= '0' && c <= '9'; c = gc())
			x = (x << 3) + (x << 1) + (c & 15);
		isneg && (x = -x);
	}
	#undef gc
}
using FastIn::read;
const int MAXN = 1e6 + 7;
struct Edge { int v, nxt; } e[MAXN << 1];
int sid, T, n, m, idx = 1, h[MAXN];
inline void add(const int u, const int v) { e[++idx] = {v, h[u]}, h[u] = idx; }
namespace task2
{
	int ans, fa[11], dep[11];
	inline int getfa(const int u) { return fa[u] == u ? u : (fa[u] = getfa(fa[u])); }
	void DFS(const int u, const int ff, const int de)
	{
		dep[u] = std::min(dep[u], de);
		for (int i = h[u], v = e[i].v; i; v = e[i = e[i].nxt].v)
			v != ff && (DFS(v, u, de + 1), true);
	}
	inline void solve()
	{
		ans = 114514;
		for (int s = 0; s < (1 << n); ++s)
		{
			if (__builtin_popcount(s) != m)
				continue;
			for (int i = 1; i <= n; ++i)
				fa[i] = i, dep[i] = 114514;
			for (int u = 1; u <= n; ++u)
				if ((s >> (u - 1)) & 1)
					for (int i = h[u], v = e[i].v; i; v = e[i = e[i].nxt].v)
						if ((s >> (v - 1)) & 1)
							fa[getfa(u)] = getfa(v);
			int fa1 = 0, fa2 = 0;
			for (int i = 1, u; i <= n; ++i)
				if ((s >> (i - 1)) & 1)
				{
					u = getfa(i);
					if (u == fa1 || u == fa2)
						continue;
					if (!fa1)
						fa1 = u;
					else if (!fa2)
						fa2 = u;
					else
					{
						fa1 = -1;
						break;
					}
				}
			if (fa1 == -1)
				continue;
			for (int i = 1; i <= n; ++i)
				if ((s >> (i - 1)) & 1)
					DFS(i, 0, 0);
			int maxrad = 0;
			for (int i = 1; i <= n; ++i)
				maxrad = std::max(maxrad, dep[i]);
			ans = std::min(ans, maxrad);
		}
		printf("%d\n", ans);
	}
}
namespace task4
{
	int ans, dep[1007];
	void DFS(const int u, const int ff, const int de)
	{
		dep[u] = std::min(dep[u], de);
		for (int i = h[u], v = e[i].v; i; v = e[i = e[i].nxt].v)
			v != ff && (DFS(v, u, de + 1), true);
	}
	inline void solve()
	{
		ans = 114514;
		for (int i = 1; i <= n; ++i)
			for (int j = i + 1; j <= n; ++j)
			{
				for (int k = 1; k <= n; ++k)
					dep[k] = 114514;
				DFS(i, 0, 0), DFS(j, 0, 0);
				int maxrad = 0;
				for (int k = 1; k <= n; ++k)
					maxrad = std::max(maxrad, dep[k]);
				ans = std::min(ans, maxrad);
			}
		printf("%d\n", ans);
	}
}
inline void solve()
{
	read(n), read(m), idx = 1;
	for (int i = 1; i <= n; ++i)
		h[i] = 0;
	for (int i = 1, u, v; i < n; ++i)
		read(u), read(v), add(u, v), add(v, u);
	if (n <= 1000 && m == 2)
		return task4::solve();
	if (sid <= 3)
		return task2::solve();
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	for (read(sid), read(T); T; --T)
		solve();
	fclose(stdin), fclose(stdout);
	return 0;
}