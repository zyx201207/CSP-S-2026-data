#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char ch1, ch2;
	int a, b, a1, a2, b1, b2;
	cin >> a >> a1 >> ch1 >> b >> b1 >> ch2;
	if (a == b) {
		a2 = (ch1 - '0') % 100;
		b2 = (ch2 - '0') % 100;
		if (a1 == b1) {
			if (a2 + 1 == b2 && b2 != 20) {
				cout << "1111";
			} else if (a2 == b2 + 1 && a2 != 20) {
				cout << "1111";
			} else if (a2 == 20 && b2 == 19) {
				cout << "1100";
			} else if (a2 == 19 && b2 == 20) {
				cout << "1100";
			} else {
				cout << "1110";
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}