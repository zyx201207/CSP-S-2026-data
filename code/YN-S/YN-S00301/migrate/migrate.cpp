#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long  n, m, x, y, a[N], b;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		b = 0;
		for (int j = 1; j <= x; j++) {
			cin >> a[j];
		}
		for (int j = 1; j <= x; j++) {
			for (int k = 1; k <= j; k++) {
				if (abs(a[j] - a[k]) % y == y - 1 && abs(a[j] - a[k]) > y && abs(a[j] - a[k]) / y == 1 && a[j + 1] != a[k]
				        && a[j - 1] != a[k]) {
					b++;
				}
			}
		}
		cout << b << endl;
	}

	return 0;
}
