#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 5e5 + 10;

typedef long long LL;

int c, n, m, mmax1, q;
int w[M];
LL d[N][N];
vector<int> a[M];
vector<int> t[M];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> mmax1 >> q;
	
	for (int i = 1; i <= m; i ++ )
		cin >> w[i];
	
	for (int i = 1, len; i <= n; i ++ )
	{
		cin >> len;
		
		for (int j = 1, x, y; j <= len; j ++ )
		{
			cin >> x >> y;
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	
	memset(d, 0x3f, sizeof d);
	
	for (int i = 1; i <= m; i ++ )
	{
		for (int j = 0; j < (int)a[i].size(); j ++ )
		{
			int num = a[i][j];
			int cost = t[i][j];
			
			for (int k = 0; k < (int)a[i].size(); k ++ )
			{
				if (j == k)
					continue;
				
				int num1 = a[i][k];
				int cost1 = t[i][k];
				
				d[num][num1] = min(d[num][num1], (LL)(cost1 + cost));
			}
		}	
	}
	
	for (int k = 1; k <= n; k ++ )
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ )
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	
	for (int i = 1; i <= q; i ++ )
	{
		int x, y;
		cin >> x >> y;
		
		LL ans = (LL)1e18;
		
		for (int j = 0; j < (int)a[x].size(); j ++ )
			for (int k = 0; k < (int)a[y].size(); k ++ )
			{
				if (a[x][j] == a[y][k])
					ans = min(ans, (LL)(t[x][j] + t[y][k]));
				else
					ans = min(ans, (LL)(d[a[x][j]][a[y][k]] + t[x][j] + t[y][k]));
			}
				
		
		cout << ans + w[x] + w[y] << '\n';
	}
	
	return 0;
}