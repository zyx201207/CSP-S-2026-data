#include <bits/stdc++.h>
using namespace std;
long long sum;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d, x[10001] = {}, p[10001] = {}, m = 0;
		sum = 0;
		int o = 0;
		cin >> n >> d;
		int n1 = n;
		for (int i = 0; i < n; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < n; i++) {
			m += x[i];
		}
		if (m < 0)
			m = (-1) * m;
		cout << m / 2 + 1;
	}
	return 0;
}
//0 3 7 20 2
// 8 3 6 1 7 2 9
// 3 1 4 2 5 5 100
//3 2 6 3 1 7 2
// 4 3 2 5 100 4
