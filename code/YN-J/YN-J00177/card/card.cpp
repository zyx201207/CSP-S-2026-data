#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], ans[300005];
int w[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		memset(w, 0, sizeof(w));
		int x = 1;
		for (int j = i; j <= n; j++) {
			if (w[a[j]] == 0) {
				w[a[j]] = x;
			} else {
				for (int k = 1; k <= m; k++) {
					if (w[k] > w[a[j]]) {
						w[k] = 0;

					}
				}
				x = w[a[j]];
			}
			x++;
		}
		for (int j = 1; j <= m; j++) {
			if (w[j] != 0) {
				ans[j]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}