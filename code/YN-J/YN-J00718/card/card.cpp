#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, b[300005], c[300005], a[300005], ww = 1, tt = 1;
map<ll, ll> mp;

void f(ll t, ll w) {
	for (ll i = 1; i <= n; i++) {
		if (mp[b[i]] != 1) {
			mp[b[i]] = 1;
			w++;
			a[w] = b[i];
		} else {
			while (a[t] != b[i]) {
				mp[a[t]] = 0;
				t++;
			}
		}
	}
	ww = w;
	tt = t;
	for (ll i = t; i <= w; i++) {
		c[a[i]]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (ll i = 1; i <= n; i++) {
		f(tt, ww);
	}
	for (ll i = 1; i <= m; i++) {
		if (c[i] != 0) {
			cout << c[i] << ' ';
		}
	}
}