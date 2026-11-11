/* construct : OCT 31'26 */
#include	<iostream>
#include	<cstring>
#include	<vector>
#define		int		long long
using namespace std;
using pii = pair<int,int>;
constexpr int maxn = 504;
constexpr int maxm = 5e5+4;
constexpr int inf = 0x3f3f3f3f3f3f3f3f;

bool BEGIN;
int w[maxm];
int c, n, m, d, q;
vector<int> a[maxn];
vector<int> t[maxn];
int dist[maxn][maxn];
vector<pii> chg[maxm];
bool END;

signed main (void)
{
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	// cerr << "SIZE : " << (&END - &BEGIN) * 1.0 / 1024 / 1024 << " MB" << endl;
	scanf ("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf ("%lld", w + i);
	for (int k, x, y, i = 1; i <= n; i++)
	{
		scanf ("%lld", &k);
		while (k--)
		{
			scanf ("%lld%lld",&x, &y);
			a[i].emplace_back(x);
			t[i].emplace_back(y);
			chg[x].emplace_back(i, y);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		memset (dist[i], 0x3f, (n + 1) * sizeof (int));
		dist[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < chg[i].size(); j++)
		{
			for (int k = j + 1; k < chg[i].size(); k++)
			{
				dist[chg[i][j].first][chg[i][k].first] = min (dist[chg[i][j].first][chg[i][k].first], chg[i][j].second + chg[i][k].second);
				dist[chg[i][k].first][chg[i][j].first] = min (dist[chg[i][j].first][chg[i][k].first], chg[i][j].second + chg[i][k].second);
			}
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
		}
	}
	while (q--)
	{
		int x, y;
		scanf ("%lld%lld", &x, &y);
		int ans = inf;
		for (auto [u, wu] : chg[x])
		{
			for (auto [v, wv] : chg[y])
			{
				ans = min (ans, w[x] + wu + dist[u][v] + wv + w[y]);
				// cout << u << ' ' << v << ' ' << w[x] + wu + dist[u][v] + wv + w[y] << endl;
			}
		}
		printf ("%lld\n", ans);
	}
	return 0;
}
