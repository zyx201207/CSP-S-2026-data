#include <bits/stdc++.h>

using namespace std;

int c, n, m, d, q;

struct station
{
	vector<int> pass;
	map<int, long long> t_platform; // t[i]指站厅到站台 
	long long t_ground; // 站厅到地面 
}stations[500005];

// 地铁线建图
long long trans[505][505];
long long dist[505][505]; // 从i号线任意站到j号线任意站所花时间最小值 

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for ( int i = 1 ; i <= m ; ++ i )
	{
		scanf("%lld", &stations[i].t_ground);
	}
	
	for ( int i = 1 ; i <= n ; ++ i )
	{
		int k;
		scanf("%d", &k);
		for ( int j = 1 ; j <= k ; ++ j )
		{
			int a, t;
			scanf("%d%d", &a, &t);
			stations[a].pass.push_back(i);
			stations[a].t_platform[i] = t;
		}
	}
	
	for ( int i = 1 ; i <= n ; ++ i )
	{
		for ( int j = 1 ; j <= n ; ++ j )
		{
			trans[i][j] = (i == j ? 0 : 1e17);
			dist[i][j] = (i == j ? 0 : 1e17);
		}
	}
	
	for ( int i = 1 ; i <= m ; ++ i )
	{
		if ( stations[i].pass.size() > 1 )
		{
			for ( int j = 0 ; j < stations[i].pass.size() ; ++ j )
			{
				for ( int k = j + 1 ; k < stations[i].pass.size() ; ++ k )
				{
					int line1 = stations[i].pass[j];
					int line2 = stations[i].pass[k];
					trans[line1][line2] = min(trans[line1][line2], stations[i].t_platform[line1] + stations[i].t_platform[line2]);
					trans[line2][line1] = min(trans[line2][line1], stations[i].t_platform[line1] + stations[i].t_platform[line2]);
				}
			}
		}
	}
	
	for ( int i = 1 ; i <= n ; ++ i )
	{
		for ( int j = 1 ; j <= n ; ++ j )
		{
			dist[i][j] = trans[i][j];
		}
	}
	
	
	// floyd
	for ( int k = 1 ; k <= n ; ++ k )
	{
		for ( int i = 1 ; i <= n ; ++ i )
		{
			for ( int j = 1 ; j <= n ; ++ j )
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		} 
	}
	
	while ( q -- )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		long long ans = 0;
		ans += stations[x].t_ground;
		ans += stations[y].t_ground;
		long long ext = 1e17;
		for ( int i = 0 ; i < stations[x].pass.size() ; ++ i )
		{
			for ( int j = 0 ; j < stations[y].pass.size() ; ++ j )
			{
				int line1 = stations[x].pass[i];
				int line2 = stations[y].pass[j];
				ext = min(ext, stations[x].t_platform[line1] + stations[y].t_platform[line2] + dist[line1][line2]);
			}
		}
		ans += ext;
		printf("%lld\n", ans); 
	}
	return 0;
}
