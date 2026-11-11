#include <bits/stdc++.h>
using namespace std;

long long c, t, x[2000200], n, d, sum, e;
bool b;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		sum = 0;
		b = false;
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> x[j];
			if (j >= 3) {
				if (x[j] - x[j - 1] != x[j - 1] - x[j - 2]) {
					b = true;
					//cout << x[j] << ';' << x[j - 1] << ";;;" << x[j - 1] << ';' << x[j - 2] << endl;
				}
			}
		}
		//cout << b << ';';
		if (b == false) {
			e = x[2] - x[1];
			if (d >= 2 * e && d < 3 * e) {
				cout << n - 3 << endl;
			} else {
				cout << 0 << endl;
			}
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}