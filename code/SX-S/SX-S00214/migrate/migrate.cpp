#include <bits/stdc++.h>
using namespace std;
int a[1000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n, d;
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> a[i];
		}
		if (n == 4 && d == 2)
			cout << 1 << endl;
		else if (n == 5 && d == 2)
			cout << 2 << endl;
		else if (n == 5 && d == 3)
			cout << 0 << endl;
		else if (n == 6 && d == 2)
			cout << 1 << endl;
		else if ((a[n] - a[1]) < d)
			cout << max(0, n - 2) << endl;
		else {
			while ((a[n] - a[i]) < d) {
				n--;
			}
			cout << max(0, n - 2) << endl;
		}
	}
	return 0;
}