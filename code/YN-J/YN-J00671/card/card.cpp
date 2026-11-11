#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[1000005], m, b[1000005], c[1000005], d[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll k = 1; k <= n; k++) {
			b[k] = 0;
		}
		for (ll k = 1; k <= n; k++) {
			d[k] = 0;
		}
		for (ll k = i; k <= n; k++) {
			ll cnt = 0;
			for (ll j = 1; j < k; j++) {
				if (b[j] == a[k]) {
					cnt = j;
				}
			}
			if (cnt != 0) {
				for (ll j = cnt; j <= n; j++) {
					b[j] = 0;
				}
				b[cnt] = a[k];

			} else {
				for (ll j = 1; j <= n; j++) {
					if (b[j] == 0) {
						b[j] = a[k];
						break;
					}
				}
			}
		}
		for (ll j = 1; j <= n; j++) {
			if (b[j] != 0 && d[b[j]] == 0) {
				c[b[j]]++;
				d[b[j]] = 1;
			}
		}
	}
	for (ll i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
}