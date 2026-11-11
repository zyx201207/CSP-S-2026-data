# include<bits/stdc++.h>

using namespace std;

const int N = 5e2 + 10, M = 5e5 + 10;
vector<int> t[N], a[N];
vector< pair<int , long long> > s[M];
long long f[N][N], id, n, m, d, q, w[M], len[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> id >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++ ) cin >> w[i];
	for(int i = 1;i <= n;i ++ )
	{
		cin >> len[i];
		t[i].emplace_back(0), a[i].emplace_back(0);
		for(int j = 1, x, y;j <= len[i];j ++ ) 
		{
			cin >> x >> y;
			a[i].emplace_back(x), t[i].emplace_back(y);
			s[x].emplace_back(i, y);
		}
	}
	
	for(int i = 1;i <= n;i ++ ) for(int j = 1;j <= n;j ++ ) f[i][j] = 1e18;
	for(int i = 1;i <= n;i ++ ) f[i][i] = 0;
	for(int i = 1;i <= m;i ++ )
	{
		for(pair<int , long long> t : s[i])
		{
			for(pair<int , long long> k : s[i])
			{
				long long u = t.first , v = k.first, w = t.second + k.second;
				if(u == v) continue;
				f[u][v] = min(f[u][v], w);
				f[v][u] = min(f[v][u], w);
			}
		}
	}
	
	for(int k = 1;k <= n;k ++ )
	{
		for(int i = 1;i <= n;i ++ )
		{
			for(int j = 1;j <= n;j ++ )
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	while(q -- )
	{
		int x, y; cin >> x >> y;
		long long ans = 1e18;
		for(pair<int, long long> t : s[x])
		{
			for(pair<int , long long> k : s[y])
			{
				long long u = t.first, v = k.first, w = t.second + k.second;
				ans = min(ans, f[u][v] + w);
			}
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}