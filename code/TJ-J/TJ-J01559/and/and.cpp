#include <bits/stdc++.h>
using namespace std;
long long a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long y = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	y = a[n];
	long long x = 0, z = y;


	for (int i = n; i >= m; i--) {
		z = y;
		for (int j = i ; j > i - m; j--) {
			z = z & a[i];
		}
		if (x < z) {
			x = z;
		}

	}
	cout << x;
	return 0;
}