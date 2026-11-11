#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int cx1, cx2;
	string zw1, zw2;
	cin >> cx1 >> zw1 >> cx2 >> zw2;
	int n = zw1.length();
	if (cx1 == cx2) {
		cout << '1';
	} else {
		cout << '0';
	}
	for (int i = 1; i <= n; i++) {
		if (zw1[n] == zw2[n]) {
			cout << '1';
			break;
		} else {
			cout << '0';
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (zw1[n] == zw2[n]) {
			if (zw1[n] == 'C' && zw2[n] == 'D') {
				cout << '0';
				break;
			}
			if (zw1[n] == 'D' && zw2[n] == 'C') {
				cout << '0';
				break;
			}
			if (zw1[n] == zw2[n]) {
				cout << '1';
				break;
			}
		} else {
			cout << '0';
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (zw1[i] == zw2[i]) {
			char a = (zw1[n]);
			char b = (zw2[n]);
			if (a + 1 == b || a - 1 == b) {
				cout << '1';
			} else {
				cout << '0';
			}
			break;
		} else {
			cout << '0';
			break;
		}
	}
	return 0;
}