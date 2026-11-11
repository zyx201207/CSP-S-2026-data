#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010, M = 5e5 + 10;
int f[N][N], w[N];
int c, n, m, d, q;

signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
		for(int i = 1; i <= m; i++) for(int j = 1; j <= m; j++) f[i][j] = 1e16;
		for(int i = 1; i <= m; i++) f[i][i] = 0;
		for(int i = 1; i <= m; i++) cin >> w[i];
		vector <pair<int, int> > g;
		for(int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;
			//cout << 1;
			for(int j = 1; j <= k; j++)
			{
				int x, y;
				cin >> x >> y;
				g.push_back({x, y});
			}
			//cout << 1;
			for(int l = 0; l < g.size(); l++)
			{
				for(int r = l + 1; r < g.size(); r++)
				{
					int x = g[l].first, y = g[r].first;
					int z = g[l].second + g[r].second;
					//cout << x << " " << y << " " << z << "\n";
					f[x][y] = min(f[x][y], z);
					f[y][x] = min(f[y][x], z);
				}
			}
			g.clear();
		}
		//cout << "\n";
		for(int k = 1; k <= m; k++)
		{
			for(int x = 1; x <= m; x++)
			{
				for(int y = 1; y <= m; y++)
				{
					f[x][y] = min(f[x][y], f[x][k] + f[k][y]);
					//cout << f[x][y] << "\n";
				}
			}
			//cout << "wtf";
		}
		//cout << "wtf";
		while(q--)
		{
			int x, y;
			cin >> x >> y;
			//cout << f[x][y] << " ";
			int ans = f[x][y] + w[x] + w[y];
			//cout << "wtf";
			cout << ans << "\n";
		}
	
}