#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[n], b[n];

	for (int i = 0; i < n; i++) {

		cin >> a[i];
	}

	sort(a, a + n);

	for (int i = 0; i < m; i++) {

		b[i] = a[n - 1 - i];
	}

	if (m == 2) {
		cout << b[0] and b[1];
	}

	if (m == 3) {
		cout << b[0] and b[1] and b[2];
	}

	if (m == 4) {
		cout << b[0] and b[1] and b[2] and b[3];
	}

	return 0;
}
