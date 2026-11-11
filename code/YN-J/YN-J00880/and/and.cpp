#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m, a[2000005];
	cin >> n, m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] % a[i + j] == 0) {
				cout << a[i];
			} else {
				cout << "m";
			}
		}
	}
	return 0;
}