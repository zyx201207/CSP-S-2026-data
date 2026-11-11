#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, a[500090], f[500090];
int m;
int x = 2, k = 2, l = 1;

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int i = 1;
	while (i <= m) {
		if (l <= k) {
			f[i] = x;
		} else {
			x++, k++, l = 1;
			continue;
		}
		i++;
		l++;
	}
	for (int i = 1; i <= m; i++ ) {
		cout << f[i] << endl;
	}
	cout << f[m];
	return 0;
}
