# include <bits/stdc++.h>
# define ll long long

using namespace std;

const ll N = 2e5 + 5;
ll n, m, ans, a[N];
bool f[N], vis[N];

bool cmp (ll x, ll y) {
	return x > y;
}

int main () {
	
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n >> m; ans = (1 << 31) - 1;
	for (ll i = 1; i <= n; i ++) cin >> a[i], f[i] = 1;
	for (ll j = 31; j >= 0; j --) {
		memset (vis, 0, sizeof (vis));
		vector <ll> vec;
		for (ll i = 1; i <= n; i ++) {
			if ((a[i] >> j) & 1) {
				vec.push_back (i);
				vis[i] = 1;
			}
		}
		ll cnt = 0;
		for (ll i = 0; i < vec.size (); i ++) {
			ll x = vec[i];
			if (f[x]) cnt ++;
		}
		if (vec.size () < m) continue ;
		if (cnt < m) {
			vector <ll> res;
			for (ll i = 1; i <= n; i ++)
				if (f[i]) res.push_back (a[i]);
			sort (res.begin (), res.end (), cmp);
			for (ll i = 0; i < m; i ++) 
				ans &= res[i];
			cout << ans;
			return 0;
		} else {
			for (ll i = 1; i <= n; i ++)
				if (f[i] && ! vis[i]) f[i] = 0;
		}
	}
	vector <ll> res;
	for (ll i = 1; i <= n; i ++)
		if (f[i]) res.push_back (a[i]);
	sort (res.begin (), res.end (), cmp);
	for (ll i = 0; i < m; i ++) 
		ans &= res[i];
	cout << ans;
	
	return 0;
}

