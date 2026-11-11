#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NM = 1e5 + 10;
ll c, t, n, d, nmin;

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

namespace subtesk {
	void solve() {
		if (a[n] <= d) {
			cout << 0 << '\n';
		} else {
			cout << 1 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		bool f = 1;
		cin >> n >> d;
		vector<ll>a(n + 1);
		cin >> a[1] >> a[2];
		nmin = a[2] - a[1];
		for (int i = 3; i <= n; i++) {
			cin >> a[i];
			if (a[i] - a[i - 1] != nmin) {
				f = 0;
			}
		}
		if (f) {
			if (nmin * 2 > d) {
				cout << 0 << '\n';
				continue;
			}
			subtesk::solve();
			continue;
		}
		if (d == 1) {
			cout << 0;
			continue;
		}
		cout << 2 << '\n';
	}
	return 0;
}
