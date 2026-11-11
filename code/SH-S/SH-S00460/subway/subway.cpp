#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int c , n , m , d , q , u , v , l , r , k , w1 , w2;
int zd[N];
vector<int> g[N];
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1 ; i <= m ; i ++)
	{
		cin >> zd[i];
	}
	for (int i = 1 ; i <= n ; i ++)
	{
		cin >> k;
		cin >> u >> w1;
		if (k == 2)
		{
			cin >> v >> w2;
			g[u].push_back(v);
			g[v].push_back(u);
			if (g[u][v] > 0)
			{
				g[u][v] = g[v][u] = min(w1 + w2 , g[u][v]);
			}
			else
			{
				g[u][v] = g[v][u] = w1 + w2;
			}
		}
	}
	for (int i = 1 ; i <= m ; i ++)
	{
		for (int j = 1 ; j <= m ; j ++)
		{
			if (i == j)
			{
				break;
			}
			for (int k = 1 ; k <= m ; k ++)
			{
				if (i == k || j == k)
				{
					break;
				}
				g[i][j] = min(g[i][j] , g[i][k] + g[k][j]);
			}
		}
	}
	while (q --)
	{
		cin >> l >> r;
		cout << g[l][r] + zd[l] + zd[r] << '\n';
	}
	return 0;
}
