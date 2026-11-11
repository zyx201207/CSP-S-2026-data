#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, c;
	int b, d;
	cin >> a >> b >> c >> d;
	if (a == c) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (b == d + 1 || b == d - 1 || b + 1 == d || b - 1 == d) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (a == c) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (b == d + 1 || b == d - 1 || b + 1 == d || b - 1 == d) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}