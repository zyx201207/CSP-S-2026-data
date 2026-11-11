#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll c, t, n, d, x[2000005], nxt[25][2000005], dis[5005][5005];
const ll mod = 998244353;
ll qp(ll ta, ll tb)
{
	ll tot = 1;
	while (tb)
	{
		if (tb & 1) tot *= ta, tot %= mod;
		ta *= ta, ta %= mod;
		tb >>= 1;
	}
	return tot;
}
unordered_set <ll> st[305][305];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		ll ans = 0;
		cin >> n >> d;
		for (ll i = 1; i <= n; i++) for (ll j = 1; j <= n; j++) dis[i][j] = 0, st[i][j].clear();
		for (ll i = 1; i <= n; i++) cin >> x[i];
		for (ll i = 1; i <= n; i++)
		{
			ll pos = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
			nxt[0][i] = pos;
		}
		for (ll i = 1; i <= 20; i++) for (ll j = 1; j <= n; j++) nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = i + 1; j <= n; j++)
			{
				ll now = i;
				for (ll k = 20; k >= 0; k--)
				{
					if (nxt[k][now] < j)
					{
						now = nxt[k][now];
						dis[i][j] += (1 << k);
					}
				}
				now = nxt[0][now];
				dis[i][j]++;
				if (now < j) dis[i][j] = 1e18;
			}
		}
		for (ll len = 1; len < n; len++)
		{
			for (ll i = 1, j = len + 1; j <= n; i++, j++)
			{
				if (dis[i][j] == 1e18) continue;
				if (dis[i][j] == 1)
				{
					st[i][j].insert((i * (n + 1) % mod + j) % mod);
					continue;
				}
				for (ll k = i + 1; k < j; k++)
				{
					if (dis[i][j] == dis[i][k] + dis[k][j])
					{
						ll df = qp(n + 1, dis[k][j]);
						for (ll p1 : st[i][k]) for (ll p2 : st[k][j])
						{
							st[i][j].insert((p1 * df % mod + p2) % mod);
						}
					}
				}
				if (st[i][j].size() == 2) ans++;
			}
		}
		cout << ans << "\n";
	}

} 
