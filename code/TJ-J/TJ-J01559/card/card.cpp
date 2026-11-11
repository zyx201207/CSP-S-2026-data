#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[300005], ans[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n ; j++) {
			if (b[a[j]] == 1) {
				for (int x = j - 1; x >= 1; x--) {

					if (a[x] != a[j]) {
						b[a[x]] = 0;

					} else {
						break;
					}
				}
			} else {
				b[a[j]] = 1;
			}
		}
		for (int j = 1; j <= m; j++) {
			if (b[j] == 1) {
				ans[j]++;
				b[j] = 0;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}