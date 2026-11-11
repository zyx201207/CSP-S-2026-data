#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000000];
int b[1000000];
int t[1000000];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			b[j] = 0;
		}
		int xb;
		int c = 0;
		for (int j = i; j <= n; j++) {
			xb = c + 1;
			for (int p = 1; p <= n; p++) {
				if (b[p] == a[j]) {
					xb = p;
				}
			}
			b[xb] = a[j];
			c = xb;
		}
		for (int j = 1; j <= c; j++) {
			t[b[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << t[i] << " ";
	}
	return 0;
}
