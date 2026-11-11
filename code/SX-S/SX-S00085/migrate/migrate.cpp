#include <bits/stdc++.h>
using namespace std;
int a[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, n, d;
	cin >> c;
	for (int i = 1; i <= t; i++) {
		cin >> n >> d;
		for (int j = 1; j <= n; j++ ) {
			cin >> a[i];
		}
		for (int j = 1; j <= n; j++) {
			for (int k =; k <= n; k++) {
				if (abs(a[k] - a[j]) > d) {
					int x = 0, f = j;
					for (int l = j; l <= k; l++) {
						x += abs(a[l] - a[f]);
						if (x >= d) {
							x = x - d;
							f = l;
						}
					}
					for (int l = j; l <= k; l++) {
						x += abs(a[l] - a[f]);
						if (x >= d) {
							x = x - d;
							f = l;
						}
					}
				}
			}
		}

	}
	return 0;
}
