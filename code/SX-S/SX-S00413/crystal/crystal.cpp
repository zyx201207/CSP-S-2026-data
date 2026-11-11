#include <bits/stdc++.h>
using namespace std;

struct ab {
	long long c, ll;
} b[500010];
long long a[500010], n, m, kk = -1, k, maxs = LLONG_MIN, l, r;

int check(long long x) {
	long long s = 0, ss = 0, f = 0;
	for (int i = x; i >= 1; i--) {
		if (s <= m) {
			s = s + (b[x].c - b[i].c) * b[i].ll;
			ss += b[i].ll;
		}
		if (s > m) {
			f = 1;
			ss += (s - m) / (b[x].c - b[i].c);
			break;
		}
	}
	if (!f) {
		maxs = max(maxs, ss);
		return 1;
	} else {
		return 0;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	a[0] = LLONG_MAX;
	a[n + 1] = LLONG_MAX;
	for (int i = 1; i <= n + 1; i++) {
		if (a[i] != a[i - 1]) {
			b[++kk].c = a[i - 1];
			b[kk].ll = i - k;
			k = i;
		}
	}
	l = 1;
	r = n;
	while (l < r) {
		long long mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	cout << maxs;
	return 0;
}
