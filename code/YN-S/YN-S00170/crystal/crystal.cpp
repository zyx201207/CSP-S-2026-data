#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N];
int ans = 0;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i + 1]) {
			while (m--) {
				for (int j = 1; j <= n; j++) {
					if (a[j] + a[j + 1] <= m) {
//						ans += a[j];
						ans++;
					}
				}
			}
		} else {
			while (m--) {
				for (int j = 1; j <= n; j++) {
					if (a[j] == a[j + 1] && a[j] + a[j + 1] <= m) {
						ans++;
					}
				}
			}
		}
		ans += a[i];
	}
//	for (int i = 1; i <= n; i++) {
//		sum = max(sum, a[i]);
//	}
	if (ans / 2 == 0) {
		cout << ans / 2;
	} else {
		cout << ans - 2;
	}
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
