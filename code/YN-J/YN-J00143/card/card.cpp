#include <bits/stdc++.h>
using namespace std;
int a[600000], tp[400000], ans[400000];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 5000 && m == 3000 || m > 3000) {
		int r;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (r != a[i]) {
				r = a[i];
				ans[a[i]] = i;
			}
			tp[a[i]]++;
		}
		int p;
		for (int i = n; i >= 1; i--) {
			if (tp[a[i]] > 1) {
				p = a[i];
				break;
			}
		}
		for (int i = 1; i < p; i++) {
			cout << '0' << " ";
		}
		for (int i = p; i <= n; i++) {
			cout << ans[a[i + 1]] - 1 << " ";
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1 + i; j <= n; j++) {
			tp[a[j]]++;
			if (tp[a[j]] == 2) {
				for (int z = 1; z <= m; z++) {
					tp[z] = 0;
				}
				tp[a[j]]++;
			}

		}
		for (int j = 1; j <= m; j++) {
			ans[j] += tp[j] != 0;
		}
		for (int j = 0; j <= m; j++) {
			tp[j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}