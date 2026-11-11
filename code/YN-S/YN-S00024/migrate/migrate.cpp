#include <bits/stdc++.h>
using namespace std;

bool dc(int a[], int n) {
	int q = a[2] - a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] - a[i - 1] != q)
			return false;
	}
	return true;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		int n, d;
		int a[200010];
		cin >> n >> d;
		for (int j = 1; j <= n; j++) {
			cin >> a[j];
		}
		if (dc(a, n)) {
			cout << n - 3 << endl;
		}
	}
	return 0;
}