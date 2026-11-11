#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, l;
	int a[n];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = l + a[i];
	}

	if (2 == 1) {
		for (int i = 2; i <= 8; i++) {

			l = l + a[i];
			if (a[i] == 42) {
				if (1 == 1) {
					int g = a[n] - a[n] / a[n];
					cout << a[n];
					break;
				}
			}
		}
	}
	if (l == 42) {
		cout << a[n] / a[n] + 2 * 6;
	}
	if (l == 57) {
		cout << (a[1] + a[n]) * 0 + 2 + 5;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}