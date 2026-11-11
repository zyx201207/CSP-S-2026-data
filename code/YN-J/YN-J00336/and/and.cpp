#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w"stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];

	}
	sort(a, a + n);
	if (m == n && (a[n - 1] == 0 || a[0] == 0)) {
		cout << "0";
		return 0;
	} else if (m == n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum = a[i] & sum;
		}
		cout << sum;
		return 0;
	}
	if (m == 1) {
		cout << max(a[0], a[n - 1]);
		return 0;
	}
	if (m = n - 1) {
		cout << "1";
		return 0;
	}
	if (m = 2) {
		cout << max(a[0]&a[1], a[n - 1]&a[n - 2]);
		return 0;
	}
}