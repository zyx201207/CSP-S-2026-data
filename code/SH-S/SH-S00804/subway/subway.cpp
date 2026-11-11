#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
const ll N = 500010, M = 510, INF = 0x3f3f3f3f3f3f3f3f;
ll c, n, m, d, q, w[N], dis[M][M]; vector<pll> v[N];
void solve()
{
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (ll i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for (ll i = 1; i <= n; i++)
	{
		ll k; scanf("%lld", &k);
		for (ll j = 1, x, y; j <= k; j++)
			scanf("%lld%lld", &x, &y), v[x].push_back(make_pair(i, y));
	}
	memset(dis, 0x3f, sizeof(dis));
	for (ll i = 1; i <= n; i++) dis[i][i] = 0;
	for (ll i = 1; i <= m; i++)
	{
		for (ll j = 0; j < (ll)v[i].size(); j++)
			for (ll k = j+1; k < (ll)v[i].size(); k++)
			{
				ll x = v[i][j].first, y = v[i][k].first, z = v[i][j].second+v[i][k].second;
				dis[x][y] = min(dis[x][y], z), dis[y][x] = min(dis[y][x], z);
			}
	}
	for (ll k = 1; k <= n; k++)
		for (ll i = 1; i <= n; i++)
			for (ll j = 1; j <= n; j++) dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
	while (q--)
	{
		ll s, t, ret = INF; scanf("%lld%lld", &s, &t);
		for (ll i = 0; i < (ll)v[s].size(); i++)
			for (ll j = 0; j < (ll)v[t].size(); j++)
			{
				ll x = v[s][i].first, y = v[t][j].first, z = v[s][i].second+v[t][j].second;
				ret = min(ret, z+dis[x][y]);
			}
		printf("%lld\n", ret+w[s]+w[t]);
	}
}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll T = 1;
	while (T--) solve();
	return 0;
}
