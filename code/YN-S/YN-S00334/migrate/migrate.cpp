#include <bits/stdc++.h>
using namespace std;

int a[1000002];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d;
	cin >> c >> t >> n >> d;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << n - 1;
	return 0;
}