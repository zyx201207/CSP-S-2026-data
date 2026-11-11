#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a[500000], b[500000] = {}, p = 0, x;
	cin >> n >> m;
	for (int i = 0; i <= n - 1; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		x = a[i];
		for (int j = 0; j <= p; j++) {
			if (x == b[j]) {
				for (int k = j; k <= p; k++) {
					b[k] = 0;
				}
			}
		}

	}
	return 0;
}