#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	int a, b;
	string c, d;

	if (n == 1) {
		cin >> a >> c;
		cout << 0;
	} else if (n == 2) {
		cin >> b >> d;
		cin >> a >> c;

		if (d == c) {
			cout << 0;
		} else if (a == b && d != c) {
			cout << a;
		} else if (a > b) {
			cout << b;
		} else if (a < b) {
			cout << a;
		}

	}

	return 0;
}
