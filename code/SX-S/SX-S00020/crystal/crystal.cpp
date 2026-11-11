#include <bits/stdc++.h>
using namespace std;

int n, m, a[100000005], b, p = 0;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (n % 2) {
		b = a[n / 2 + 1];
	} else {
		b = a[n / 2];
	}
	int i, sum = 0;
	for (i = 1; i <= n; i++) {
		if (a[i] == b) {
			p++;
		}
		for (int j = 0; j < n; j++) {
			if (a[i] + j == b) {
				sum++;
			}
			if (sum == m) {
				break;
			}

		}
		if (sum == m) {
			break;
		}
	}
	cout << (i + p) / 2;
	return 0;
}
