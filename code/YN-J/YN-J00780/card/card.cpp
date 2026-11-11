#include <bits/stdc++.h>
using namespace std;
int a[500010], b[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int x = a[i];
		for (int j = 1; j <= i; j++) {
			if (a[j] == x) {
				for (int k = j; k <= i; k++) {
					a[k] = 0;
				}
			} else {
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = a[i];
		for (int j = 1; j <= i; j++) {
			if (a[j] == x) {
				for (int k = j; k <= i; k++) {
					ans++;
					a[k] = 0;
				}
			} else {
				break;
			}
		}
		for (int j = 1; j <= m; j++) {
			if (j == a[i]) {
				cout << ans << " ";
			}
		}
	}
	return 0;
}