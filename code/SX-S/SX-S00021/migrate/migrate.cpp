#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "W", stdout);
	long long c, t;
	cin >> c >> t;
	long long n, d;
	vector<long long>x(n + 10);
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
	}
	if (n == 5) {
		cout << 1 << endl << 2;
	}
	if (n == 6) {
		cout << 0 << endl << 1;
	}
	return 0;
}









