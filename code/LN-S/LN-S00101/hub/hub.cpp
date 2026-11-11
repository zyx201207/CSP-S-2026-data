#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long LL;

int c, t;

int n, k;
vector<int> g[1000006];

int s[1000006];
int prnt(int u) { return (u == s[u]) ? u : (s[u] = prnt(s[u])); }

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v), g[v].push_back(u);
		}
		for (int x = 0; x < (1 << n); x++)
		if (__builtin_popcount(x) == k)
		{
			for (int i = 1; i <= n; i++) s[i] = i;
			int c = n;
			for (int i = 1; i <= n; i++)
				if ((x >> i) | 1)	
					for (auto v : g[i])
						if ((x >> v) | 1)
							if (prnt(v) != prnt(i)) s[prnt(v)] = prnt(i), c--;
			if (c <= 2)
			{
				
			}
		}
		cout << 0 << "\n";
	}
	return 0;
}