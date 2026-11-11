#include <bits/stdc++.h>
using namespace std;
int n, a[10];
char b[10];
string s;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i] >> b[i];
	}

	if (n == 1) {
		cout << 0;
		return 0;
	}

	if (n == 2) {
		if (a[1] < a[2]) {
			cout << a[1];
			return 0;
		} else if (a[1] > a[2]) {
			cout << a[2];
			return 0;
		} else {
			if (b[1] == b[2]) {
				cout << 0;
				return 0;
			} else {
				cout << a[1];
				return 0;
			}
		}
	}
}
