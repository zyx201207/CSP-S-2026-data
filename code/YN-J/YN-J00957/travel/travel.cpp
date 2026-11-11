#include <bits/stdc++.h>
using namespace std;
int a1, b1, a2, b2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> b1 >> a2 >> b2;
	if (a1 == a2) {
		cout << "11";
	} else {
		cout << "0000";
		return 0;
	}
	if (b1 == b2 - 1 && b1 == b2 + 1) {
		cout << "11";
	} else {
		cout << "10";
	}

	return 0;
}
