#include <bits/stdc++.h>
using namespace std;
unsigned long long x[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;

	while (t--) {
		int n;
		unsigned long long d;
		cin >> n >> d;

		for (int i = 1; i <= n; i++) {

			cin >> x[i];
		}

		cout << n - 1 << endl;
	}

	return 0;
}