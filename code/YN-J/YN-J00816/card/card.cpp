#include <bits/stdc++.h>
using namespace std;

int a[500005];
int d[500005];
int g[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int b = n, c = 1, e = 0, f = 0, t;
	while (b--) {
		for (int i = c; i <= n; i++) {

			for (int j = 1; j <= e; j++) {
				if (d[j] == a[i]) {
					t = j;
					f = 1;
					break;
				}
			}
			if (f == 1) {
				for (int j = t; j <= e; j++) {
					d[j] = 0;
				}
				e = 0;
				f = 0;
			}
			e++;
			d[e] = a[i];
		}
		for (int i = 1; i <= e; i++) {
			g[d[i]]++;
		}
		for (int i = 1; i <= e; i++) {
			d[i] = 0;
		}
		e = 0;
		c++;
	}
	for (int i = 1; i <= m; i++) {
		cout << g[i] << " ";
	}
	return 0;
}