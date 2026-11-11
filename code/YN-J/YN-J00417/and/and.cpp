#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int a[200001];
int gm;
int g;
int w[200001];
int l = 0;
int z;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n;
	cin >> m;
	for (int q = 0; q < n; q++) {
		cin >> a[q];
	}
	for (int q = 0; q < n; q++) {
		if (a[q] % 2 == 1) {
			gm++;
		}
	}
	if (m == 1) {
		for (int q = 0; q < n; q++) {
			if (z <= a[q]) {
				z = a[q];
			}
		}
		cout << z;
		return 0;
	}
	if (gm == n) {
		for (int q = 0; q < n; q++) {
			l++;
			if (l <= m) {
				for (int u = 0; u < n; u++) {
					if (a[g] < a[u]) {
						g = u;
					}
				}
				w[l] = a[g];
				a[g] == 0;

			}
		}
		cout << w[m];
	}
}