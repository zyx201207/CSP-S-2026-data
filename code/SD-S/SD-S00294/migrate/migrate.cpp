#include <iostream>
#include <vector>

using std::cin;
using std::cout;
const int N = 5e3 + 10;
typedef long long ll;

bool cant[N];
int f[N];
int g[N];
ll x[N];
int lst[N];
int cnt[N];
std::vector<int> nw;
std::vector<int> vec[N];

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
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	rd(c), rd(t);
	while (t--)
	{
		int n;
		ll d;
		rd(n), rd(d);
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			rd(x[i]);
		for (int r = 1, l = 1; r <= n; ++r)
		{
			while (l <= r && x[l] + d < x[r])
				l++;
			lst[r] = l;
		}
		for (int i = 1; i <= n; ++i)
		{
			vec[0].clear();
			for (int j = 1; j <= n; ++j)
				f[j] = 0, cant[j] = false, vec[j].clear();
			for (int k = i + 1; k <= n; ++k)
			{
				if (lst[k] == k)
				{
					cant[k] = true;
					continue;
				}
				f[k] = f[lst[k]] + 1;
				g[k] = 0;
			}
			g[i] = 1;
			vec[0].push_back(i);
			for (int k = i + 1; k <= n; ++k)
			{
				if (cant[k])
					continue;
				for (auto it : vec[f[lst[k]]])
				{
					if (it >= lst[k])
						g[k] += g[it];
				}
				if (g[k] >= 3)
					g[k] = 3;
				else
				{
					if (g[k] == 2)
						ans++;
					vec[f[k]].push_back(k);
					if (vec[f[k]].size() >= 4)
					{
						for (int i = 0; i < (int)vec[f[k]].size() - 1; ++i)
							vec[f[k]][i] = vec[f[k]][i + 1];
						vec[f[k]].pop_back();
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
