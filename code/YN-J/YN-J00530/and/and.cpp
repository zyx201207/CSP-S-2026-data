#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], n, b, c[200005];

signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	int m, maxx = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	if (m == 1) {
		cout << maxx;
	} else {
		sort(a + 1, a + n + 1);
		int l = 0;
		for (int i = n; i >= 1; i--) {
			l++;
			c[l] = a[i];
		}
		int ssum = c[1];
		for (int i = 2; i <= m; i++) {
			ssum = ssum & c[i];
		}
		cout << ssum;
	}
	return 0;
}
