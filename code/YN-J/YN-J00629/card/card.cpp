#include <bits/stdc++.h>
using namespace std;

long long a[5000005], b[3000005] = {}, c[5000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int d = 1;
	while (n--) {
		for (int i = d; i <= n + d; i++) {
			if (c[a[i]] == 0) {
				c[a[i]]++;
			} else {
				for (int j = 1; j <= m; j++) {
					c[j] = 0;
				}
				c[a[i]]++;
			}
		}
		d++;
		for (int i = 1; i <= m; i++) {
			b[i] = b[i] + c[i];
			c[i] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	return 0;
}