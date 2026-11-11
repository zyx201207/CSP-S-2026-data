#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, a[500005], a1[500005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a1[i] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		int c = 1, ans = 0;
		bool f = true;
		for (int j = i; j <= n; j++) {
			for (int k = j; k <= n; k++) {
				if (a[j] != a[k]) {
					f = true;
				} else {
					f = false;
				}
			}
			if (f) {
				a[n + c] = a[j];
				c++;
			} else {
				for (int t = j; t <= n; t++) {
					a[t] = 0;
				}
				a[j + 1] = a[j];
			}
		}
		for (int d = 1; d <= n + c; d++) {
			if (a[d] == i) {
				ans++;
			}
		}
		cout << ans << " ";
		for (int l = 1; l <= n; l++) {
			a[i] = a1[i];
		}

	}
	return 0;
}