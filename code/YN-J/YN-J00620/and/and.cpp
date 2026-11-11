#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[200005];
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		int b = a[i] % 10;
		a[i] /= 10;
		c[i] = max(b & a[i], c[i]);
	}
	sort(c + 1, c + 1 + m);
	if (c[m + 1] == 0) {
		cout << 511;
	} else
		cout << c[m + 1];

	return 0;
}
