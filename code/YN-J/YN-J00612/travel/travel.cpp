#include <bits/stdc++.h>
using namespace std;
string c1, c2, c3, c4, a1, a2, b1, b2, a3, b3;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	for (int i = 0; i < c2.size(); i++) {
		a1 = c2[0];
		a2 = c2[1];
		a3 = c2[2];
	}
	for (int i = 0; i < c4.size(); i++) {
		b1 = c4[0];
		b2 = c4[1];
		b3 = c4[2];
	}
	if (c1 == c3) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == c3 && a1 == b1 && a2 == b2) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == c3 && a1 == b1 && a2 == b2 && (((a3 <= "C" && a3 >= "A") && (b3 <= "C" && b3 >= "A")) || ((a3 <= "F"
	        && a3 >= "D") && (b3 <= "F" && b3 >= "d")))) {
		cout << "1";
	} else {
		cout << "0";
	}
	if (c1 == c3 && a1 == b1 && a2 == b2 && (((a3 <= "C" && a3 >= "A") && (b3 <= "C" && b3 >= "A")) || ((a3 <= "F"
	        && a3 >= "D") && (b3 <= "F" && b3 >= "d"))) && ((a3 == "A" && b3 == "B") || (a3 == "B" && b3 == "C") || (a3 == "D"
	                && b3 == "F") || (a3 == "B" && b3 == "A") || (a3 == "C" && b3 == "B") || (a3 == "F" && b3 == "D"))) {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}