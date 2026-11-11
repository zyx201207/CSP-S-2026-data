#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a[200005] = {};
	char b[200005] = {};
	cin >> n;
	for (int i = 1; i <= 2; i++) {
		cin >> a[i] >> b[i];
		if (b[i] == b[i - 1]) {
			cout << 0;
			return 0;
		}
		if (a[i] >= a[i - 1]) {
			cout << a[i] - a[i - 1];
			return 0;
		}

		if (a[i] <= a[i - 1]) {
			cout << a[i - 1] - a[i];
			return 0;
		}

	}
	if (n == 1) {
		cout << 1;
		return 0;
	}
	return 0;
}