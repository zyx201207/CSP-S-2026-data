#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
ll c, t, n, k, mask, vis, fa[20][maxn], dep[maxn];
vector<ll> edge[maxn];
void dfsmask(ll u)
{
	vis |= 1ll << u;
	for (ll v : edge[u])
	{
		if (((mask >> v) & 1) && !((vis >> v) & 1))
		{
			dfsmask(v);
		}
	}
}
void dfs(ll u)
{
	dep[u] = dep[fa[0][u]] + 1;
	for (ll v : edge[u])
	{
		if (v == fa[0][u])
		{
			continue;
		}
		fa[0][v] = u;
		dfs(v);
	}
}
inline ll dis(ll u, ll v)
{
	ll ret = 0;
	if (dep[u] < dep[v])
	{
		swap(u, v);
	}
	for (ll i = 19; i >= 0; i--)
	{
		if (fa[i][u] && dep[fa[i][u]] > dep[v])
		{
			u = fa[i][u];
			ret += 1ll << i;
		}
	}
	if (dep[u] > dep[v])
	{
		u = fa[0][u];
		ret++;
	}
	for (ll i = 19; i >= 0; i--)
	{
		if (fa[i][u] && fa[i][v] && fa[i][u] != fa[i][v])
		{
			u = fa[i][u];
			v = fa[i][v];
			ret += 2ll << i;
		}
	}
	if (u != v)
	{
		u = fa[0][u];
		v = fa[0][v];
		ret += 2;
	}
	return ret;
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> k;
		for (ll i = 0; i < n; i++)
		{
			edge[i].clear();
		}
		for (ll i = 1; i < n; i++)
		{
			ll u, v;
			cin >> u >> v;
			u--;
			v--;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		ll ans = 1e18;
		for (mask = 3; mask < (1 << n); mask++)
		{
			vis = 0;
			ll cnt = 0, popcnt = 0;
			for (ll i = 0; i < n; i++)
			{
				if (!((mask >> i) & 1))
				{
					continue;
				}
				if (++popcnt > k)
				{
					break;
				}
			}
			if (popcnt != k)
			{
				continue;
			}
			for (ll i = 0; i < n; i++)
			{
				if (((mask >> i) & 1) && !((vis >> i) & 1))
				{
					dfsmask(i);
					if (++cnt > 2)
					{
						break;
					}
				}
			}
			if (cnt > 2)
			{
				continue;
			}
			dfs(1);
			for (ll i = 1; i < 20; i++)
			{
				for (ll j = 0; j < n; j++)
				{
					fa[i][j] = fa[i - 1][fa[i - 1][j]];
				}
			}
			ll cur = 0;
			for (ll i = 0; i < n; i++)
			{
				ll curr = 1e18;
				for (ll j = 0; j < n; j++)
				{
					if ((mask >> j) & 1)
					{
						curr = min(curr, dis(i, j));
					}
				}
				cur = max(cur, curr);
			}
			ans = min(ans, cur);
		}
		cout << ans << '\n';
	}
	return 0;
}