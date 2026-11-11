#include <bits/stdc++.h>
#define rep(i, l, r) for (ll i = (l); i <= (r); ++i)
#define REP(i, r, l) for (ll i = (r); i >= (l); --i)
using namespace std;

typedef long long ll;

ll n, m, l, r, mid;
ll a[500010];
ll b[500010];
ll c[500010];

bool check(ll len) {
	if (len == 1) {
		return true;
	}
	__int128 cur = 0;
	rep(i, 2, len) {
		cur += (i - 1) * b[i];
	}
	if (cur <= m) {
		return true;
	}
	rep(i, 3, n - len + 2) {
		cur += (c[i - 1] - c[i + len - 2]) + static_cast<__int128>(len - 1) * b[i + len - 2];
		if (cur <= m) {
			return true;
		}
	}
	return false;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	rep(i, 2, n) {
		b[i] = a[i] - a[i - 1];
		c[i] = c[i - 1] + b[i];
	}
	l = 1;
	r = n;
	while (l < r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << l - 1 << '\n';
	return 0;
}
