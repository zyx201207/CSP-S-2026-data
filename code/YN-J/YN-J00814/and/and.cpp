#include <bits/stdc++.h>
using namespace std;
int a[1000005];
char b[1000005];

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	if (n == 2) {
		if (a[1] == b[2]) {
			cout << 0;
			return 0;
		} else {
			cout << 1;
		}
	}

	return 0;
}