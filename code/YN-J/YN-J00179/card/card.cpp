#include <bits/stdc++.h>
using namespace std;
int n, m, b[100005], a[100005], c[100005];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			if (a[j] == b[i]) {
				sum++;
			}
		}
		if (sum == 0) {
			for (int j = 1; j <= n; j++) {
				if (b[j] == 0) {
					b[j] = a[i];
				}
			}
		} else {
			for (int j = 1; j <= n; j++) {
				if (b[j] == a[i]) {
					for (int k = j + 1; k <= n; k++) {
						b[k] == 0;
					}
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			c[b[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
	return 0;
}