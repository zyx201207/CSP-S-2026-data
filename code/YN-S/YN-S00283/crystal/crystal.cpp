#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
	return a < b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal,out", "w", stdout);
	int n = 0, m = n, a[500005] = {0}, ans = 0, d = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < m; i++) {
		while (m > 0) {
			m--;
			for (int d = 0; d < n; d++) {
				if (a[i] + m == a[i + d]) {
					ans++;

				}
			}
		}
	}
	cout << ans;
	return 0;
}