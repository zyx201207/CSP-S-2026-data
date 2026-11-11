#include <bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
char c[100000010];

int main() {

	int n, m = 0, x = 0, y = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		y += a[i];
	}
	if (y <= 90000000) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= a[i]; j++) {
				m++;
				c[m] = b[i];
			}
		}
		for (int i = 1; i <= m / 2; i++) {
			if (c[i] != c[m - i]) {
				x++;
			}
		}
	} else {

	}
	cout << x;
	return 0;
}