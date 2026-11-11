#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 2e5 + 5;
int a[N];
char b[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	if (n == 1) {
		cout << 0;
	} else if (n == 2) {
		if (b[1] == b[2]) {
			cout << 0;
		} else {
			if (a[1] == a[2]) {
				cout << a[1];
			} else {
				cout << min(a[1], a[2]);
			}

		}
	}
	return 0;
}
