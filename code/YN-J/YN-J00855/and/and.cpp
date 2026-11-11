#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200001], maxn = -1;

int main() {
	freopen("and.in", "w", stdin);
	freopen("and.out", "r", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (m == 2) {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j <= n - 1; j++) {
				if (a[i]&a[j] > maxn) {
					maxn = a[i] & a[j];
				}
			}
		}
	} else if (m == 1) {
		for (int i = 0; i < n - 1; i++) {
			if (maxn < a[i]) {
				maxn = a[i];
			}
		}
	}
	cout << maxn;
	return 0;
}