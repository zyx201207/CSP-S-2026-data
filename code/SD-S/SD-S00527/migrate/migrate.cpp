#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5010;

int n, d;
int a[N], mp[N][N], g[N][N];

void solve()
{
	cin >> n >> d;
	
	for (int i = 0; i < n; i ++ )
		cin >> a[i];
		
	int ans = 0;
	for (int s = 0; s < (1 << n); s ++ )
	{
		vector<int> p;
		for (int i = 0; i < n; i ++ )
			if ( ((s >> i) & 1)) p.push_back(i);
		int sz = p.size(), cnt = 1;
		bool ok = true;
		if ( sz < 2 ) continue;
		int o = p[0];
		for (int i = 1; i < sz; i ++ )
		{
			if ( p[i] - p[i - 1] > d )
			{
				ok = false;
				break;
			}
			o += p[i] - p[i - 1];
			if ( o > d ) cnt ++, o = 0;
		}
		if ( ok) 
		{
			int u = p[0], v = p[sz - 1];
			if ( g[u][v] <= cnt ) 
			{
				if ( g[u][v] == cnt ) mp[u][v] ++;
				else g[u][v] = cnt, mp[u][v] = 1;
			}
		}
	}
	
	for (int i = 0; i < n; i ++ )
		for (int j = i + 1; j < n; j ++ )
			if ( mp[i][j] == 2 ) ans ++;
	cout << ans - 1 << "\n";
	
	memset(mp, 0, sizeof mp);
	memset(g, 0, sizeof g);	
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, t;
	cin >> c >> t;
	while (t -- ) solve();
	
	return 0;
}
