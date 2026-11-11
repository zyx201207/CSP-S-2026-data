#include <bits/stdc++.h>
using namespace std;
int a[500000], b[500000], c[500000];

int main() {

	int n, m, x = 0;
	cin >> n >> m;
	bool s = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < a[i - 1]) {
			s = 0;
		}
	}
	if (s == 1) {
		for (int i = 1; i <= n + 1; i++) {
			if (a[i] != a[i - 1] && a[i - 1] != 0) {
				cout << i - 1 << " ";
			}
		}
	} else {
		for (int i = n; i >= 1; i--) {
			b[i] = a[i];
			x = 1;
			for (int j = 1; j < i; j++) {
				if (b[i] == b[j]) {
					for (int k = x; k <= i - j; j++) {
						a[x] = b[k];
						b[k] = 0;
						x++;
					}
				}
			}
			for (int j = 1; j <= n; j++) {
				c[b[j]]++;
			}
		}
		for (int i = 1; i <= m; i++) {
			cout << c[i] << " ";
		}
	}
	return 0;
}