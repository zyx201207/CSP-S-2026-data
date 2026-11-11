#include <bits/stdc++.h>
using namespace std;
const int N = 5e6 + 10;
long long n, m, b[N], x = 1e13 + 10, y, c[N], d[N], z;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			b[i] += abs(a[i] - a[j]);
			c[j] = a[i] - a[j];
			if (c[j] < 0) {
				c[j] =	1e13 + 10;
			}
		}
		if (x > b[i]) {
			x = b[i];
			y = i;
			sort(c + 1, c + 1 + n);
			for (int k = 1; k <= n; k++) {

				d[k] = c[k];


			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (m -  d[i] < 0) {
			break;
		} else {
			m = m -  d[i];
			z++;
		}
	}

	cout << z;
	return 0;
}