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
ll tt;
ll n, m, k, qq;
ll a[500010];
ll sum[500010];

void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n, greater<ll> ());
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
	{
		ll L = i, R = n;
		ll pos = i;
		while (L <= R)
		{
			ll mid = L + R >> 1;
			ll len = mid - i + 1;
			ll tmp = sum[mid] - sum[i - 1];
			if (len * a[i] - tmp <= m)
				pos = mid, L = mid + 1;
			else
				R = mid - 1;
		}
//		D(i), DE(pos);
		ans = max(ans, pos - i + 1);
	}
	cout << ans << '\n';
}

int main()
{
	ios ::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	for (tt = 1; tt--; )
		solve();
	return 0;
}