#include <bits/stdc++.h>
using namespace std;
long long a[321423];
long long s[615342];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long q, w;
	cin >> q >> w;
	int z = 0;
	int x = 0;
	int c = 0;
	for (long long j = 1; j <= q; j++) {
		cin >> a[j];
		for (long long i = 1; i <= w; i++) {
			z = a[j] % 2;
			if (z > z + 1) {
				x = a[j];
			} else {
				x = a[j] + 1;
			}
			s[i] = x;
			for (long long im = 1; im <= j; im++) {
				if (s[i] >= s[i + 1] ) {
					c = s[i];
				} else {
					c = s[i + 1];
				}
			}
		}
	}
	cout << c - 1;
	return 0;
}