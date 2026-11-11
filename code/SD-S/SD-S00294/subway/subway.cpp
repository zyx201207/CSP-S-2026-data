#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const int M = 5e5 + 10;
const int N = 510;
typedef long long ll;
typedef int st;
const ll oo = 1e18;

int w[M];
std::vector<st> way[M];
std::vector<int> t[M];
ll dis[N][N];

template<typename T>
void rd(T &x)
{
	x = 0;
	int f = 1;
	char c = getchar();
	while (!isdigit(c))
	{
		if (c == '-')
			f = -f;
		c = getchar();
	}
	while (isdigit(c))
	{
		x = (x << 1) + (x << 3) - '0' + c;
		c = getchar();
	}
	x *= f;
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	rd(c), rd(n), rd(m), rd(d), rd(q);
	for (int i = 1; i <= m; ++i)
		rd(w[i]);
	for (st i = 1; i <= n; ++i)
	{
		for (st j = 1; j <= n; ++j)
			dis[i][j] = oo;
		dis[i][i] = 0;
	}
	for (st i = 1; i <= n; ++i)
	{
		int k;
		rd(k);
		for (int j = 1; j <= k; ++j)
		{
			int a, T;
			rd(a), rd(T);
			way[a].push_back(i);
			t[a].push_back(T);
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		st siz = way[i].size();
		for (st j = 0; j < siz; ++j)
		{
			for (st k = 0; k < siz; ++k)
				dis[way[i][j]][way[i][k]] = std::min(dis[way[i][j]][way[i][k]], (ll)t[i][j] + t[i][k]);
		}
	}
	for (st i = 1; i <= n; ++i)
	{
		for (st j = i + 1; j <= n; ++j)
			dis[j][i] = dis[i][j];
	}
	for (st k = 1; k <= n; ++k)
	{
		for (st i = 1; i <= n; ++i)
		{
			for (st j = 1; j <= n; ++j)
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
	while (q--)
	{
		int x, y;
		rd(x), rd(y);
		st sizx = way[x].size();
		st sizy = way[y].size();
		ll ans = oo;
		for (st i = 0; i < sizx; ++i)
		{
			for (st j = 0; j < sizy; ++j)
				ans = std::min(ans, dis[way[x][i]][way[y][j]] + w[x] + w[y] + t[x][i] + t[y][j]);
		}
		cout << ans << '\n';
	}
	return 0;
}
