#include <iostream>
using namespace std;

int n, m, a[500001], b[300001], c[400001], d[300001];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int w = 1;
		for (int k = 1; k <= m; k++) {
			b[k] = 0;
		}
		for (int j = i; j <= n; j++) {
			c[w] = a[j];
			w++;
			b[a[j]]++;
			if (b[a[j]] > 1) {
				for (int k = 1; k < w; k++) {
					c[k] = 0;
					b[k] = 0;
				}
				c[1] = a[j];
				b[a[j]]++;
				w = 2;
			}
		}
		for (int j = 1; j <= m; j++) {
			d[j] += b[j];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << d[i] << " ";
	}
	return 0;
}