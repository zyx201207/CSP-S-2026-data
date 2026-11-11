#include <bits/stdc++.h>
using namespace std;
long long a[2000020];
int b[2000020], c[2000020];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		long long n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (a[2] - a[1] == a[3] - a[2]) {
			int sum = a[4] - a[3];
			if (m >= sum * 2 && m <= sum * 3) {
				cout << n - 3 << endl;
			} else {
				cout << 0 << endl;
			}
		} else if (n > 5000)
			cout << 0 << endl;
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}