#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 505;

int w[N][N];
vector<pair<int, int>> val[500005];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
//	cout << c << " " << n << " " << m << " " << d << " " << q << "\n";
	// c 测试点编号，n 地铁条数，m 站点数，d 每个地铁站最多被几条地铁经过，q 询问数
	vector<int> _w(m + 1, 0), k(n + 1, 0);
	for (int i = 1; i <= m; i++) cin >> _w[i];
	memset(w, 0x3f, sizeof w);
	for (int i = 1; i <= n; i++) w[i][i] = 0;
//	cerr << "Yes";
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++)
		{
			int a, t;
			cin >> a >> t;
			val[a].push_back({i, t});
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (auto p : val[i])
		{
			for (auto q : val[i])
			{
				int u = p.first, w_u = p.second;
				int v = q.first, w_v = q.second;
				w[u][v] = min(w[u][v], w_u + w_v);
			}
		}
	}

//	cout << "114\n";
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cout << w[i][j] << " ";
//		}
//		cout << "\n";
//	}
	for (int k = 1; k <= n; k++)
	{
		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= n; y++)
			{
				w[x][y] = min(w[x][y], w[x][k] + w[k][y]);
			}
		}
	}
//	cout << "114\n";
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= n; j++)
//		{
//			cout << w[i][j] << " ";
//		}
//		cout << "\n";
//	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		int res = 1e18;
		for (auto p : val[x])
		{
			for (auto q : val[y])
			{
				int u = p.first, w_u = p.second;
				int v = q.first, w_v = q.second;
				res = min(res, w_u + w[u][v] + w_v);
			}
		}
		cout << res + _w[x] + _w[y] << "\n";
	}
	return 0;
}
