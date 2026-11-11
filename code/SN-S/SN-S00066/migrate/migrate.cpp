#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

ll c, t;

ll distance(ll u, ll v, vector<ll>& x) {
	return x[v] - x[u];
}

// Not Actually True.
bool force_judge(ll u, ll v, vector<ll>& x, vector<ll>& p, ll n, ll d) {
//	cout << "First" << endl;
	ll l = u, r = u, fd, ld;
	ll m = 0;
	while (1) {
//		printf("Flying...(%d,%d, d=%d,r=%d)\n", l, r, d, distance(l, r + 1, x));
		if (distance(l, l + 1, x) > d) {
			v = l;
			break;
		}
		for (;distance(l, r + 1, x) <= d; r++) {}
		if (m == 0) {
			fd = distance(l, min(r, v), x);
		}
		m++;
		l = r;
		if (r >= v) {
			break;
		}
	}
//	cout << "Second" << endl;
	ll m2 = 0;
	r = v; l = v;
	while (1) {
		for (;distance(l - 1, r, x) <= d; l--) {}
		if (l <= u) {
			ld = distance(max(l, u), r, x);
		}
		m2++;
		r = l;
		if (l <= u) {
			break;
		}
	}
	if (fd != ld && m2 == m) {
		return true;
	}
	return false;
}

void handle() {
	ll n, d;
	cin >> n >> d;
	vector<ll> x(n + 1);
	vector<ll> p(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> x[i];
		p[i] = p[i-1] + x[i];
	}
	// Ãÿ≈–
	if (distance(1, n, x) <= d) {
		cout << 0 << endl;
		return;
	}
	if (c == 13 || c == 14 || c == 1 || c == 2) {
		ll ans = 0;
		for (int i = 1; i <= n - 3; i++) {
			if (distance(i, i + 3, x) > d) {
				if (distance(i, i + 1, x) <= d && distance(i+1, i+3, x) <= d) {
					if (distance(i, i + 2, x) <= d && distance(i+2, i+3, x) <= d) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
		return;
	}
	
//	cout << "Forcing" << endl;
	
	// ±©¡¶
	ll ans = 0;
	for (ll u = 1; u < n; u ++) {
		for (ll v = u + 1; v <= n; v++) {
//			printf("Judge %d -> %d\n", u, v);
			ans += force_judge(u, v, x, p, n, d);
		}
	} 
	cout << ans << endl;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t-->0) {
		handle();
	}
	return 0;
}

