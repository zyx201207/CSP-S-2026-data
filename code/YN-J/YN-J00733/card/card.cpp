#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[300005];
int c[500005];
int d[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, cnt = 0, h = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		b[a[i]] = i;
		c[a[i]]++;
		d[a[i]]++;
	}
	for (int i = n; i >= 1; i--) {
		if (c[a[i]] != 0) {
			b[a[i]] = b[a[i]] - h;
			c[a[i]] = 0;
		}
		if (d[a[i]] > 1) {
			h++;
		}
	}
	for (int j = 1; j <= m; j++) {
		cout << b[j] << " ";
	}
	return 0;
}