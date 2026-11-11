#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int m, n, d = 0;
	int a[10000];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int x = a[i] & a[i - 1];
		if (x > d) {
			d = x;
		}
	}
	cout << d;

	return 0;
}