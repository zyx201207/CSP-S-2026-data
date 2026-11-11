#include <bits/stdc++.h>
using namespace std;
int a[10], ans[3];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		cout << n;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int v[6] = {0, 0, 0, 0, 0, 0}, idx = 0;
		for (int j = i; j <= n; j++) {
			for (int k = 1; k <= 5; k++) {
				if (v[k] == a[j]) {
					for (int q = k; v[q] != 0; q++) {
						v[q] = 0;
					}
				}
			}
			v[idx] = a[j];
			idx++;
		}
		for (auto q : v) {
			if (q != 0) {
				ans[q]++;
			}
		}
	}
	cout << ans[1] << " " << ans[2];
}
