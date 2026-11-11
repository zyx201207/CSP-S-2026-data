#include <bits/stdc++.h>
using namespace std;
long long n, m, a[200005];
long long f[20005][2005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		f[i][1] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 2; k <= m; k++) {
			for (int j = 1; j <= i; j++) {
				f[i][k] = max(f[i][k], f[j][k - 1] & a[i]);
			}
		}
	}
	cout << f[n][m];
	return 0;
}