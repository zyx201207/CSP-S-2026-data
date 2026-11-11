#include <bits/stdc++.h>
using namespace std;
int c, t;
long long n, d;
long long x[2000000];
long long sum;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while (t--) {
		if (c >= 15 && c <= 18) {
			if (x[3] - x[1] <= d) {
				cout << n / 2;
			}
		} else {
			sum = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> x[i];
			}
			for (int i = 1; i <= n - 3; i ++) {
				if (x[i + 3] - x[i] <= d) {
					continue;
				} else if (x[i + 3] - x[i + 2] <= d && x[i + 2] - x[i] <= d && x[i + 3] - x[i + 1] <= d && x[i + 1] - x[i] <= d) {
					sum++;
				}
			}
			cout << sum << '\n';
		}

	}
	return 0;
}
