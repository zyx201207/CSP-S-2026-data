//15:37
/*
将铁路视为点
每个站视为边 连d_i*(d_i-1)条边到铁路上
得到一张点数500，边数1e7的图；跑floyd -> N^3
然后查询时 枚举两个站台对应的铁路点 D^2 取min
最终max(N^3, Q*D^2) 
*/
//15:42
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2+10, M = 5e5+10;
int w[M], f[N][N];
struct Node {
	int v, w;
};
vector<Node> g[M];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof f);
	int C, n, m, D, q;
	cin >> C >> n >> m >> D >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int u, w;
			cin >> u >> w;
			g[u].push_back({i, w});
		}
	}
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int i = 1; i <= m; i++)
	{
		for(int x = 0; x < g[i].size(); x++)
		for(int y = 0; y < g[i].size(); y++)
		{
			if(x == y) continue;
			Node a = g[i][x], b = g[i][y];
			f[a.v][b.v] = min(f[a.v][b.v], a.w + b.w);
			f[b.v][a.v] = min(f[b.v][a.v], a.w + b.w);
		}
	}
	for(int j = 1; j <= n; j++)
	for(int i = 1; i <= n; i++)
	for(int k = 1; k <= n; k++)
		f[i][k] = min(f[i][k], f[i][j] + f[j][k]);
	while(q--)
	{
		int x, y;
		cin >> x >> y;
		int ans = LLONG_MAX;
		for(int i = 0; i < g[x].size(); i++)
		for(int j = 0; j < g[y].size(); j++)
		{
			ans = min(ans, f[g[x][i].v][g[y][j].v] + g[x][i].w + g[y][j].w);
		}
		cout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}
//16:06码完 
// 16:11 耶 样例过了 
