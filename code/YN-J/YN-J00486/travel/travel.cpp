#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char a, b;
	char a1, b1;
	cin >> a >> a1 >> b >> b1;

	if (a == b) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}

	if (a1 / 10 == b1 / 10 + 1) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}