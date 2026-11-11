#include <bits/stdc++.h>
using namespace std;
long long n, m, a[1000005], num, b[1000005], c[1000005], a1[1000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		a1[i] = a[i];
	}
	long long ant = 1;
	num = n - ant + 1;
	while (num != 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (a[j] != 0 && a[i + 1] == b[j]) {
					for (long long h = j; h < i + 1; h++) {
						a[h] = 0;
						b[h] = 0;
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (a[i] != 0) {
				c[a[i]]++;
			}
		}
		num--;
		for (int i = 1; i <= n; i++) {
			a[i] = a1[i + ant];
			b[i] = a1[i + ant];
		}
		ant++;
	}
	for (int i = 1; i <= m; i++) {
		cout << c[i] << " ";
	}
}