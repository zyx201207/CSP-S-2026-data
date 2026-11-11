#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

typedef pair<int, int> P;
const int N = 505, M = 5e5 + 5;
int f[N][N];
vector <P> vec[M];
int c, n, m, d, T, w[M];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int i, j, k;
	cin >> c >> n >> m >> d >> T;
	
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i != j)
				f[i][j] = 4e18;
	
	for(i = 1; i <= m; i++)
		cin >> w[i];
	
	for(i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		
		while(k--)
		{
			int u, t;
			cin >> u >> t;
			vec[u].pb(mp(i, t));
		}
	}
	
	for(i = 1; i <= m; i++)
	{
		for(auto u : vec[i])
		{
			for(auto v : vec[i])
			{
				f[u.fi][v.fi] = min(f[u.fi][v.fi], u.se + v.se);
				f[v.fi][u.fi] = min(f[v.fi][u.fi], u.se + v.se);
			}
		}
	}

	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

	while(T--)
	{
		int u, v, res = 4e18;
		cin >> u >> v;
		
		for(auto p : vec[u])
			for(auto q : vec[v])
				res = min(res, f[p.fi][q.fi] + p.se + q.se);
		
		cout << res + w[u] + w[v] << "\n";
	}

	return 0;
}

//100pts 33min