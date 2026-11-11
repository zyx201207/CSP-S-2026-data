#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200010], mx, x;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n);
	x = a[n - 1];
	for (int i = n - 2; i >= n - m; i--) {
		x = x & a[i];
	}
	cout << x << endl;
	return 0;
}