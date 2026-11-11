#include <bits/stdc++.h>
using namespace std;
unsigned long long m, n, a[100000000], n1, u;

int d(int step, unsigned long long  maxx) {
	if (n1 == m) {
		maxx = max(maxx, maxx & a[n1]);
		return maxx;
	}

	for (int i = step + 1; i < n; i++) {

		n1++;
		d(i, maxx);
	}

	return 0;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {

		unsigned long long p = u;
		u = d(i, a[i]);
		u = max(p, u);
	}

	cout << u;
	return 0;
}
