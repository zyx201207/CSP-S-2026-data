#include <bits/stdc++.h>
using namespace std;
int n, m, a[300005], x[300005], h = 0;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			x[j] = a[j];
			for (int k = 1; k <= j; k++) {
				if (a[j] == x[k]) {
					for (int w = 1; w <= j; w++) {
						x[w] = 0;
					}
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		h = 0;
		for (int j = 1; j <= n - i + 1; j++) {
			if (x[j] == 1) {
				h++;
			}
		}
		cout << h << " ";
	}
	return 0;
}