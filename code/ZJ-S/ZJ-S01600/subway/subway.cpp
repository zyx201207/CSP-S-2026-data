#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10, M = 510;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q, w[N], k[M];
ll f[M][M];
struct Edge{int v, w;};
vector<Edge> e[N];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++)
		{
			int to, w;
			cin >> to >> w;
			e[to].push_back({i, w});
		}
	}
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n; i ++) f[i][i] = 0;
	for(int i = 1; i <= m; i ++)
	{
		for(Edge t1 : e[i])
		{
			int v1 = t1.v, w1 = t1.w;
			for(Edge t2 : e[i])
			{
				int v2 = t2.v, w2 = t2.w;
				f[v1][v2] = min(f[v1][v2], 1LL * w1 + w2);
			}
		}
	}
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	while(q --)
	{
		int u, v;
		cin >> u >> v;
		ll tmp = inf;
		for(Edge t1 : e[u])
		{
			int v1 = t1.v, w1 = t1.w;
			for(Edge t2 : e[v])
			{
				int v2 = t2.v, w2 = t2.w;
				tmp = min(tmp, f[v1][v2] + w1 + w2);
			}
		}
		ll ans = w[u] + w[v] + tmp;
		cout << ans << '\n';
	}
	return 0;
}