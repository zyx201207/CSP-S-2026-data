#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf = -4e18;
int n, m;
int a[500005];
int b[300005];
int vis[300005];
int zh[500005];

signed main () {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	int t = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i != 1 && a[i] > a[i - 1]) {
			t = 0;
		}
	}
	if (t == 1) {
		for (int i = 1; i <= n; i++) {
			if (i == n || a[i] != a[i + 1]) {
				b[a[i]] = i;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << b[i] << " ";
		}
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int k = 0;
		for (int j = 1; j <= m; j++) {
			vis[j] = 0;
		}
		for (int j = i; j <= n; j++) {
			if (vis[a[j]] == 0 || vis[a[j]] > k) {
				zh[++k] = a[j];
				vis[a[j]] = k;
			} else {
				k = vis[a[j]] - 1;
				zh[++k] = a[j];
				vis[a[j]] = k;
			}
		}
		for (int i = 1; i <= k; i++) {
			b[zh[i]] ++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	return 0;
}