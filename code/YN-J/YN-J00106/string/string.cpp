#include <bits/stdc++.h>
using namespace std;
int a[148];
char b[148];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int cnt = 0;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> b[i];
	}

	for (int i = 1; i <= n; i++) {

		if (i >= 2 && b[i - 1] == b[i]) {
			cnt++;
		}

		if (cnt == n - 1) {
			cout << 0;
			return 0;
		}
	}

	return 0;
}