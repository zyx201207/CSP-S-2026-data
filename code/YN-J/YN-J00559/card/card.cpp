#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100010];
int b[100010];

int c[100010] = {0};

int main() {
	freopen("card.in", "r", strin);
	freopen("card.out", "w", strout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			b[j] = a[j];
			for (int k = 1; k <= j; k++) {
				if (b[k] == a[j]) {
					for (int l = 1; l <= k; l++) {
						b[l] = 0;
						j = l;
					}
				}
			}
			c[b[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (c[i] != 0)
			cout << c[i] << " ";
	}
	return 0;
}