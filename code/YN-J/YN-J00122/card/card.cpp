#include <bits/stdc++.h>
using namespace std;
long long  a[500005], b[500005];
long long c[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = j - 1; k >= i; k--) {
				if (b[j] == b[k]) {
					for (int o = k; o <= j; o++) {
						b[o] = -1;
					}
					break;
				}
			}
		}
		for (int l = i; l <= n; l++) {
			c[b[l]]++;
		}
		for (int p = 1; p <= n; p++) {

			b[i] = a[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}

}