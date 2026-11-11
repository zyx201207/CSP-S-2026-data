#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin)   ;
	freopen("card.out", "w", stdout);
	int a[10005], n, m, cs = 0, b[10005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (a[j] != a[i]) {

				continue;
			}
			if (a[j] == a[i]) {
				break;
			}
			int k = a[i];
			a[j - 1] = a[j];
			a[n] = k;
		}
		if (cs == n) {
			for (int j = 1; j <= m; j++) {
				if (a[i] == a[j]) {
					b[j]++;
				}
			}
		}
		cs++;
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i];
	}
	return 0;
}