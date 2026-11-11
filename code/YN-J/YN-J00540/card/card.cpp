#include <bits/stdc++.h>
using namespace std;
long long n, m, a[505050], b[303030];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "r", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int c[303030] = {0};
		for (int j = i; j <= n; j++) {
			c[a[j]]++;
			for (int k = i; k < j; k++) {
				if (a[j] == a[k]) {
					for (int w = k; w < j; w++) {
						c[a[w]]--;
					}
				}
			}
		}

		for (int j = 1; j <= m; j++) {
			cout << c[j] << ' ';
			if (c[j]) {
				b[j]++;
			}
		}
		cout << endl;
	}
	for (int i = 1; i <= m; i++)
		cout << b[i] << ' ';

	return 0;
}