#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];

int And(int x, int y) {
	int s = 0, i = 0;
	if (x < y) {
		swap(x, y);
	}
	while (y != 0) {
		if (x % 2 == 1 && y % 2 == 1) {
			s += pow(2, i);
		}
		x = x >> 1;
		y = y >> 1;
		i += 1;
	}
	return s;
}

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i = i + 1) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (m == 1) {
		cout << a[n];
		return 0;
	}
	for (int i = n; i > m; i = i - 1) {
		a[i - 1] = And(a[i], a[i - 1]);
	}
	cout << a[n - m + 1];
	return 0;
}