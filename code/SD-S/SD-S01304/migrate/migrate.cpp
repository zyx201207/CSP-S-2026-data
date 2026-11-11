# include <bits/stdc++.h>
# define ll long long
# define inf 0x3f3f3f3f3f3f3f3f

using namespace std;

const ll N = 2e6 + 5;
ll c, t, n, d, ans;
ll a[N], dis[N], cnt[N], dp[N];
bool f[N];

void Dij (ll root) {
	memset (dis, 0x3f, sizeof (dis));
	memset (cnt, 0, sizeof (cnt));
	memset (f, 0, sizeof (f));
	priority_queue <pair <ll, ll> > q;
	cnt[root] = 1;
	dis[root] = 0;
	q.push ({0, root});
	while (! q.empty ()) {
		ll x = q.top ().second; q.pop ();
		f[x] = 1;
		for (ll y = 1; y <= n; y ++) {
			ll dep = a[x] - a[y];
			if (dep < 0) dep = -dep;
			if (dep <= d) {
				if (f[y]) continue ;
				if (dis[x] + 1 < dis[y]) {
					dis[y] = dis[x] + 1;
					q.push ({- dis[y], y});
					cnt[y] = cnt[x];
				} else if (dis[x] + 1 == dis[y])
					cnt[y] += cnt[x];
			}
		}
	}
	//for (ll i = 1; i <= n; i ++) cout << dis[i] << " ";
	//cout << "\n";
	//for (ll i = 1; i <= n; i ++) cout << cnt[i] << " ";
	//cout << "\n";
	for (ll i = root + 1; i <= n; i ++)
		if (cnt[i] == 2) ans ++;
}

int main () {
	
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	cin >> c >> t;
	while (t --) {
		cin >> n >> d;
		ans = 0;
		for (ll i = 1; i <= n; i ++) cin >> a[i];
		if (n <= 5000) {
			for (ll u = 1; u <= n; u ++) Dij (u);
			cout << ans << "\n";
		} else {
			// µÈ²î
			memset (dp, 0, sizeof (dp));
			dp[1] = 1;
			for (ll i = 2; i <= n; i ++) {
				for (ll j = 1; j < i; j ++) {
					if (a[i] - a[j] <= d) 
						dp[i] += dp[j];
				}
			}
			cout << dp[n] << "\n";
		}
	}

	return 0;
}

