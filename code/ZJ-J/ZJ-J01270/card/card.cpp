#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, a[500005], s[500005], f[500005];
signed main() {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int c = 1;
		for (int j = i; j <= n; j++) {
			for (int k = c - 1; k >= 1; k--) {
				if (f[k] == a[j]) {
					for (int l = k+1; l <= c; l++) {
						f[l] = 0;
					}
					c = k;
					break;
				}
			}
			f[c] = a[j];
			c++;
		}
		for (int j = 1; j <= c; j++) {
			s[f[j]]++;
		}
	}
	s[a[n]] = n;
	for (int i = 1; i <= m; i++) {
		cout << s[i] << " ";
	}
	return 0;
}
