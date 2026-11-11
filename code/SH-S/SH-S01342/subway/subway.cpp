#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int w[500005];
struct edge
{
	int v , t;
};
vector<edge> g[500005];
ll f[505][505];
int main()
{
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int C , n , m , d , q; scanf("%d%d%d%d%d" , &C , &n , &m , &d , &q);
	for (int i = 1; i <= m; i++) scanf("%d" , &w[i]);
	for (int i = 1; i <= n; i++)
	{
		int k; scanf("%d" , &k);
		for (int j = 1; j <= k; j++)
		{
			int x , t; scanf("%d%d" , &x , &t);
			g[x].push_back({i , t});
		}
	}
	memset(f , 0x3f , sizeof(f));
	for (int i = 1; i <= n; i++) f[i][i] = 0;
	for (int i = 1; i <= m; i++)
	{
		int l = g[i].size() , x , y;
		for (int j = 0; j < l - 1; j++)
		{
			for (int k = j + 1; k < l; k++)
			{
				x = g[i][j].v , y = g[i][k].v;
				f[x][y] = min(f[x][y] , (ll)(g[i][j].t + g[i][k].t));
			}
		}
	}
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++) f[i][j] = f[j][i] = min(f[i][j] , f[j][i]);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = min(f[i][j] , f[i][k] + f[k][j]);
	while (q --)
	{
		int x , y; scanf("%d%d" , &x , &y);
		ll ans = inf;
		for (edge i : g[x])
			for (edge j : g[y])
				ans = min(ans , f[i.v][j.v] + i.t + j.t);
		printf("%lld\n" , ans + w[x] + w[y]);
	}
	return 0;
}
