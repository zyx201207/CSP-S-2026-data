#include <bits/stdc++.h>
using namespace std;
string a, a1, b, b1;
char a2[1000];
char b2[1000];

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> a1 >> b >> b1;
	if (a == b) {
		cout << 1;
	} else {
		cout << 0000;
		return 0;
	}

	if (a1[0] == b1[0] && a1[1] == b1[1]) {
		cout << 1;
		if (a1[2] == 'A' || a1[2] == 'B' || a1[2] == 'C' ) {
			if (b1[2] == 'B' || b1[2] == 'C' || b1[2] == 'A') {
				cout << 1;
				if (abs(a1[2] - b1[2]) == 1) {
					cout << 1;
				} else
					cout << 0;
			} else {
				cout << 00;
			}
//02 01A 02 01B
		} else if (a1[2] == 'D' || a1[2] == 'F' ) {
			if (b1[2] == 'D' || b1[2] == 'F')	{
				cout << 1;
				if (b1[2] != a1[2]) {
					cout << 1;
				}
			} else
				cout << 00;


		}
	} else {
		cout << 000;
	}

	return 0;
}