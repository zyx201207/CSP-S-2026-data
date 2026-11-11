#include <cstdio>
#include <vector>
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
const int MAXM = 5e5 + 7;
const long long inf = 1e18;
int sid, n, m, D, Q, w[MAXM];
long long f[507][507];
std::vector<std::pair<int, int>> g[MAXM];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	read(sid), read(n), read(m), read(D), read(Q);
	for (int i = 1; i <= m; ++i)
		read(w[i]), g[i].reserve(D);
	for (int i = 1, k; i <= n; ++i)
	{
		read(k);
		for (int j = 1, a, t; j <= k; ++j)
			read(a), read(t), g[a].emplace_back(i, t);
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			f[i][j] = i == j ? 0 : inf;
	for (int i = 1; i <= m; ++i)
		for (int j = 0, u, t1; j < (int)(g[i].size()); ++j)
		{
			u = g[i][j].first, t1 = g[i][j].second;
			for (int k = j + 1, v, t2; k < (int)(g[i].size()); ++k)
				v = g[i][k].first, t2 = g[i][k].second,
				f[u][v] = std::min(f[u][v], (long long)(t1) + t2),
				f[v][u] = f[u][v];
		}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
	for (int i = 1, x, y; i <= Q; ++i)
	{
		read(x), read(y);
		long long ans = inf;
		for (const auto &[u, t1] : g[x])
			for (const auto &[v, t2] : g[y])
				ans = std::min(ans, f[u][v] + t1 + t2);
		printf("%lld\n", ans + w[x] + w[y]);
	}
	fclose(stdin), fclose(stdout);
	return 0;
}