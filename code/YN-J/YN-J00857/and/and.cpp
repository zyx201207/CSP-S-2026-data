#include <bits/stdc++.h>
using namespace std;

int n, m, a[200001], b[200001], mx = -1, ans;

int And(int x, int y) {
	int z = a[x];
	for (int i = x + 1; i <= y; i++) {
		z = z & a[i];
	}
	return z;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[a[i]]++;
		if (b[a[i]] > 1) {
			mx = max(a[i], mx);
			ans = mx;
		}
	}
	for (int i = 1; i <= n - m + 1; i++) {
		for (int j = i + m - 1; j <= n; j++) {
			ans = max(And(i, j), ans);
		}
	}
	cout << ans;
	return 0;
}