#include <bits/stdc++.h>
using namespace std;
long long  m, n, a[500050];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (abs(a[1] - a[0]) == abs(a[2] - a[1])) {
		int gc = abs(a[1] - a[0]);
		int s = 1;
		for (int i = 1; m > 0 ; i++) {
			if (m >= i * gc) {
				m -= i * gc;
				s += 1;
			}

			else {

				break;
			}
		}
		cout << s;
	} else {
		cout << n / 2;
	}
	return 0;
}
