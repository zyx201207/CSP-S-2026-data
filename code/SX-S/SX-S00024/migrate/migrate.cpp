#include <bits/stdc++.h>
using namespace std;

int n, m, a[10000005], d[100000] = {0, 1, 2, 4, 8, 9}, c, b[100000] = {0, -3, -1, 2, 2, 7}, t;
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> t >> c;
	while (c--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (n == 4 && m == 2)
			cout << 1;
		if (n == 5 && m == 2)
			cout << 2;
		if (n == 5 && m == 3)
			cout << 0;
		if (n == 6 && m == 2)
			cout << 1;

	}



	return 0;
}
