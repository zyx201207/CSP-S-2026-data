#include <bits/stdc++.h>
using namespace std;
int c, t, n, sum;
long long d, a[2001000];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	for (int o = 1; o <= t; o++) {
		sum = 0;
		memset(a, 0, sizeof(0));
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		if (c == 11 or c == 12) {
			int d2 = a[2] - a[1];
			if (d2 >= d)
				sum = 0;
			else {
				int k = d2 % d;
				int k2 = 2 * k - 1;
				for (int i = 1; i <= n; i++) {
					if (i + 2 <= n)
						sum++;
					if (i + k2 <= n)
						sum++;
				}
			}
		} else {
			for (int i1 = 1; i1 <= n - 2; i1++) {
				for (int j1 = i1 + 2; j1 <= n; j1++) {
					int s = 0;
					for (int k1 = i1 + 1; k1 <= j1; k1++) {
						if (a[k1] - a[i1] <= d and a[j1] - a[k1] <= d )
							s++;
					}
					if (s == 2)
						sum++;
				}
			}

		}
		cout << sum << endl;
	}
	return 0;
}
