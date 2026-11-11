#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 10;
ll c, t, ans =  0;
ll n, d;
ll a[N];
struct w {
	ll val, cnt;
};
map <ll, w> m;
map <ll, ll> far;
ll getid(int u, int v) {
	return ((u - 1) * n + v);
}
void dfs (ll s, ll idx, ll sum) {
	if (m [getid (s, idx)].val == 0 || m [getid (s, idx)].val > sum) {
		m [getid (s, idx)].val = sum;
		m [getid (s, idx)].cnt = 1;
	} else if (m[getid (s, idx)].val == sum) {
		m [getid (s, idx)].cnt++;
	} else {
		return ;
	}
	if (idx >= n) {
		return ;
	}
	for (ll i = idx + 1; i <= far[idx]; i++) {
		dfs (s, i, sum + 1);
	}
}
void solve () {
	ans = 0;
	m.clear ();
	far.clear ();

	cin >> n >> d;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll i = 1, j = i;
	while (i <= n) {
		while (j + 1 <= n && a[j + 1] - a[i] <= d) {
			j++;
		}
		far[i] = j;
		i++;
	}
	for (ll i = 1; i <= n; i++) {
		dfs (i, i, 0);
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = i + 1; j <= n; j++) {
			if (m.count(getid (i, j)) && m [getid (i, j)].cnt == 2) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}
int main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		solve ();
	}
	return 0;
}
