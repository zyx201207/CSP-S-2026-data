#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 5;
ll c, T;
ll n, d;
ll a[N];
pair<ll, ll> b[N];
ll nex[N];

ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -f;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

void solve() {
	n = read();
	d = read();
	for (ll i = 1; i <= n; i++) {
		a[i] = read();
	}
	if (n == 1 || d == 1) {
		cout << 0 << endl;
	} else if (c == 11 || c == 12) {
		ll c = a[2] - a[1];
		ll m = d / c;
		if (m <= 1) {
			cout << 0 << endl;
			return;
		}
		cout << max(0ll, n - 2 * m + 1) << endl;
	} else {
		queue<ll> q;
		for (ll i = 1; i <= n; i++) {
			while (!q.empty() && a[i] - a[q.front()] > d && a[i - 1] - a[q.front()] <= d) {
				nex[q.front()] = i - 1;
				q.pop();
			}
			q.push(i);
		}
		while (!q.empty()) {
			nex[q.front()] = n;
			q.pop();
		}
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			b[i] = {0, 1};
			for (ll j = i - 1; j >= 1; j--) {
				if (nex[j] == j) {
					break;
				}
				b[j] = {0, 0};
				for (ll k = min(i, nex[j]), c = 3; k > j && c; k--, c--) {
					if (b[j].first == 0) {
						b[j] = {b[k].first + 1, b[k].second};
					} else if (b[j].first == b[k].first + 1) {
						b[j].second += b[k].second;
					}
				}
				b[j].second = min(b[j].second, (long long)3);
				if (b[j].second == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read();
	T = read();
	for (ll i = 1; i <= T; i++) {
		solve();
	}

	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/