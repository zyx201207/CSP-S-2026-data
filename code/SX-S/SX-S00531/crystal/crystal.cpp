#include <bits/stdc++.h>
using namespace std;
int z, s, x, n, m;
int  a[10000000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	x = a[2] - a[1];
	if (x == 0) {
		cout << n;
	} else if (m < x ) {
		cout << 1 ;
	} else
		for (int i = 2; i <= n; i++) {
			z = (a[1] * i + a[i] * i) / 2;
			s = i * a[i] - z;
			if (s == m) {
				cout << i;
				return 0;
			} else if (s > m) {
				cout << i - 1 ;
				return 0;
			}
		}

}
