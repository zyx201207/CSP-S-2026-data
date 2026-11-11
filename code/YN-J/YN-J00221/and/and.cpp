#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, mj = 9999;
	cin >> n >> m;
	int cb[m + 1], a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		int goat = 0, cc;
		for (int j = 1; j <= n; j++) {
			if (a[j] > goat) {
				goat = a[j];
				cc = j;
			}
		}
		cb[m] = goat;
		a[cc] = 0;
	}
	for (int i = 1; i <= m; i++) {
		if (cb[i] < mj) {
			mj = cb[i];
		}
	}
	cout << mj;
}