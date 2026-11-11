#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, n, m, d, q, w[500005], k, a, t, x, y;
vector <pair <ll, ll> > e[500005];
ll dis[505][505];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1; i <= n; i++) for (ll j = i + 1; j <= n; j++) dis[i][j] = dis[j][i] = 1e18;
	for (ll i = 1; i <= m; i++) cin >> w[i];
	ll idex = m;
	for (ll i = 1; i <= n; i++)
	{
		cin >> k;
		for (ll j = 1; j <= k; j++)
		{
			cin >> a >> t;
			e[a].push_back({i, t});
		}
	}
	for (ll i = 1; i <= m; i++)
	{
		for (ll j = 0; j < e[i].size(); j++)
		{
			for (ll k = j + 1; k < e[i].size(); k++)
			{
				ll p1 = e[i][j].first, p2 = e[i][k].first, t = e[i][j].second + e[i][k].second;
				dis[p1][p2] = dis[p2][p1] = min(dis[p1][p2], t);
			}
		}
	}
	for (ll k = 1; k <= n; k++) for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while (q--)
	{
		cin >> x >> y;
		ll ans = 1e18;
		for (pair <ll, ll> i : e[x])
		{
			for (pair <ll, ll> j : e[y])
			{
				ans = min(ans, i.second + j.second + dis[i.first][j.first]);
			}
		}
		cout << ans + w[x] + w[y] << "\n";
	}
} 
