#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 5;
ll n, m;
ll a[N];
ll sum[N];

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

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read();
	m = read();
	for (ll i = 1; i <= n; i++) {
		a[i] = read();
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll l = 1, r = i;
		ll pos = i;
		while (l <= r) {
			ll mid = (l + r) >> 1;
			if ((i - mid + 1)*a[i] - (sum[i] - sum[mid - 1]) <= m) {
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		ans = max(ans, i - pos + 1);
	}
	cout << ans << endl;



	return 0;
}

