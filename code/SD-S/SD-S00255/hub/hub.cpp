#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const long long Inf = 0x3f3f3f3f3f3f3f3f;
long long c, t, n, k, u, v, ans;
vector <int> tree[1000005];
int dep[1000005], st[1000005][20];
void dfs(int nowi, int lsti)
{
	for (int i = 1;i <= __lg(dep[nowi]);++i)
	{
		st[nowi][i] = st[st[nowi][i - 1]][i - 1];
	}
	for (int i = 0;i < (int)tree[nowi].size();++i)
	{
		int v = tree[nowi][i];
		if (v == lsti)
		{
			continue;
		}
		dep[v] = dep[nowi] + 1;
		st[v][0] = nowi;
		dfs(v, nowi);
	}
}
int lca(int a, int b)
{
	if (dep[a] < dep[b])
	{
		swap(a, b);
	}
	for (int i = __lg(dep[a]);i >= 0;--i)
	{
		if (dep[st[a][i]] < dep[b])
		{
			continue;
		}
		a = st[a][i];
	}
	if (a == b)
	{
		return a;
	}
	for (int i = __lg(dep[a]);i >= 0;--i)
	{
		if (st[a][i] == st[b][i])
		{
			continue;
		}
		a = st[a][i];
		b = st[b][i];
	}
	return st[a][0];
}
long long dis(int x, int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1;i <= n;++i)
		{
			tree[i].clear();
		}
		for (int i = 1;i < n;++i)
		{
			cin >> u >> v;
			tree[u].emplace_back(v);
			tree[v].emplace_back(u);
		}
		dep[1] = 1;
		dfs(1, 0);
		if (k == n)
		{
			cout << "0\n";
			continue;
		}
		if (k == n - 1)
		{
			cout << "1\n";
			continue;
		}
		if (n <= 10)
		{
			ans = Inf;
			for (int i = 0;i < 1 << n;++i)
			{
				int num = 0;
				for (int j = 0;j < n;++j)
				{
					num += (i >> j) & 1;
				}
				if (num == k)
				{
					int num = 0;
					for (int j = 0;j < n;++j)
					{
						if ((i >> j) & 1 && (!j || (i >> (st[j + 1][0] - 1)) & 1 ^ 1))
						{
							++num;
						}
					}
					if (num > 2)
					{
						continue;
					}
					long long nans = 0;
					for (int j = 0;j < n;++j)
					{
						if ((i >> j) & 1 ^ 1)
						{
							long long nnans = Inf;
							for (int k = 0;k < n;++k)
							{
								if ((i >> k) & 1)
								{
									nnans = min(nnans, dis(j + 1, k + 1));
								}
							}
							nans = max(nans, nnans);
						}
					}
					ans = min(ans, nans);
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
