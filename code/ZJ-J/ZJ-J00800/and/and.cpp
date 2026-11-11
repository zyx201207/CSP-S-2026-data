#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 10;
ll n, m, maxn = -1;
ll a[N];
map <ll, bool> p;
map <ll, ll> Cnt;
void init () {
	ll num = 1;
	for (ll i = 1; i <= 30; i++) {
		p[num] = true;
		num *= 2;
	}
	return ;
}
void dfs (ll idx, ll sum, ll cnt) {
	if (cnt == m) {
		maxn = max (maxn, sum);
		return ;
	}
	if (idx > n) {
		return ;
	}
	dfs (idx + 1, sum & a[idx + 1], cnt + 1);
	dfs (idx + 1, sum, cnt);
}
void Bdfs (ll num, ll sum, ll cnt) {
	if (cnt >= m) {
		maxn = max (maxn, sum);
		return ;
	}
	if (num > 3) {
		return ;
	}
	dfs (num + 1, sum & (num + 1), cnt + Cnt[num + 1]);
	dfs (num + 1, sum, cnt);
}
int main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	
	init ();
	cin >> n >> m;
	bool flagA = true, flagB = true;
	if (!p[n]) flagA = false;
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		if (!p[a[i] + 1]) flagA = false;
		if (a[i] > 4) flagB = false;
	}
	if (flagA) {
		sort (a + 1, a + 1 + n);
		cout << a[n - m];
	} else if (flagB) {
		for (ll i = 1; i <= n; i++) {
			Cnt[a[i]]++;
		}
		for (ll i = 1; i < 4; i++) {
			if (Cnt[i] >= m) {
				maxn = max (maxn, i);
			}
		}
		if (maxn != -1) {
			cout << maxn;
		} else {
			for (ll i = 1; i < 4; i++) {
				Bdfs (i, i, Cnt[i]);
			}
			cout << maxn;
		}
	} else if (n == m) {
		int ans = a[1];
		for (ll i = 2; i <= n; i++) {
			ans &= a[i];
		}
		cout << ans;
	} else if (m == 2) {
		for (ll i = 1; i <= n; i++) {
			for (ll j = i + 1; j <= n; j++) {
				maxn = max (maxn, a[i] & a[j]);
			}
		}
		cout << maxn;
	} else {
		for (ll i = 1; i <= n; i++) {
			dfs (i, a[i], 1);
		}
		cout << maxn;
	}
	return 0;
}
