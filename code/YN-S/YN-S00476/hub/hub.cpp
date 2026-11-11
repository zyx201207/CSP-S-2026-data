#include <bits/stdc++.h>
using namespace std;
freeopen ("migrate.in", 'r', stdin);
freeopen ("migrate.out", 'w', stdout);

int main() {
	int c, t, n, k, d[1000] = {0}, z = 0, a[100], b[100], e[100];
	cin >> c >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> k;
		for (int j = 0; j < n - 1; j++) {
			cin >> a[i] >> b[i];
			e[i] = b[i] - a[i];
		}
		sort(e, e + n);
		d[z] = e[0];
		z++;
	}
	for (int i = 0; i < z; i++) {
		cout << d[i];
	}
	return 0;
}