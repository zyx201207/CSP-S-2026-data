#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll c, n, m, d, q, w[500005], dist[505][505];
vector<pair<ll, ll> > G[505];
vector<pair<ll, ll> > have[500005];

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	ll k, to, x;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> to >> x;
			have[to].push_back({i, x});
		}
	}	
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		for (auto j : have[i])
		{
			for (auto l : have[i])
			{
				if (j.first == l.first) continue;
				dist[j.first][l.first] = min(dist[j.first][l.first], j.second + l.second);
			}
		}
	}
	for (int l = 1; l <= n; l++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == l) continue;
			for (int j = 1; j <= n; j++)
			{
				if (i == j || j == l) continue;
				dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
			}
		}
	}
	ll a, b;
	for (int i = 1; i <= q; i++)
	{
		cin >> a >> b;
		ll ans = 4e18;
		for (auto j : have[a])
		{
			for (auto l : have[b])
			{
				ans = min(ans, dist[j.first][l.first] + j.second + l.second);
			}
		}
		ans = ans + w[a] + w[b];
		cout << ans << "\n";
	}
	return 0;
}
