#include <bits/stdc++.h>
using namespace std;
long long a[4000000];
long long zm[4000000];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	long long sum = 0;
	int qz = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[0] = -2;
	for (int t = 1; t <= m; t++) {
		for (int i = 1; i <= n; i++) {
			sum = 0;
			for (int j = i - 1; j <= n; j++) {
				for (int b = 1; b <= n - 1; b++) {
					if (zm[b] == a[j]) {
						qz = 0;
					}
					if (qz == 0) {
						zm[b + 1] = -1;
					}
				}
			}
			long long  c = 1;
			while (a[c] == -1) {
				if (a[c] == i) {
					sum++;
					break;
				}
				c++;
			}

		}
		cout << sum << " ";
	}


	return 0;
}