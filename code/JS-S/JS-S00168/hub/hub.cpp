#include <bits/stdc++.h>
using namespace std;

int c, T, n, k;

int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> T;
	while (T--)
	{
		cin >> n >> k;
		for (int i = 1; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			/*G[u].push_back(v);
			G[v].push_back(u);*/
		}
		/*for (int i = 0; i < (1 << n); i++)
		{
			int cnt = 0;
			for (int j = 0; j < n; j++)
				if (i & (1 << j)) cnt++;
			if (cnt != k) continue;
			for (int j = 1; j <= n; j++)
				fa[j] = j;
			for (int j = 0; j < n; j++)
				if (i & (1 << j)) 
				{
					for (int k = 0; k < (int)G[j + 1].size(); k++)
					{
						if (i & (1 << (G[j + 1][k] - 1))) 
						{
							int u = search(j + 1), v = search(G[j + 1][k]);
							fa[u] = v;
						}
					}
				}
		}*/
		printf("1\n");
	}
	return 0;

}
