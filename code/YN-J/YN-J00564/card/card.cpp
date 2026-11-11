#include <bits/stdc++.h>
using namespace std;

int main() {
	freeopen("card","r",stdin);
	freeopen("card","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[n + 5], b[n + 5];
	int mx[m + 5];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++) {
			b[i] = 0;
		}
		for (int j = i; j <= n; j++) {
			b[j] = a[j];
			for (int k = 1; k <= j; k++) {
				if (b[k] == a[j]) {
					for (int q = k; q < j; q++) {
						b[q] = 0;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			mx[b[i]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << mx[i] << " ";
	}
	return 0;
}
