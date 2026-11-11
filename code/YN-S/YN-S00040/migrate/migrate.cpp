#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MAX = 1e18;

ll read() {
	int op;
	ll n = 0;
	char c = getchar();
	if (c == '-') {
		op = -1;
		c = getchar();
	} else {
		op = 1;
	}
	while (c >= '0' && c <= '9') {
		n = 10 * n + c - '0';
		c = getchar();
	}
	return op * n;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int ccc, tt;
	ccc = read(), tt = read();
	while (tt--) {
		ll n, d;
		n = read(), d = read();
		vector<ll>x(n);
		for (int i = 0; i < n; i++) {
			x[i] = read();
		}
		//
		vector<vector<ll> >ct(n);
		vector<vector<ll> >minv(n);
		for (int i = 0; i < n; i++) {
			ct[i].resize(n), minv[i].resize(n);
			for (int j = i + 1; j < n; j++) {
				if (x[j] - x[i] <= d) {
					ct[i][j] = 1, minv[i][j] = 1 - MAX;
					continue;
				}
				if (x[j] - x[i] > d && j - i == 1) {
					ct[i][j] = 0, minv[i][j] = MAX;
					continue;
				}
				int k = 0;
				while (j - k - 1 > i && x[j] - x[j - k - 1] <= d) {
					k++;
					minv[i][j] = min(minv[i][j], minv[i][j - k] + 1);
				}
				k = 0;
				while (j - k - 1 > i && x[j] - x[j - k - 1] <=  d) {
					k++;
					if (minv[i][j] == minv[i][j - k] + 1) {
						ct[i][j] += ct[i][j - k];
					}
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (ct[i][j] == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}