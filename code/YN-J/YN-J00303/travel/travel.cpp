#include <bits/stdc++.h>
using namespace std;

string a1, a2, a3, a4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> a2 >> a3 >> a4;

	if (a1 == a3) {
		cout << 1;
	} else {
		for (int i = 0; i < 4; i++) {
			cout << 0;
		}
		return 0;
	}
	if (a2[0] == a4[0] && a2[1] == a4[1]) {
		cout << 1;
	} else {
		for (int i = 0; i < 3; i++) {
			cout << 0;
		}
		return 0;
	}
	if ((a2[2] == 'A' && a4[2] == 'B')
	        || (a2[2] == 'B' && (a4[2] == 'A' || a4[2] == 'C'))
	        || (a2[2] == 'C' && a4[2] == 'B')
	        || (a2[2] == 'D' && a4[2] == 'F')
	        || (a2[2] == 'F' && a4[2] == 'D')
	        ||	(a4[2] == 'A' && a2[2] == 'B')
	        || (a4[2] == 'B' && (a2[2] == 'A' || a2[2] == 'C'))
	        || (a4[2] == 'C' && a2[2] == 'B')
	        || (a4[2] == 'D' && a2[2] == 'F')
	        || (a4[2] == 'F' && a2[2] == 'D')) {
		cout << "11";
		return 0;
	} else if (((a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C') && (a4[2] == 'A' || a4[2] == 'B' || a4[2] == 'C'))
	           || (a2[2] == 'D' && a4[2] == 'F')
	           || ((a4[2] == 'A' || a4[2] == 'B' || a4[2] == 'C') && (a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C')) || (a4[2] == 'D'
	                   && a2[2] == 'F')) {
		cout << "10";
	} else {
		cout << "00";
	}
	return 0;
}