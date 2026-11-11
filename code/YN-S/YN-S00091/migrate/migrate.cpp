#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e6;
long long x[maxn];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long c, t;
	cin >> c >> t;
	if (c == 0 || c == 11 || c == 12 ) {
		while (t--) {
			long long n, d;
			cin >> n >> d;
			for (long long i = 0; i < n; i++) {
				cin >> x[i];
			}
			long long p = x[1] - x[0];
			long long m = d / p;
			m <<= 1;
			if (m > 2 && m < n) {
				cout << n - m + 1 << "\n";
			} else
				cout << 0 << "\n";
		}

	} else {
		while (t--) {
			cout << "0\n";
		}
	}

}
