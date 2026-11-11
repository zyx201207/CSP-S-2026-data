#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define D(x) cout << #x << ": " << x << ' '
#define DE(x) cout << #x << ": " << x << '\n'
#define pii pair<ll, ll>
#define mkp(x, y) make_pair(x, y)
#define pl p << 1
#define pr p << 1 | 1
using namespace std;
constexpr ll MOD = 998244353ll, inf = 1ll << 60;
ll Case, tt;
ll n, m, k, qq;
ll a[2000010];
ll dis[2000010];
ll pos[2000010];
ll cnt[2000010];
ll tong[2000010];

void solve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		pos[i] = -1;
		ll L = 1, R = i - 1;
		while (L <= R)
		{
			ll mid = L + R >> 1;
			if (a[i] - a[mid] <= k)
				pos[i] = mid, R = mid - 1;
			else
				L = mid + 1;
		}
//		D(i), DE(pos[i]);
	}
	ll ans = 0;
	for (int s = 1; s <= n; s++)
	{
		for (int i = 0; i <= n; i++)
			tong[i] = 0, cnt[i] = 0, dis[i] = inf;
		dis[s] = 0;
		cnt[s] = 1;
		tong[0] = 1;
		ll r = s;
		for (int e = s + 1; e <= n; e++)
		{
			if (pos[e] == -1)
				continue;
			while (r < pos[e])
			{
				if (dis[r] != inf)
					tong[dis[r]] -= cnt[r];
				r++;
			}
			while (r < e && dis[r] == inf)
				r++;
			if (r == e)
				continue;
			ll mn = dis[r];
			ans += tong[mn] == 2;
			dis[e] = mn + 1;
			cnt[e] = tong[mn];
			tong[dis[e]] += tong[mn];
		}
	}
	cout << ans << '\n';
}

int main()
{
	ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	for (cin >> Case >> tt; tt--; )
		solve();
	return 0;
}