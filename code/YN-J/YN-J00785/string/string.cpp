#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 2;
int n, a[N];
string c[N], s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> c[i];
	}

	if (n = 1) {
		cout << 0;
	} else(n = 2) {
		if (c[1] == c[2]) {
			cout << 0;
		} else if (a[1] <= a[2]) {
			cout << a[1];
		} else {
			cout << a[2];
		}
	}

	return 0;
}