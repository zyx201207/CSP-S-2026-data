#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long int a[N], b[N], c[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	a[N] = {0};
	long long int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		c[i] = b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if ((b[j] == b[k] || b[j + 1] == b[k] || b[j + 2] == b[k]) && c[j] != -1 && c[k] != -1) {
					for (int ii = j; ii < k; ii++) {
						c[ii] = N;
					}
				}
			}
		}
		for (int j = i; j <= n; j++) {
			int k = 1;
			a[c[j]] += 1;
			c[j] = b[j];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << a[i] << ' ';
	}
	return 0;
}