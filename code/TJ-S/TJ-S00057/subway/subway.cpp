#include <bits/stdc++.h>
using namespace std;

int mapp[510][500010];
int entry[500010];
int c, n, m, d, q, k, x, y;
long long mint;

void dfs(int u, long long time)
{
	if (mapp[u][y])
	{
		time += mapp[u][y];
		if (time < mint) mint = time;
		return ;
	}
	for (int i = 1; i <= m; i++)
	{
		if (mapp[u][i])
		{
			for (int j = 1; j <= n; j++)
			{
				if (j == u) continue;
				if (mapp[j][i])
				{
					int save1 = mapp[u][i], save2 = mapp[j][i];
					mapp[u][i] = 0;
					mapp[j][i] = 0;
					dfs(j, time+save1+save2);
					mapp[u][i] = save1;
					mapp[j][i] = save2;
				}
			}
		}
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> entry[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int t;
			cin >> t;
			cin >> mapp[i][t];
		}
	}
	
	while(q--)
	{
		cin >> x >> y;
		mint = 10000000000;
		for (int o = 1; o <= n; o++)
		{
			if (mapp[o][x])
			{
				dfs(o, mapp[o][x]);
			}
		}
		
		cout << mint+entry[x]+entry[y] << "\n";
	}
	
	return 0;
}
