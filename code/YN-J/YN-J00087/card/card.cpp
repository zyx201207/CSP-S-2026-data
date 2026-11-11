#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int a[50005], b, t, c[50005], ans = 0;
	string m;
	cin >> b >> t;

	for (int i = 1; i <= b; i++) {

		cin >> a[i];

		for (int i = 1; i <= b; i++) {

			for (int k = 1; k <= i; k++) {

				if (a[i] == m[k]) {
					ans = 1;
				}
			}

			if (ans == 0) {
				c[a[i]]++;
				m += a[i];
			} else {
				ans = 0;
			}
		}

		for (int i = 1; i <= t; i++) {

			cout << c[i] << " ";
		}
	}

	return 0;
}