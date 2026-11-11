#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n = 2, a[10005] = {1, 2}, m = 2, j = 0, k,
	                      nn = 0, shu, w[100005] = {0}, c[100005] = {0}, po = 0, cd, cf;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	if (m == 1) {
		cout << a[n - 1];
		return 0;
	}
	for (int i = n - 1; i >= 0; i--) {
		shu = a[i];
		while (shu > 0) {
			w[j] = shu % 2;
			shu = shu / 2;
			j++;
		}
		if (i == n - 1)
			k = j;
	}
	if (m == 2) {
		while (po <= n) {
			cd = w[po] and w[po];
			po++;
			nn = cd << po + nn;
		}
		cout << nn;
		return 0;
	}
	cout << n;
}

