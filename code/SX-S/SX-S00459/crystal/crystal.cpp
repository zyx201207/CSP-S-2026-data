#include <bits/stdc++.h>
using namespace std;
long long n, m, sum, number;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	sum = 0;
	cin >> n >> m;
	int a[n + 1], c[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	c[0] = 0;
	while (m > 0) {
		for (int i = 1; i <= n; i++) {
			c[i] = a[i + 1] - a[i];
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] < a[i + 1]) {
				a[i] += c[i];
				if (m >= c[i]) {
					m = m - c[i];
					sum = a[i];
					break;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == sum) {
			number++;
		}
	}
	cout << number << endl;
	return 0;
}