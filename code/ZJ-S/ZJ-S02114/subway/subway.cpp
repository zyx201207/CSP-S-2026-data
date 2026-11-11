#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e4 + 10;
int n, m, d, q;
int w[N], a[N][N], k[N], t[N][N];

int dfs(int u, int v)
{
	for(int i = 1; i <= n; i ++)
	{
		map<int, int> mp;
		for(int j = 1; j <= k[i]; j ++)
			mp[a[i][j]] ++;
		if(mp[u] && mp[v])
			return w[u] + t[i][u] + w[v] + t[i][v];
	}
	
	int tip;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= k[i]; j ++)
			if(a[i][j] == u) 
			{
				tip = i;
				break;
			}
	//cout << tip << endl;
	for(int j = 1; j <= k[tip]; j ++)
	{
		if(a[tip][j] == u) continue;
		return  w[u] + t[tip][a[tip][j]] + dfs(a[tip][j], v);
	}
			
}
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) scanf("%lld", &w[i]);
	
	for(int i = 1; i <= n; i ++)
	{
		scanf("%lld", &k[i]);
		for(int j = 1; j <= k[i]; j ++)
			scanf("%lld %lld", &a[i][j], &t[i][j]);
	}
	while(q --)
	{
		int u, v;
		cin >> u >> v;
		printf("%lld\n", dfs(u, v));
	}
	return 0;
}
