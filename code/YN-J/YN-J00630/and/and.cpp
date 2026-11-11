#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[10005], num = 0, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] <= a[i + 1]) {
			num = a[i + 1];
		}
		num = c[i];
		d = min(c[i], c[i + 1]);
		if (d > sum) {
			sum = d;
		}
	}
	cout << sum;
	return 0;
}
