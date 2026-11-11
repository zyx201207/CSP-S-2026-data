#include <bits/stdc++.h>
using namespace std;
int a[500005], b[300005], c[500005], d[300005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	for (int x = 1; x <= n; x++) {
		for (int i = x; i <= n; i++) {


			for (int j = 1; j <= m; j++) {
				if (b[x] == j) {
					c[j]++;
				}
				if (c[j] == 2) {
					for (int v = 1; v < x; v++) {
						b[v] = 0;
						if (b[i] == m) {
							d[j]++;

						}
					}
					c[j] = 0;

				}
			}
			for (int y = 1; y <= n; y++) {

				b[y] = a[y];
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << d[i] << " ";
	}
	return 0;
}