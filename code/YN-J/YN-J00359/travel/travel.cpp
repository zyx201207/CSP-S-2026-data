#include <bits/stdc++.h>
using namespace std;
string ina, inb, za, zb;
bool a = false, b = false;

int main() {
	cin >> ina >> za >> inb >> zb;
	if (ina[0] != inb[0] || ina[1] != inb[1]) {
		cout << "0000";
		return 0;
	} else {
		cout << '1';
	}
	if (za[0] == zb[0] && za[1] == zb[1]) {
		cout << '1';
		a = true;
	} else
		cout << '0';
	if (a) {
		if (((za[2] - 64 ) <= 3 && (zb[2] - 64) <= 3) || ((za[2] - 64) > 3 && (zb[2] - 64) > 3)) {
			cout << '1';
			b = true;
		} else
			cout << '0';
	} else
		cout << '0';
	if (b) {
		if (abs(za[2] - zb[2]) == 1)
			cout << 1;
		else
			cout << '0';
	} else
		cout << '0';
	return 0;
}