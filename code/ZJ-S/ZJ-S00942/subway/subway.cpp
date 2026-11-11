#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 510, maxm = 5e5 + 10;
ll c, n, m, d, q, w[maxm], dis[maxn][maxn];
vector<pair<ll, ll>> subways[maxn], busways[maxm];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= m; i++)
	{
		cin >> w[i];
	}
	for (ll i = 1; i <= n; i++)
	{
		ll k;
		cin >> k;
		subways[i].resize(k);
		for (ll j = 0; j < k; j++)
		{
			cin >> subways[i][j].first >> subways[i][j].second;
			busways[subways[i][j].first].push_back({i, subways[i][j].second});
		}
		sort(subways[i].begin(), subways[i].end());
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = i + 1; j <= n; j++)
		{
			dis[i][j] = 1e18;
			for (ll ki = 0, kj = 0; ki < subways[i].size() && kj < subways[j].size(); ki++)
			{
				while (kj < subways[j].size() && subways[j][kj].first < subways[i][ki].first)
				{
					kj++;
				}
				if (kj < subways[j].size() && subways[j][kj].first == subways[i][ki].first)
				{
					dis[i][j] = min(dis[i][j], subways[j][kj].second + subways[i][ki].second);
				}
			}
			dis[j][i] = dis[i][j];
		}
	}
	for (ll k = 1; k <= n; k++)
	{
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while (q--)
	{
		ll u, v, ans = 1e18;
		cin >> u >> v;
		for (auto x : busways[u])
		{
			for (auto y : busways[v])
			{
				ans = min(ans, x.second + y.second + dis[x.first][y.first]);
			}
		}
		cout << ans + w[u] + w[v] << '\n';
	}
	return 0;
}