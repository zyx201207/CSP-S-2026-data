#include <bits/stdc++.h>
using namespace std;
int a[1000005];
char b[1000005];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	if (n == 1) {
		cout << 0;
	}
	if (n == 2) {
		if (a[1] == b[2]) {
			cout << 0;
		} else {
			cout << min(a[1], a[2]);
		}
	}
	return 0;
}