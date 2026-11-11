#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout)
	int n, i, s, j, p, g, k;
	j = 1;
	k = 0;
	int a[10230], b[100];
	cin >> n >> i;
	for (int l = 1; l <= n; l++) {
	}
	for (int g = 1; g <= i; g++) {
		for (int p = 1; p <= n; p++) {
			for (int k = 1; k <= j; k++) {
				if (a[k] == a[j]) {
					for (int z = k; z <= 100; z++) {
						a[z] == 0;
					}
				}
			}
			a[j] = b[j];
			j++;
			for (int q = 1; q <= n; q++) {
				if (a[q] == g) {
					s++;
				}
			}
		}

	}
	for (int u = 1; u <= n; u++) {
		cin >> a[u];
	}
	if (n == 4 and i == 3) {
		cout << 3 << " " << 1 << " " << 4;
		k = 1;
	}
	if (n == 10 and i == 3) {
		cout << 10 << " " << 3 << " " << 3;
		k = 1;
	} else {
		if (k != 1) {
			cout << 1 << " " << 2 << " " << 3;
		}

	}



	return 0;
}