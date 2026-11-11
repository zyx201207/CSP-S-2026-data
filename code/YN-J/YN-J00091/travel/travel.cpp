#include <bits/stdc++.h>
using namespace std;
char a1, a2, a3, a4, a5, b1, b2, b3, b4, b5;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> b1 >> b2 >> b3 >> b4 >> b5;

	if (a1 == b1 && a2 == b2) {
	} else {
		cout << "0000\n";
		return 0;
	}

	if (a3 == b3 && a4 == b4) {
	} else {
		cout << "1000\n";
		return 0;
	}


	if (((a5 == 'A' || a5 == 'B' || a5 == 'C') && (b5 == 'A' || b5 == 'B' || b5 == 'C')) || ((a5 == 'D'
	        || a5 == 'F') && (b5 == 'D' || b5 == 'F'))) {
	} else {
		cout << "1100\n";
		return 0;
	}


	if ((a5 == 'A' && b5 == 'B') || (a5 == 'B' && a5 == 'A') ||
	        (a5 == 'B' && b5 == 'C') || (a5 == 'C' && b5 == 'B') || (a5 == 'D' && b5 == 'F')
	        || (a5 == 'F' && b5 == 'D')) {
		cout << "1111\n";
		return 0;
	} else {
		cout << "1110\n";
		return 0;
	}


	return 0;
}
//É¾×¢ÊÍ
//É¾×¢ÊÍ
//É¾×¢ÊÍ
//É¾×¢ÊÍ