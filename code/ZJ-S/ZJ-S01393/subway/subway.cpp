#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define pb push_back
#define sz size()
using namespace std;
const int N = 5e5 + 100, M = 600;
int C, n, m, d, q;
int w[N], F[M][M];
struct node { int x, y; };
vector<node> g[N];
#define min(x, y) (x > y ? y : x)
#define max(x, y) (x > y ? x : y)
#define f(i, j) F[min(i, j)][max(i, j)]
signed main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> C >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1, k; i <= n; i ++)
	{
		cin >> k;
		for(int j = 1, x, y; j <= k; j ++)
			cin >> x >> y, g[x].pb({i, y});
	}
	memset(F, 0x3f, sizeof F);
	for(int i = 1; i <= m; i ++)
	{
		for(int j = 0; j < g[i].sz; j ++)
			for(int k = j + 1; k < g[i].sz; k ++)
			{
				node a = g[i][j], b = g[i][k];
				f(a.x, b.x) = min(f(a.x, b.x), a.y + b.y);
			}
	}
	for(int k = 1; k <= n; k ++)
	{
		for(int i = 1; i <= n; i ++)
			for(int j = i + 1; j <= n; j ++)
				f(i, j) = min(f(i, j), f(i, k) + f(k, j));
		f(k, k) = 0;
	}
		
	while(q --)
	{
		int u, v, ans = 1e18;
		cin >> u >> v;
		for(int j = 0; j < g[u].sz; j ++)
			for(int k = 0; k < g[v].sz; k ++)
			{
				node a = g[u][j], b = g[v][k];
				ans = min(ans, a.y + b.y + f(a.x, b.x));
			}
		cout << ans + w[u] + w[v] << "\n";
	}
	return 0;
}
