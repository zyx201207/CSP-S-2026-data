#include <bits/stdc++.h>
using namespace std;
int n, m, a[100005], b, d;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {

		if (a[i] < a[i + 1]) {
			b = a[i];
			a[i] = a[i + 1];
			a[i + 1] = b;
		}
	}

	for (int i = 1; i <= n - 1; i++) {

		d += a[i];
	}

	cout << a[n - 1] << endl;
	return 0;
}
