#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NM = 5e5 + 5;
ll n, m, a[NM], k = 0, ans = -1;

ll read() {
	int ss = 0, mm = 1;
	char cc = getchar();
	while (cc < '0' || cc > '9') {
		if (cc == '-') {
			mm = -1;
		}
		cc = getchar();
	}
	while (cc >= '0' && cc <= '9') {
		ss = ss * 10 + (cc - '0');
		cc = getchar();
	}
	return ss * mm;
}

namespace subtesk1 {
	void solve() {
		int i = 1;
		while (i++) {
			if ((i * (i * k + k) / 2) > m) {
				break;
			}
		}
		cout << i << '\n';
		return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	n = read(), m = read();
	bool f = 1, ff = 1;
	a[2] = read();
	k = a[2] - a[1];
	for (int i = 3; i <= n; i++) {
		a[i] = read();
		if (a[i] - a[i - 1] != k) {
			ff = 0;
		}
	}
	if (ff) {
		subtesk1::solve();
		return 0;
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) {
		ll j, cs = m, tmp = 0;
		j = i;
		for (j; j >= 1; j--) {
			if (cs >= a[i] - a[j]) {
				cs = cs - a[i] + a[j];
				tmp++;
			} else {
				break;
			}
		}
		ans = max(tmp, ans);
	}
	cout << ans << '\n';
	return 0;
}