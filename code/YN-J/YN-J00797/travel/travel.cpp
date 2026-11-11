#include <bits/stdc++.h>
using namespace std ;
int a, b, an, bn;
int am, bm;
bool ar = 1, br = 1;
string az, bz, ay, by;

int zw(string x) {
	int n = 0, a = 0;
	n = x[0] - '0';
	a += n;
	n = x[1] - '0';
	a = a * 10 + n;
	return a;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> ay >> az >> by >> bz;
	an = zw(az);
	bn = zw(bz);
	a = zw(ay);
	b = zw(by);
	am = az[2] - 'A';
	bm = bz[2] - 'A';
	if (am == 0 || am == 1 || am == 2 )
		ar = 0;
	if (bm == 0 || bm == 1 || bm == 2)
		br = 0;

	if (am == 3 || am == 5 )
		ar = 1;
	if (bm == 3 || bm == 5)
		br = 1;

	if (a != b) {
		cout << "0000";
		return 0;
	} else
		cout << 1;
	if (an != bn) {
		cout << "000";
		return 0;
	} else
		cout << 1;
	if (ar == br ) {
		cout << 1;
		if (am + bm == 8) {
			cout << 1;
		} else if (am + bm == 1 || am + bm == 3) {
			cout << 1;
			return 0;
		}
		cout << 0;
	} else {
		cout << "00";
	}
	return 0;
}