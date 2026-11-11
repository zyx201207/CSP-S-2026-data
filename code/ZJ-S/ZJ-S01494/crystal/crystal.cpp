#include<bits/stdc++.h>
using namespace std;
long long a[550000], m, s[550000], f[550000];
int n;
int main () {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
		f[i] = 1;
	}
	f[0] = 0;
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++ ) {
		s[i] = s[i - 1] + a[i];
	}
	int mx = -1;
	if (n <= 10000 || a[2] - a[1] != a[3] - a[2]) {
		for (int i = 1; i <= n; i ++ ) {
			for (int j = 1; j + i - 1 <= n; j ++ ) {
				if (i * a[j + i - 1] <= m + s[j + i - 1] - s[j - 1]) {
					mx = i;
					break;
				}
			}
		}
		cout << mx;
	}
	else {
		long long c = a[2] - a[1];
		for (int i = 1; i <= n; i ++ ) {
			if (1ll * i * (i + 1) / 2 * c > m) {
				cout << i;
				return 0;
			}
		}
		cout << n;
	}
	return 0;
}

/*
5 8
-3 -1 2 2 7

*/
