#include <bits/stdc++.h>
using namespace std;
long long a[300000];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int m1 = m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 2) {
		long long sun = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (j != i) {
					sun = max(sun, a[i] & a[j]);
				}
			}
		}
		cout << sun;
		return 0;
	}
	sort(a + 1, a + 1 + n);
	long long sun = a[n];
	for (int i = n - 1; i >= n - m + 1; i--) {
		sun &= a[i];
	}
	cout << sun;
	return 0;
}