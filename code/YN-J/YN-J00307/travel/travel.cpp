#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c, r, h, x;
	cin >> c >> r >> h >> x;
	if (c[0] == h[0] && c[1] == h[1]) {
		cout << "1";
	} else {
		cout << "0000";
		return 0;
	}
	if (r[0] == x[0] && r[1] == x[1]) {
		cout << "1";
	} else {
		cout << "000";
		return 0;
	}
	if (r[2] == 'A' || r[2] == 'B' || r[2] == 'C' && x[2] == 'A' || x[2] == 'B' || x[2] == 'C') {
		cout << "1";
	} else if (r[2] == 'D' || r[2] == 'F' && x[2] == 'D' || x[2] == 'F') {
		cout << "11";
	} else {
		cout << "00";
		return 0;
	}
	if (r[2] == 'A' && x[2] == 'B') {
		cout << "1";
	} else if (r[2] == 'B' && x[2] == 'A') {
		cout << "1";
	} else if (r[2] == 'B' && x[2] == 'C') {
		cout << "1";
	} else if (r[2] == 'C' && x[2] == 'B') {
		cout << "1";
	} else {
		cout << "0";
	}
	return 0;
}